#ifndef Meteorite_h
#define Meteorite_h

#include "BaseClass.h"

const int METEORITE_WIDGHT = 30;
const int METEORITE_HEIGHT = 15;

class Meteorite : public BaseClass
{
public:
	Meteorite();
	void CallMetorite();
	bool HandleMetorite();
	~Meteorite();

private:
	int _x_val;
	int _y_val;
};

#endif // !Meteorite_h
