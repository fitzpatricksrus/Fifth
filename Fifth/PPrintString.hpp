#ifndef PPrintString_hpp
#define PPrintString_hpp

#include "Word.hpp"

namespace us_cownet_fifth_primitives_string {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PPrintString : public Word {
    public:
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PPrintString"; };
    };
}

#endif /* PPrintString_hpp */
