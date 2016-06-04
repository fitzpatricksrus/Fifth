#ifndef PReadString_hpp
#define PReadString_hpp

#include <stdio.h>
#include "PString.hpp"

namespace us_cownet_fifth_primitives_string {
    
    using us_cownet_fifth_interp::ExecutionThread;
    
    class PReadString : public PString {
    public:
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PReadString"; };
    };
}

#endif /* PInputString_hpp */
