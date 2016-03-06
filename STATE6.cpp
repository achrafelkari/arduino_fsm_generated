
#include "./runner.h"
#include "./io.h"
 // byAcceleo
    #include "./STATE5.h"
 // byAcceleo
    #include "./STATE1.h"
 // byAcceleo
    #include "./STATE4.h"
 // byAcceleo
    #include "./STATE3.h"
 // byAcceleo
    #include "./STATE6.h"
 // byAcceleo
    #include "./STATE2.h"
void STATE6::initialize() {
	StateMachine::initialize();
}
STATE6::STATE6() :StateMachine() {
	initialize();
}
void STATE6::activate() {
	StateMachine::activate();
out(M,true,-1);
out(FB,true,-1);
out(MOTOR,true,-1);
out(SB,true,-1);
	StateMachine::activate();
}
void STATE6::handleActivation() {
	if (running && finished ) {
		activate();
	}
}

void STATE6::handleExits() { 
	if (running && !finished &&  ev_all_stop) { //emergency stop the FB machine
		finish();
		 state1->tick();
	}
}
void STATE6::tick() { 
        StateMachine::tick();
    	handleActivation();
    	handleExits();
}
