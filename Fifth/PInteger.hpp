#ifndef PInteger_hpp
#define PInteger_hpp

#include <stdio.h>
#include "PVariable.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PInteger : public PVariable {
    public:
        PInteger(int s) : value(s) {}

        virtual std::string debugName() { return std::to_string(value); };

        int value;
    };
}

#endif /* PInteger_hpp */
