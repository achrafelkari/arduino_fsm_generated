/*
 * StateMachine.h
 *
 *  Created on: 27 nov. 2015
 *      Author: pfister
 *
 * Object version (singletons), inspired by:
 * http://playground.arduino.cc/Code/SMlib (author: nilton 61)
 * improvements:
 *   state composition, submachines
 *   detection of entry in states
 *   x
 *   y
 *
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include <Arduino.h>



class StateMachine;


#define call(object,ptrToMember)  ((object).*(ptrToMember))


typedef const char* PCHAR;

typedef void STATE;
typedef STATE ( StateMachine::*PRUN ) ( void );

#define SMLOG_


#ifdef SMLOG
class State;
#endif



typedef enum {
	skinitial = 1, skhistory = 2,
	skdeepHistory = 3, skfinal = 4,
	skexit = 5,
	skstart = 6,
	sknormal = 7,
	skdummy = 8
} StateKind ;

#ifdef SMLOG
#include "State.h"
#endif


#ifdef SMLOG
#define MAX_STATES 10
#define ns(f) #f
#endif



// exemple :ev_master_stop = master_stop && !prior_master_stop; prior_master_stop = master_stop;
#define in_event(signal)  ev_##signal = signal && !prior_##signal; prior_##signal =signal

#define debug_event(signal) if (signal) Serial.println(#signal)// ca c'est un affichage !



//#define in_event1nu(signal) in_ev(signal, &prior_##signal)

//class StateMachine;

#ifdef SMLOG
typedef void (*PLogger)(char*);
#endif


class StateMachine {
public:
	StateMachine();
#ifdef SMLOG
	StateMachine(PLogger, char*);
#endif

	int stsn;
	PRUN s_waiting;
	PRUN s_entered;
	PRUN s_exec;
	PRUN s_start;
	PRUN s_restart;
	PRUN s_exit;

	void f_initial();
	void f_start() ;
	void f_restart();
	void f_exit();
	void f_dummy() ;

#ifdef SMLOG
	State* states[MAX_STATES];
	State* registerState(PRUN astate, char*name, StateKind kind);
#else

	void registerState(PRUN astate, StateKind kind);
#endif


#ifdef SMLOG
	PLogger logger;
	char name[15];
	void logState(PCHAR msg);
	void debugMachine();
	void log_restart();
	void log_exit();
	void log_entry();
	void logStat();

#endif

	void tick();
	void finish();
	void activate();
	void restart();

#ifdef SMLOG
    void set(PRUN astate, PCHAR log);
#else
    void set(PRUN astate);
#endif
	unsigned long mark; //timer mark
	boolean finished;
	boolean running;
	boolean timeout(unsigned long time);
	boolean entry();
	void initialize();
	void handleExits();
	void handleActivations();
	void endCycle();
};

#endif /* STATEMACHINE_H_ */
