
#ifndef STATE5_H_
#define STATE5_H_

#include "./library/StateMachine.h"


class STATE5: public StateMachine {

public:
	STATE5();

	void activate();
	void handleExits();
	void handleActivation();
	void initialize();
	void tick();

private:
	void deactivate();
};

#endif

