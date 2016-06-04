#include "PDup.hpp"

#include "ExecutionThread.hpp"

namespace us_cownet_fifth_primitives {
    using us_cownet_fifth_interp::ExecutionThread;
    
    void PDup::execute(ExecutionThread& thread) {
        thread.pushData(thread.peekData());
    }
    
    static PDup dup;
    PDup& PDup::INSTANCE = dup;
}