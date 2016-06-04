#ifndef ExitCompositeWord_hpp
#define ExitCompositeWord_hpp

#include "Word.hpp"

namespace us_cownet_fifth_interp {
    
    class ExecutionThread;

    class ExitCompositeWord : public Word {
        // when executed, ends the current colon definition
    public:
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "Return"; };
    };
    
}

#endif /* ExitCompositeWord_hpp */
