#ifndef PNot_hpp
#define PNot_hpp

#include "Word.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PNot : public Word {
    public:
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PNot"; };
        
        static PNot& INSTANCE;
    };
}

#endif /* PInteger_hpp */
