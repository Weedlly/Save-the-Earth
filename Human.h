#ifndef Human_h
#define Human_h

#include "BaseClass.h"
#include "F0.h"
#include "Bullet.h"
#include "Boss.h"
#include "Rocket.h"
#define HEIGHT_MAIN_OBJECT 40
#define WIDTH_MAIN_OBJECT 40
class Human : public BaseClass
{
public:
	Human();
	~Human();
	void HandleInputAction(SDL_Event event);
	void HandleMove();
	
	std::vector<Bullet*> GetBulletList() { return _bulletList; }
	void SetBulletList(std::vector<Bullet*> bulletList) { _bulletList = bulletList ; };
	void FireBullet();

	std::vector<Rocket*> GetRocketList() { return _rocketList; }
	void SetRocketList(std::vector<Rocket*> rocketList) { _rocketList = rocketList; };


	void SetBoss(Boss& virut) { _virut = virut; }
	Boss GetBoss() const { return _virut; }
private:
	std::vector<Bullet*> _bulletList;
	std::vector<Rocket*> _rocketList;
	Boss _virut;
	int x_val_;
	int y_val_;
	
};
#endif // !Human_h
