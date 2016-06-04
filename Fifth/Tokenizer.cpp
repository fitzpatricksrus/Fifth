#include "Tokenizer.hpp"

namespace us_cownet_utils {
    
    Tokenizer::Tokenizer(string s)
    : source(s)
    {
    }
    
    bool Tokenizer::isSeperator(char c) {
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                return true;
                break;
            default:
                return false;
                break;
        }
    }
    
    string Tokenizer::nextToken() {
        string result = "";
        size_t len = source.length();
        // skip leading whitespace
        while (pos < len && isSeperator(source[pos])) {
            pos++;
        }
        // gather a token
        while (pos < len && !isSeperator(source[pos])) {
            result += source[pos++];
        }
        return result;
    }
    
}

