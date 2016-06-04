#ifndef CompositeWord_hpp
#define CompositeWord_hpp

#include "Word.hpp"

namespace us_cownet_fifth_interp {
    
    class ExecutionThread;
    class CompositeWordInvocation;
    
    class CompositeWord : public Word {
    public:
        CompositeWord(Word** words);
        virtual void execute(ExecutionThread& thread);
        virtual std::string debugName() { return "CompositeWord"; };
        
    private:
        class CompositeWordInvocation : public Word {
        public:
            CompositeWordInvocation(Word** wordsIn);
            void execute(ExecutionThread& thread);
            virtual std::string debugName() { return ""; };

        private:
            Word** words;
        };
        
        CompositeWordInvocation invocation;
    };
    
}

#endif /* CompositeWord_hpp */
