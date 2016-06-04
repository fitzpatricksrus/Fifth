#include "PGoto.hpp"

#include "ExecutionThread.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    void PGoto::execute(ExecutionThread& thread) {
        thread.peekControlStack().i = offset;
    }
}

