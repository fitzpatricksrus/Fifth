#ifndef ExecutionThread_h
#define ExecutionThread_h

#include "CompositeWord.hpp"
#include "List.hpp"

namespace us_cownet_fifth_interp {
    
    using us_cownet_utils::List;
    using std::string;
    
    class DataStackEntry {
    public:
        union {
            Word* w;
            int i;
        };
        
        DataStackEntry() {}
        DataStackEntry(int iIn) : i(iIn) {}
        DataStackEntry(Word* wIn) : w(wIn) {}
        DataStackEntry(const DataStackEntry& sIn) = default;
        DataStackEntry(DataStackEntry&& sIn) = default;
        ~DataStackEntry() {}
        DataStackEntry& operator=(const DataStackEntry& sIn) = default;
    };

    class ControlStackEntry {
    public:
        Word* w;
        int i;
        
        ControlStackEntry() : i(-1), w(0) {}
        ControlStackEntry(Word* wIn) : i(-1), w(wIn) {}
        ControlStackEntry(Word* wIn, int ndx) : i(ndx), w(wIn) {}
        ControlStackEntry(const ControlStackEntry& sIn) = default;
        ControlStackEntry(ControlStackEntry&& sIn) = default;
        ~ControlStackEntry() {}
        ControlStackEntry& operator=(const ControlStackEntry& sIn) = default;
    };

    // The entire execution context for this thread
    class ExecutionThread {
    public:
        ExecutionThread();
        ExecutionThread(Word* entryIn);
        ExecutionThread(const ExecutionThread& other);
        ExecutionThread(ExecutionThread&& other);
        ~ExecutionThread();
        ExecutionThread& operator=(const ExecutionThread& other);
        
        ControlStackEntry& peekControlStack();
        void pushControlStack(Word* entryIn);
        void pushControlStack(Word* entryIn, int ndx);
        void popControlStack();
		void execute(Word* word);

		void run();
        bool isDone();
        
        DataStackEntry& peekData(int ndx);
        DataStackEntry& peekData();
        void pushData(int i);
        int popInt();
        void pushData(DataStackEntry& w);
        void pushData(Word* w);
        Word* popData();
        void popData(int cnt);
        
        void debug(std::string msg);
        void warning(std::string msg);
        void error(std::string msg);
        
        void setDebug(bool debugOnIn);
        
    private:
        List<ControlStackEntry, 100> stack;
        List<DataStackEntry, 100> dataStack;
        bool debugOn;
    };
    
}

#endif /* ExecutionThread_h */
