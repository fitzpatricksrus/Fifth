#include "PStringConstant.hpp"

#include "ExecutionThread.hpp"

namespace us_cownet_fifth_primitives_string {
    
    using us_cownet_fifth_interp::ExecutionThread;
    
    void PStringConstant::execute(ExecutionThread& thread) {
        thread.pushData(this);
    }
    
}
