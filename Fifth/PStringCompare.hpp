//
//  PStringCompare.hpp
//  Fifth
//
//  Created by Dad on 1/24/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#ifndef PStringCompare_hpp
#define PStringCompare_hpp

#include "Word.hpp"

namespace us_cownet_fifth_primitives_string {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PStringCompare : public Word {
    public:
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PStringCompare"; };
        
        static PStringCompare& INSTANCE;
    };
}

#endif /* PStringCompare_hpp */
