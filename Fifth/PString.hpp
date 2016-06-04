#ifndef PString_hpp
#define PString_hpp

#include <stdio.h>
#include "Word.hpp"

namespace us_cownet_fifth_primitives_string {
    
    using us_cownet_fifth_interp::Word;
    using us_cownet_fifth_interp::ExecutionThread;
    
    class PString : public Word {
    public:
        PString() {}
        PString(std::string s) : value(s) {}
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PString"; };
        
        std::string value;
    };
}

#endif /* PString_hpp */
