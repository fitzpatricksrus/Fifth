#include "PNoOp.hpp"

#include "ExecutionThread.hpp"
#include "PBooleanConstant.hpp"

namespace us_cownet_fifth_primitives {
    using us_cownet_fifth_interp::ExecutionThread;
    
    void PNoOp::execute(ExecutionThread& thread) {
    }
    
    static PNoOp instance;
    PNoOp& PNoOp::INSTANCE = instance;
}