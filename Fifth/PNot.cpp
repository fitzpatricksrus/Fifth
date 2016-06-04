#include "PNot.hpp"

#include "ExecutionThread.hpp"
#include "PBooleanConstant.hpp"

namespace us_cownet_fifth_primitives {
    using us_cownet_fifth_interp::ExecutionThread;
    
    void PNot::execute(ExecutionThread& thread) {
        Word* w = thread.peekData().w;
        PBooleanConstant* b = dynamic_cast<PBooleanConstant*>(w);
        if (b != nullptr) {
            thread.popData();
            if (b->isTrue) {
                thread.pushData(&PBooleanConstant::FALSE_VALUE);
            } else {
                thread.pushData(&PBooleanConstant::TRUE_VALUE);
            }
        } else {
            thread.error("NOT applied to non PBooleanConstant value");
        }
    }
    
    static PNot instance;
    PNot& PNot::INSTANCE = instance;
}