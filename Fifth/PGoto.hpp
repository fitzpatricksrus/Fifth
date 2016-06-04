#ifndef PGoto_hpp
#define PGoto_hpp

#include <stdio.h>

#include "Word.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PGoto : public Word {
    public:
        PGoto(int offsetIn) : offset(offsetIn) {}
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PGoto"; };
        
    private:
        int offset;
    };
}


#endif /* PGoto_hpp */
