/*
 * State.h
 *
 *  Created on: 30 nov. 2015
 *      Author: pfister
 */

#ifndef H_
#define H_
#include "StateMachine.h"



class State {

public:
	StateMachine* owner;
	PRUN func;
	char name[20];
	boolean initial;
	StateKind kind;
	State(StateMachine* owner, PRUN func, char* name,StateKind kind);
};

#endif /* H_ */
