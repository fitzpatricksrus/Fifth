#include <stdio.h>

#include "Word.hpp"

namespace us_cownet_fifth_interp {
        
    Word::~Word() {
    }
    std::string Word::debugName() {
        return typeid(*this).name();
    }

}