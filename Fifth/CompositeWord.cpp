#include "CompositeWord.hpp"

#include "ExecutionThread.hpp"

namespace us_cownet_fifth_interp {
    
    CompositeWord::CompositeWordInvocation::CompositeWordInvocation(Word** wordsIn)
    : Word(), words(wordsIn)
    {
    }
    
    void CompositeWord::CompositeWordInvocation::execute(ExecutionThread& thread) {
        //words[thread.peekControlStack().i++]->execute(thread);
        // this just calls execute() on the word, but it
        // allows the thread to do book keeping for debug
        // purposes.
        thread.execute(words[thread.peekControlStack().i++]);
    }
    
    
    CompositeWord::CompositeWord(Word** wordsIn)
    : Word(), invocation(wordsIn)
    {
    }
    
    void CompositeWord::execute(ExecutionThread& thread) {
        // remove the stub invocation that called this method
        // and replace it with one that marches through
        // the words.
        thread.pushControlStack(&invocation, 0);
    }
}