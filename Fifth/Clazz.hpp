#ifndef Clazz_hpp
#define Clazz_hpp

#include <stdio.h>
#include "Word.hpp"
#include "Map.hpp"

namespace us_cownet_fifth_OO {

    using namespace us_cownet_fifth_interp;
    using us_cownet_utils::Map;
    
    class Clazz : public Word {
    public:
        Word* findMethod(int key) {
            return methodMap.get(key);
        }
    private:
        Map<int, Word*, 20> methodMap;
    };

}

#endif /* Clazz_hpp */
