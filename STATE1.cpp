
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
void STATE1::initialize() {
	StateMachine::initialize();
}
STATE1::STATE1() :StateMachine() {
	initialize();
}
void STATE1::activate() {
	StateMachine::activate();
out(MOTOR,false,-1);
out(SB,false,-1);
out(FB,false,-1);
out(M,false,-1);
	StateMachine::activate();
}
void STATE1::handleActivation() {
	if (running && finished ) {
		activate();
	}
}

void STATE1::handleExits() { 
	if (running && !finished &&  ev_fb_start) { //emergency stop the FB machine
		finish();
		 state4->tick();
	}
	if (running && !finished &&  ev_master_start) { //emergency stop the FB machine
		finish();
		 state2->tick();
	}
}
void STATE1::tick() { 
        StateMachine::tick();
    	handleActivation();
    	handleExits();
}
