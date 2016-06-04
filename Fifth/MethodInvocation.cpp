//
//  MethodInvocation.cpp
//  Fifth
//
//  Created by John Fitzpatrick on 1/25/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#include "MethodInvocation.hpp"

#include "ExecutionThread.hpp"
#include "Object.hpp"

namespace us_cownet_fifth_OO {
	
	using namespace us_cownet_fifth_interp;
	
	void MethodInvocation::execute(ExecutionThread& thread) {
		Object* thiz = dynamic_cast<Object*>(thread.peekData(paramCount).w);
		if (thiz != nullptr) {
			Clazz* clazz = thiz->getClazz();
			Word* w = clazz->findMethod(messageKey);
			if (w != nullptr) {
				// thread.execute just calls execute() on the word,
				// but it allows the thread to do book keeping for
				// debug purposes.
				thread.execute(w);
				
			} else {
				thread.error("method not found: " + std::to_string(messageKey));
			}
		} else {
			thread.error("Message sent to non-object");
		}
	}
}

