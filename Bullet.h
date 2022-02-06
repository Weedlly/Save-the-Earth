#ifndef Bullet_h
#define Bullet_h

#include "BaseClass.h"

const int BULLET_WIDGHT = 10;
const int BULLET_HEIGHT = 13;

class Bullet : public BaseClass
{
public:
	Bullet();
	void CallBullet();
	bool HandleBullet();
	~Bullet();

private:
	int _x_val;
	int _y_val;
};


#endif // !Bullet_h
