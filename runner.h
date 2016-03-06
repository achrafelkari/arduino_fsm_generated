
#ifndef _runner_H_
#define _runner_H_
#include "Arduino.h"
#include "library/StateMachine.h"
#include "iomapping.h"

//geretated by acceleo ! 
    #include "STATE5.h"
    #include "STATE1.h"
    #include "STATE4.h"
    #include "STATE3.h"
    #include "STATE6.h"
    #include "STATE2.h"


#ifdef __cplusplus
extern "C" {
#endif


#define FSIMULATE_RESET_DELAY


void SM_loop();
void SM_setup();


//by Acceleo
    class STATE5;
    extern STATE5* state5;

    class STATE1;
    extern STATE1* state1;

    class STATE4;
    extern STATE4* state4;

    class STATE3;
    extern STATE3* state3;

    class STATE6;
    extern STATE6* state6;

    class STATE2;
    extern STATE2* state2;



void nop();
void SM_setEvent();
void addSm(StateMachine* machine);
void StateMachine_loop();
void StateMachine_setup();
void StateMachine_setEvent();

#ifdef __cplusplus
} // extern "C"
#endif

#endif

