#include "PString.hpp"

#include "ExecutionThread.hpp"

namespace us_cownet_fifth_primitives_string {
    
    void PString::execute(ExecutionThread& thread) {
        thread.pushData(this);
    }

}