/*
 * StateMachine.cpp
 *
 *  Created on: 27 nov. 2015
 *      Author: pfister
 */

#include "StateMachine.h"

#ifdef SMLOG
#include "State.h"
#endif

/*void StateMachine::f_initial() {
	Serial.println("should not be called: f_initial");
}*/
void StateMachine::f_start() {
	//Serial.println("should not be called: f_start");
}
void StateMachine::f_restart() {
	//Serial.println("should not be called: f_restart");
}
void StateMachine::f_exit() {
	//Serial.println("should not be called: f_exit");
}

void StateMachine::f_dummy() {

}

void StateMachine::initialize() {
#ifdef SMLOG
	name[0] = 0;
#endif

	finished = true;
	running = true;
	mark = millis();
	s_exec = NULL;
	s_entered = NULL;
	//s_waiting = &StateMachine::f_initial;
	s_start = &StateMachine::f_start;
	s_restart = &StateMachine::f_restart;
	s_exit = &StateMachine::f_exit;
	stsn = 0;

#ifdef SMLOG
	for (int i = 0; i < MAX_STATES; i++)
	states[i] = NULL;
#endif

#ifdef SMLOG
	logger = NULL;

#endif
}

StateMachine::StateMachine() {
	initialize();
}

#ifdef SMLOG
State* StateMachine::registerState(PRUN func, char*name, StateKind kind) {

	if (kind == skinitial)
	s_waiting = func;
	else if (kind == skdummy_) {
		//s_waiting = f_dummy;
		s_waiting = &StateMachine::f_dummy;
	}

	if (stsn < MAX_STATES - 1) {
		State* s = new State(this, func, name, kind);
		states[stsn++] = s;
		return s;
	}
	Serial.println("max states reached !");
	return NULL;
}
#else

void StateMachine::registerState(PRUN func, StateKind kind) {
	if (kind == skinitial)
		s_waiting = func;
	else if (kind == skdummy)
		s_waiting = &StateMachine::f_dummy;
}

#endif

#ifdef SMLOG
StateMachine::StateMachine(PLogger loggr, char* _name) {
	initialize();
	logger = loggr;
	strcpy(name, _name);
}

void StateMachine::log_exit() {
	Serial.print(name);
	Serial.print(" ");
	Serial.println("emergency exit");
}

void StateMachine::log_entry() {
	Serial.print(name);
	Serial.print(" ");
	Serial.println("entry");
}

void StateMachine::log_restart() {
	Serial.print(name);
	Serial.print(" ");
	Serial.println("restart");
}

void StateMachine::logState(PCHAR msg) {
	if (msg != NULL) {
		Serial.print(msg);
		Serial.print(" ");
	}
	logStat();
}

void StateMachine::logStat() {
	boolean result = false;
	Serial.print("(");
	Serial.print(finished?"finished":"active");
	Serial.print(running?" running":" paused");
	Serial.print(")");
	Serial.print(name);
	if (s_exec == NULL)
	Serial.println(".[NULL]");
	else {
		for (int i = 0; i < MAX_STATES; i++) {
			if (states_[i] != NULL) {
				if (states[i]->func == s_exec) {
					Serial.print(".[");
					Serial.print(states[i]->name);
					Serial.println("]");
					result = true;
					break;
				}
			}
		}
		if (!result) {
			if (s_exec == s_start)
			Serial.println(".[start]");
			else if (s_exec == s_waiting)
			Serial.println(".[waiting]");
			else if (s_exec == s_restart)
			Serial.println(".[restart]");
			else if (s_exec == s_exit)
			Serial.println(".[exit]");
		}
	}
}

void StateMachine::debugMachine() {
	logState(NULL);
}

#endif

void StateMachine::tick() { //equivalent to nilton's EXEC
	if (running && !finished) {
		if (s_exec == NULL)
#ifdef SMLOG
			set(s_start, "NULL->start");
#else
			set(s_start);
#endif
		else if (s_exec == s_start)
#ifdef SMLOG
			set(s_waiting, "start->waiting");
#else
			set(s_waiting);
#endif
		else if (s_exec != NULL) {
			(this->*s_exec)();
		}
	}
}

void StateMachine::finish() {
#ifdef SMLOG
	log_exit();
#endif
	s_exec = NULL;
	finished = true;
}

void StateMachine::activate() {
#ifdef SMLOG
	log_entry();
#endif
	finished = false;
	//running = true; NO !! //FP160115
}

void StateMachine::restart() {
	finished = false;
	//set_(history, "history");
}

#ifdef SMLOG
void StateMachine::set(PRUN newstate, PCHAR log) {
	s_exec = newstate;
	logState(log);  //log millis()-mark
	mark = millis();
	s_entered = s_exec;
}
#else
void StateMachine::set(PRUN newstate) {
	s_exec = newstate;
	mark = millis();
	s_entered = s_exec;
}
#endif

boolean StateMachine::entry() {
	boolean result = s_exec != NULL && s_exec != &StateMachine::f_start
			&& s_exec != &StateMachine::f_restart
			&& s_exec != &StateMachine::f_exit && s_exec == s_entered;
	s_entered = NULL;
	return result;
}

void StateMachine::endCycle() {
	//entered_ = NULL;
}

boolean StateMachine::timeout(unsigned long time) {
	return (millis() - mark) > time;
}

