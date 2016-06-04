//
//  HelloWorld.hpp
//  Fifth
//
//  Created by Dad on 1/18/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#ifndef HelloWorld_hpp
#define HelloWorld_hpp

#include <stdio.h>
#include <string>
#include "Word.hpp"

namespace us_cownet_fifth_primities {

using us_cownet_fifth_interp::Word;
using us_cownet_fifth_interp::ExecutionThread;

class HelloWorld : public Word {
public:
    HelloWorld();
    HelloWorld(std::string msg);
    virtual void execute(ExecutionThread& thread);
    
private:
    std::string message;
};

}

#endif /* HelloWorld_hpp */
