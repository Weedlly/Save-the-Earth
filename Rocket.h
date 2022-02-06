#ifndef Rocket_h
#define Rocket_h

#include "BaseClass.h"

const int ROCKET_WEIDTH = 15;
const int ROCKET_HEIGHT = 20;

class Rocket : public BaseClass
{
public:
	Rocket();
	~Rocket();
	void CreateEquation();
	void CallRocket();
	bool HandleRocket();

private:
	double _A;
	double _B;
	int _target_x;
	int _target_y;
	bool _isSide;
};

#endif // !Rocket_h

