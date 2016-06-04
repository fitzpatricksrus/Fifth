//
//  PStringCompare.cpp
//  Fifth
//
//  Created by Dad on 1/24/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#include "PStringCompare.hpp"

#include <iostream>
#include "ExecutionThread.hpp"
#include "PString.hpp"
#include "PIntegerConstant.hpp"

namespace us_cownet_fifth_primitives_string {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    using us_cownet_fifth_primitives::PIntegerConstant;
    
    void PStringCompare::execute(ExecutionThread& thread) {
        PString* thiz = dynamic_cast<PString*>(thread.popData());
        if (thiz != nullptr) {
            PString* other = dynamic_cast<PString*>(thread.popData());
            if (other != nullptr) {
                int result = thiz->value.compare(other->value);
                if (result < 0) {
                    thread.pushData(&PIntegerConstant::NEG_ONE);
                } else if (result == 0) {
                    thread.pushData(&PIntegerConstant::ZERO);
                } else {
                    thread.pushData(&PIntegerConstant::ONE);
                }
            } else {
                thread.error("Tried doing string comparison where thiz was not a string");
            }
        } else {
            thread.error("Tried doing string comparison where thiz was not a string");
        }
    }
    
    static PStringCompare psc;
    PStringCompare& PStringCompare::INSTANCE = psc;
}

