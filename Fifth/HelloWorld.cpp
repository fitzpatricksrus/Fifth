#include "HelloWorld.hpp"
#include <iostream>

namespace us_cownet_fifth_primities {

HelloWorld::HelloWorld()
: message("HelloWorld\n")
{
}

HelloWorld::HelloWorld(std::string msg)
: message(msg)
{
}

void HelloWorld::execute(ExecutionThread& thread) {
    std::cout << message;
}

}
