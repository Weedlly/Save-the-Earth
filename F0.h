#ifndef F0_h
#define F0_h

#include "BaseClass.h"

const int METEORITE_WIDGHT = 20;
const int METEORITE_HEIGHT = 20;
const int F0_SPEED = 4;

class F0 : public BaseClass
{
public:
	F0();
	void CallF0();
	bool HandelF0();

	void SetType(int type) { _type = type; }
	~F0();

private:
	int _x_val;
	int _y_val;
	int _type;
};

#endif // !F0_h
