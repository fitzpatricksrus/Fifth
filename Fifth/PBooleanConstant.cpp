//
//  PBooleanConstant.cpp
//  Fifth
//
//  Created by Dad on 1/21/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#include "PBooleanConstant.hpp"
#include "ExecutionThread.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    
    void PBooleanConstant::execute(ExecutionThread& thread) {
        thread.pushData(isTrue);
    }
    
    static PBooleanConstant TRUE_VALUE_CONSTANT(true);
    PBooleanConstant& PBooleanConstant::TRUE_VALUE = TRUE_VALUE_CONSTANT;
    static PBooleanConstant FALSE_VALUE_CONSTANT(false);
    PBooleanConstant& PBooleanConstant::FALSE_VALUE = FALSE_VALUE_CONSTANT;
}