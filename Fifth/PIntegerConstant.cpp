//
//  PIntegerConstant.cpp
//  Fifth
//
//  Created by Dad on 1/21/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#include "PIntegerConstant.hpp"

#include "ExecutionThread.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    
    void PIntegerConstant::execute(ExecutionThread& thread) {
        thread.pushData(value);
    }
    
    static PIntegerConstant neg_one(-1);
    static PIntegerConstant zero(0);
    static PIntegerConstant one(1);
    
    PIntegerConstant& PIntegerConstant::NEG_ONE = neg_one;
    PIntegerConstant& PIntegerConstant::ZERO = zero;
    PIntegerConstant& PIntegerConstant::ONE = one;
}