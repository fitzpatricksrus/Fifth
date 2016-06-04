#ifndef Word_h
#define Word_h

#include <string>

namespace us_cownet_fifth_interp {
    
    class ExecutionThread;
    
    class Word {
    public:
        Word() {};
        virtual ~Word();
        virtual void execute(ExecutionThread& thread) = 0;
        virtual std::string debugName();
    };
    
}

#endif /* Word_h */
