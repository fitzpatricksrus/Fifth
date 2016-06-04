#include "PReadString.hpp"
#include <iostream>

#include "ExecutionThread.hpp"

namespace us_cownet_fifth_primitives_string {
    
    using us_cownet_fifth_interp::ExecutionThread;
    
    void PReadString::execute(ExecutionThread& thread) {
        std::getline(std::cin, value);
        PString::execute(thread);
    }
}

