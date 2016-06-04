#ifndef PStringConstant_hpp
#define PStringConstant_hpp

#include <stdio.h>

#include "PString.hpp"

namespace us_cownet_fifth_primitives_string {
    
    class PStringConstant : public PString {
    public:
        PStringConstant(std::string s) : PString(s) {}
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return std::string("PStringConstant: \"") + value + "\""; };
    };
}

#endif /* PStringConstant_hpp */
