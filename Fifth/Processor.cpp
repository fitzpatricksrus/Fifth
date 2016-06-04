#include "Processor.hpp"

namespace us_cownet_fifth_interp {
    
    Processor::Processor()
    : threads()
    {
    }
    
    void Processor::addThread(Word* definition, bool debugOn) {
        // we execute the word immediately instead of putting it
        // on the stack to better mimic the behavior of
        // nested contexts.  For example, a primitive word
        // is never put on the stack, so pushing it on the stack
        // and letting the thread pick it up latter makes the
        // outer context different.  This way, only composits
        // push themselves on the control stack, just like in
        // normal execution.
        ExecutionThread t;
        t.setDebug(debugOn);
        t.execute(definition);
        if (!t.isDone()) {
            threads.add(t);
        }
    }
    
    void Processor::process() {
        int currentThreadIndex = 0;
        while (threads.size() > 0) {
			threads[currentThreadIndex].run();
            if (threads[currentThreadIndex].isDone()) {
				threads.removeNdx(currentThreadIndex);
            } else {
				currentThreadIndex = (currentThreadIndex + 1) % threads.size();
            }
        }
    }
    
    ExecutionThread& Processor::currentThread() {
        return threads[currentThreadIndex];
    }
    
    
}