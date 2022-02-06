#include "Boss.h"

Boss::Boss() : BaseClass() {
	_rect.w = BOSS_WIDGHT;
	_rect.h = BOSS_HEIGHT;
	_rect.x = 0;
	_rect.y = 0;
	_A = 0;
	_B = 0;
	_isSide = true;
	_target_x = range_x(engine);
	_target_y = range_y(engine);

	_heal = 100;
}

Boss::~Boss() {
}

void Boss::CreateEquation() {
	_target_x = range_x(engine);
	_target_y = range_y(engine);

	if (_rect.x < _target_x) {
		_isSide = true;
	}
	else
	{
		_isSide = false;
	}
		
	_A = (_rect.y - _target_y) * 1.0 /  (_rect.x - _target_x);
	_B = _rect.y - _rect.x * _A;
}
void Boss::CallBoss() {
	if (_isSide == true)
		_rect.x += BOSS_WIDGHT / 30;
	else
		_rect.x -= BOSS_WIDGHT / 30;
	_rect.y = _B + (_A * _rect.x);
}

bool Boss::HandleBoss() {
	if (_isSide == true && _rect.x >= _target_x )
	{
		return true;
	}
	else if (_isSide == false && _rect.x <= _target_x)
	{
		return true;
	}
	else if (_rect.x < 0 || _rect.x + BOSS_WIDGHT > SCREEN_LENGTH)
	{
		return true;
	}
	else if (_rect.y < 0 || _rect.y + BOSS_HEIGHT > SCREEN_WIDTH)
	{
		return true;
	}
	return false;
}

void Boss::FireF0() {
	for (int i = 1; i <= 6; i++)
	{
		F0* f0 = new F0;
		f0->SetType(i);
		f0->SetRect(_rect.x, _rect.y);
		_F0List.push_back(f0);
	}
}

bool Boss::BossIsDie() {
	if (_heal != 0) {
		_heal--;
		return false;
	}
	else return true;
}