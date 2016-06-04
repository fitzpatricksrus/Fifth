#ifndef PDup_hpp
#define PDup_hpp

#include "Word.hpp"

namespace us_cownet_fifth_primitives {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class PDup : public Word {
    public:
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "PDup"; };

        static PDup& INSTANCE;
    };
}

#endif /* PInteger_hpp */
