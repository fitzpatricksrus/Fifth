#ifndef Object_hpp
#define Object_hpp

#include "Word.hpp"
#include "Clazz.hpp"

namespace us_cownet_fifth_OO {
    
    using namespace us_cownet_fifth_interp;
    using us_cownet_utils::Map;
    
    class Object : public Word {
    public:
        Clazz* getClazz() { return clazz; }
    private:
        Clazz* clazz;
    };
    
}
#endif /* Object_hpp */
