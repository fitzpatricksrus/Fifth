//
//  PVariable.cpp
//  Fifth
//
//  Created by Dad on 1/21/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#include "PVariable.hpp"

#include "ExecutionThread.hpp"

namespace us_cownet_fifth_primitives {
    
    void PVariable::execute(ExecutionThread& thread) {
        thread.pushData(this);
    }
    
}