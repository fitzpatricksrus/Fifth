#ifndef PBoolean_hpp
#define PBoolean_hpp

#include <stdio.h>
#include "PVariable.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PBoolean: public PVariable {
    public:
        PBoolean(bool isTrueIn) : isTrue(isTrueIn) {}
        virtual std::string debugName() { return "PBoolean"; };

        bool isTrue;
    };
    
}


#endif /* PBoolean_hpp */
