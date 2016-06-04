#ifndef PConstant_hpp
#define PConstant_hpp

#include <stdio.h>

#include "Word.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    // this is a marker interface for debugging
    class PConstant : public Word {
    public:
        PConstant() {}

        virtual std::string debugName() { return "PConstant"; };
};
}

#endif /* PConstant_hpp */
