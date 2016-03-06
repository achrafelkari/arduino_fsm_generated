
#ifndef STATE4_H_
#define STATE4_H_

#include "./library/StateMachine.h"


class STATE4: public StateMachine {

public:
	STATE4();

	void activate();
	void handleExits();
	void handleActivation();
	void initialize();
	void tick();

private:
	void deactivate();
};

#endif

