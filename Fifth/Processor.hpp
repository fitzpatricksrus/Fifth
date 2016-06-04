#ifndef Processor_hpp
#define Processor_hpp

#include <stdio.h>
#include "List.hpp"
#include "ExecutionThread.hpp"

namespace us_cownet_fifth_interp {
    
    using us_cownet_utils::List;
    
    class Processor {
    public:
        Processor();
        
        void addThread(Word* definition, bool debugOn = false);
        void process();
        ExecutionThread& currentThread();
        
    private:
        int currentThreadIndex;
        List<ExecutionThread, 10> threads;
    };
    
}

#endif /* Processor_hpp */
