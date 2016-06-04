//
//  PBooleanConstant.hpp
//  Fifth
//
//  Created by Dad on 1/21/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#ifndef PBooleanConstant_hpp
#define PBooleanConstant_hpp

#include <stdio.h>
#include "PConstant.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PBooleanConstant: public PConstant {
    public:
        static PBooleanConstant& TRUE_VALUE;
        static PBooleanConstant& FALSE_VALUE;

        PBooleanConstant(bool isTrueIn) : isTrue(isTrueIn) {}

        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return isTrue ? "True" : "False"; };

        bool isTrue;
    };
    
}

#endif /* PBooleanConstant_hpp */
