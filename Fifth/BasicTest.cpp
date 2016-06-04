//
//  BasicTest.cpp
//  Fifth
//
//  Created by John Fitzpatrick on 1/25/16.
//  Copyright © 2016 Dad. All rights reserved.
//

#include "BasicTest.hpp"

#include <iostream>

#include "ExecutionThread.hpp"
#include "ExitCompositeWord.hpp"
#include "Processor.hpp"
#include "PPrintString.hpp"
#include "PStringConstant.hpp"
#include "PStringCompare.hpp"
#include "PReadString.hpp"
#include "PGoto.hpp"
#include "PIf.hpp"
#include "PDup.hpp"
#include "PNot.hpp"
#include "PNoOp.hpp"

namespace us_cownet_tests {
	
	using us_cownet_fifth_interp::CompositeWord;
	using us_cownet_fifth_interp::ExitCompositeWord;
	using us_cownet_fifth_interp::Processor;
	using us_cownet_fifth_interp::Word;
	using us_cownet_fifth_primitives_string::PStringConstant;
	using us_cownet_fifth_primitives_string::PStringCompare;
	using us_cownet_fifth_primitives_string::PPrintString;
	using us_cownet_fifth_primitives_string::PReadString;
	using us_cownet_fifth_primitives::PGoto;
	using us_cownet_fifth_primitives::PIf;
	using us_cownet_fifth_primitives::PDup;
	using us_cownet_fifth_primitives::PNot;
	using us_cownet_fifth_primitives::PNoOp;
	
	PReadString inputString;
	PStringConstant exitString("exit");
	PPrintString printString;
	PGoto gotoWord(0);
	PIf ifWord(0);
	ExitCompositeWord ecd;
	
	Word* printStringWords[] = {
		&printString,
		&ecd
	};
	CompositeWord printStringComposite(printStringWords);
	Word* printStringWords2[] = {
		&PNoOp::INSTANCE,
		&printStringComposite,
		&ecd
	};
	CompositeWord printStringComposite2(printStringWords2);
	
	Word* testWords[] = {
		&inputString,
		&PDup::INSTANCE,
		&printStringComposite2,
		&exitString,
		&PStringCompare::INSTANCE,
		&PNot::INSTANCE,
		&ifWord,
		&ecd
	};
	CompositeWord mainWord(testWords);
	
	Word* loopWords[] = {
		&exitString,
		&printString,
		&gotoWord,
		&ecd
	};
	CompositeWord loopWord(loopWords);
	
	int main(int argc, const char * argv[]) {
		Processor p;
		p.addThread(&mainWord, true);
//		p.addThread(&loopWord, true);
		p.process();
		
		return 0;
	};
	
}

