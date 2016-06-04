#include "PIf.hpp"
#include "PBoolean.hpp"
#include "ExecutionThread.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    
    void PIf::execute(ExecutionThread& thread) {
        PBoolean* b = (PBoolean*)thread.popData();
        if (b != nullptr) {
        if (b->isTrue) {
            thread.peekControlStack().i = offset;
        }
        } else {
            thread.error("PIf condition not a PBoolean");
        }
    }
}