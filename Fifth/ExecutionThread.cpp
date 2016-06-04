#include <iostream>
#include "ExecutionThread.hpp"

namespace us_cownet_fifth_interp {
    
    ExecutionThread::ExecutionThread()
    : stack(), dataStack(), debugOn(false)
    {
    }
    
    ExecutionThread::ExecutionThread(Word* entryIn)
    : stack(), dataStack(), debugOn(false)
    {
        stack.add(entryIn);
    }
    
    ExecutionThread::ExecutionThread(const ExecutionThread& other)
    : stack(other.stack), dataStack(other.dataStack), debugOn(other.debugOn)
    {
    }
    
    ExecutionThread::ExecutionThread(ExecutionThread&& other)
    : stack(other.stack), dataStack(other.dataStack), debugOn(other.debugOn)
    {
    }
    
    ExecutionThread::~ExecutionThread() {
    }
    
    ExecutionThread& ExecutionThread::operator=(const ExecutionThread& other) {
        if (this == &other) return *this;
        stack = other.stack;
        dataStack = other.dataStack;
        debugOn = other.debugOn;
        return *this;
    }
    
    ControlStackEntry& ExecutionThread::peekControlStack() {
        return stack.peek();
    }
    
    void ExecutionThread::pushControlStack(Word* word) {
        stack.add(word);
    }
    
    void ExecutionThread::pushControlStack(Word* word, int ndx) {
        stack.add(ControlStackEntry(word, ndx));
    }
    
    void ExecutionThread::popControlStack() {
        stack.pop();
    }
    
    void ExecutionThread::execute(Word* w) {
        if (debugOn) {
            std::string name = w->debugName();
            if (name != "") {
                string indent = " > > > > > > > > > > > > > > > > > > > > > > > > >";
                indent = indent.substr(0, stack.size() * 2);
                
                std:string num = std::to_string(peekControlStack().i - 1);
                std::string pad = "   ";
                pad = pad.substr(0, pad.length() - num.length());
                num = pad + num;
                
                std::string msg =indent + num + ": " + name + "\n";
                debug(msg);
            }
        }
        w->execute(*this);
    }
    
	void ExecutionThread::run() {
		execute(stack.peek().w);
	}
	
    bool ExecutionThread::isDone() {
        return stack.size() == 0;
    }
    
    DataStackEntry& ExecutionThread::peekData(int ndx) {
        return dataStack.peek(ndx);
    }
    
    DataStackEntry& ExecutionThread::peekData() {
        return dataStack.peek();
    }
    
    void ExecutionThread::pushData(DataStackEntry& e) {
        dataStack.add(e);
    }
    
    void ExecutionThread::pushData(int i) {
        dataStack.add(i);
    }
    
    int ExecutionThread::popInt() {
        int i = dataStack.peek().i;
        dataStack.pop();
        return i;
    }
    
    void ExecutionThread::pushData(Word* w) {
        dataStack.add(w);
    }
    
    Word* ExecutionThread::popData() {
        Word* w = dataStack.peek().w;
        dataStack.pop();
        return w;
    }
    
    void ExecutionThread::popData(int cnt) {
        dataStack.pop(cnt);
    }
    
    void ExecutionThread::debug(std::string msg) {
        if (debugOn) {
            std::cout << msg;
        }
    }
    
    void ExecutionThread::warning(std::string msg) {
        std::cout << msg << "\n";
    }
    
    void ExecutionThread::error(std::string msg) {
        std::cout << msg << "\n";
    }
    
    void ExecutionThread::setDebug(bool debugOnIn) {
        debugOn = debugOnIn;
    }
}