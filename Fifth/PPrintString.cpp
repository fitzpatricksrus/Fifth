#include "PPrintString.hpp"

#include <iostream>

#include "ExecutionThread.hpp"
#include "PString.hpp"

namespace us_cownet_fifth_primitives_string {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    void PPrintString::execute(ExecutionThread& thread) {
        PString* s = dynamic_cast<PString*>(thread.popData());
        if (s != nullptr) {
            std::cout << s->value << "\n";
        } else {
            thread.error("tring to PPrintString a non-PString");
        }
    }
}

