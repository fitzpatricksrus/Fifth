#ifndef PIf_hpp
#define PIf_hpp

#include <stdio.h>
#include "Word.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PIf : public Word {
    public:
        PIf(int offsetIn) : offset(offsetIn) {}
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PIf"; };
        
    private:
        int offset;
    };
}


#endif /* PIf_hpp */
