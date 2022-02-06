#ifndef Boss_h
#define Boss_h

#include "BaseClass.h"
#include "F0.h"
const int BOSS_WIDGHT = 100;
const int BOSS_HEIGHT = 100;
class Boss : public BaseClass
{
public:
	Boss();
	~Boss();
	void CreateEquation();
	void CallBoss();
	bool HandleBoss();
	std::vector<F0*> GetFoList() { return _F0List; }
	void SetF0List(std::vector<F0*> F0List) { _F0List = F0List; }
	void FireF0();
	bool BossIsDie();

	int GetHeal() { return _heal; }
private:
	double _A;
	double _B;
	int _target_x;
	int _target_y;
	bool _isSide;
	int _heal;
	std::vector<F0*> _F0List;
};

#endif // !Boss_h

