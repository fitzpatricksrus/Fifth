//
//  PIntegerConstant.hpp
//  Fifth
//
//  Created by Dad on 1/21/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#ifndef PIntegerConstant_hpp
#define PIntegerConstant_hpp

#include <stdio.h>
#include "PConstant.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PIntegerConstant : public PConstant {
    public:
        PIntegerConstant(int s) : value(s) {}
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return std::to_string(value); };
        
        const int value;
        
        static PIntegerConstant& NEG_ONE;
        static PIntegerConstant& ZERO;
        static PIntegerConstant& ONE;
    };
}

#endif /* PIntegerConstant_hpp */
