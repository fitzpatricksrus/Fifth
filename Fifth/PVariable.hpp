//
//  PVariable.hpp
//  Fifth
//
//  Created by Dad on 1/21/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#ifndef PVariable_hpp
#define PVariable_hpp

#include <stdio.h>
#include "Word.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PVariable : public Word {
    public:
        PVariable() {}
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PVariable"; };
    };
}

#endif /* PVariable_hpp */
