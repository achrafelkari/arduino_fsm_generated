
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
void STATE4::initialize() {
	StateMachine::initialize();
}
STATE4::STATE4() :StateMachine() {
	initialize();
}
void STATE4::activate() {
	StateMachine::activate();
out(FB,true,-1);
out(M,false,-1);
out(SB,false,-1);
out(MOTOR,false,-1);
	StateMachine::activate();
}
void STATE4::handleActivation() {
	if (running && finished ) {
		activate();
	}
}

void STATE4::handleExits() { 
	if (running && !finished &&  ev_m_start) { //emergency stop the FB machine
		finish();
		 state5->tick();
	}
	if (running && !finished &&  ev_fb_stop) { //emergency stop the FB machine
		finish();
		 state6->tick();
	}
}
void STATE4::tick() { 
        StateMachine::tick();
    	handleActivation();
    	handleExits();
}
