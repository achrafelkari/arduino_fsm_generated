
#ifndef STATE1_H_
#define STATE1_H_

#include "./library/StateMachine.h"


class STATE1: public StateMachine {

public:
	STATE1();

	void activate();
	void handleExits();
	void handleActivation();
	void initialize();
	void tick();

private:
	void deactivate();
};

#endif

