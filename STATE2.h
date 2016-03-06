
#ifndef STATE2_H_
#define STATE2_H_

#include "./library/StateMachine.h"


class STATE2: public StateMachine {

public:
	STATE2();

	void activate();
	void handleExits();
	void handleActivation();
	void initialize();
	void tick();

private:
	void deactivate();
};

#endif

