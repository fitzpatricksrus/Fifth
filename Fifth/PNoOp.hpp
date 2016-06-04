#ifndef PNoOp_hpp
#define PNoOp_hpp

#include "Word.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PNoOp : public Word {
    public:
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PNoOp"; };
        
        static PNoOp& INSTANCE;
    };
}

#endif /* PInteger_hpp */
