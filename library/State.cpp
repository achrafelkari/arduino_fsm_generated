/*
 * State.cpp
 *
 *  Created on: 30 nov. 2015
 *      Author: pfister
 */

#include "State.h"



State::State(StateMachine* _owner, PRUN _func, char*_name,StateKind _kind) {
	owner = _owner;
	func = _func;
	kind =_kind;
	strcpy(name,_name);

}

