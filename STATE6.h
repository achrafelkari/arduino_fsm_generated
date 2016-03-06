
#ifndef STATE6_H_
#define STATE6_H_

#include "./library/StateMachine.h"


class STATE6: public StateMachine {

public:
	STATE6();

	void activate();
	void handleExits();
	void handleActivation();
	void initialize();
	void tick();

private:
	void deactivate();
};

#endif

