#include "Shell.hpp"

namespace us_cownet_fifth_shell {

    void OuterShell::execute(ExecutionThread& thread) {
    
    }

}

/*


 do
	inputBuffer readline
	inputPos 0 !
	
	do
		inputPos (inputBuffer inputPos tokenize) !
		dup if
			execute
		endif
	inputPos inputBuffer length >= until
 false until


*/