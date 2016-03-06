
#ifndef STATE3_H_
#define STATE3_H_

#include "./library/StateMachine.h"


class STATE3: public StateMachine {

public:
	STATE3();

	void activate();
	void handleExits();
	void handleActivation();
	void initialize();
	void tick();

private:
	void deactivate();
};

#endif

