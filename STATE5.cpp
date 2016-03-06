
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
void STATE5::initialize() {
	StateMachine::initialize();
}
STATE5::STATE5() :StateMachine() {
	initialize();
}
void STATE5::activate() {
	StateMachine::activate();
out(M,true,-1);
out(FB,false,-1);
out(MOTOR,false,-1);
out(SB,false,-1);
	StateMachine::activate();
}
void STATE5::handleActivation() {
	if (running && finished ) {
		activate();
	}
}

void STATE5::handleExits() { 
	if (running && !finished &&  ev_m_stop) { //emergency stop the FB machine
		finish();
		 state4->tick();
	}
	if (running && !finished &&  ev_all_start) { //emergency stop the FB machine
		finish();
		 state6->tick();
	}
}
void STATE5::tick() { 
        StateMachine::tick();
    	handleActivation();
    	handleExits();
}
