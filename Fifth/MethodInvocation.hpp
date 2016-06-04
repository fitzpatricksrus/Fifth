//
//  MethodInvocation.hpp
//  Fifth
//
//  Created by John Fitzpatrick on 1/25/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#ifndef MethodInvocation_hpp
#define MethodInvocation_hpp


#include "Word.hpp"

namespace us_cownet_fifth_OO {
	
	using namespace us_cownet_fifth_interp;
	
	class MethodInvocation : public Word {
	public:
		virtual void execute(ExecutionThread& thread);
		
	private:
		int messageKey;
		int paramCount;
	};
}


#endif /* MethodInvocation_hpp */
