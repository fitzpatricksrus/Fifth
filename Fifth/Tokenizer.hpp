#ifndef Tokenizer_hpp
#define Tokenizer_hpp

#include <stdio.h>
#include <string>

namespace us_cownet_utils {

    using std::string;

    class Tokenizer {
    public:
        Tokenizer(string s);
        
        bool isSeperator(char c);
        
        string nextToken();
        
    private:
        int pos;
        string source;
    };
    
    
}

#endif /* Tokenizer_hpp */
