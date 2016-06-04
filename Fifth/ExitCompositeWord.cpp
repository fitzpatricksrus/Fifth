#include "ExitCompositeWord.hpp"

#include "ExecutionThread.hpp"

namespace us_cownet_fifth_interp {
    
    void ExitCompositeWord::execute(ExecutionThread& thread) {
        // pop the current stack frame off the stack, returning to the previous
        thread.popControlStack();
    }
    
}