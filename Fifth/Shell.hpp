/*

 context vocabulary
 current vocabulary
 compile stack
 inputBuffer
 inputPos
 tokenBuffer
 tokenPos
 
 : readToken
	skipWhiteSpace
	inputPos inputBuffer stringLength >= if
		do
			readLine
			skipWhiteSpace
		inputPos inputBuffer stringLength >= while
	endif
	tokenPos 0 !
	do
		tokenBuffer tokenPos inputBuffer inputPos c@ c!
		inputPos inputPos @ 1 + !
        tokenPos tokenPos @ 1 + !
    inputBuffer inputPos isWhiteSpace not while
    tokenBuffer tokenPos 0 c!
 ;
 
 : OuterInterp
 repeat
 readToken                  { token }
 dup                        { token token }
 searchCurrentContext       { token (null OR word) }
 dup NULL = not if          { token (null OR word) }
   swap                     { word token }
   drop                     { word }
   execute                  { }
 else
   drop                     { token }
   parseNumber              { token false OR number true }
   if                       { token OR number }
     push on stack          { }
   else
     printError             { }
   endif
 endif
 endRepeat
 ;
 
 
 root variable: "inputBuffer" is: ""
 inputBuffer variable: "length' is: 0
 
 root variable: "outperInterp"
 
 outperInterp variable: "isWhiteSpace:at:" is: { buffer pos |
	(buffer at: pos) == ' '
 }
 outerInterp isWhatSpace: 'b'
 (outerInterp isWhatSpace: ' ') if: { "It's white space" print }
 { outerInterp isWhatSpace: ' ' } if: { "It's white space" print }
 { outerInterp isWhatSpace: ' ' } whileTrue: { "true" }

 
	
 
*/
#ifndef Shell_hpp
#define Shell_hpp

#include <stdio.h>
#include "Word.hpp"
#include "ExecutionThread.hpp"

namespace us_cownet_fifth_shell {
    
    using us_cownet_fifth_interp::ExecutionThread;
    using us_cownet_fifth_interp::Word;
    
    class OuterShell : public Word {
    public:
        virtual void execute(ExecutionThread& thread);
        
    };
}

#endif /* Shell_hpp */
