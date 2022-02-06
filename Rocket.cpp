#include "Rocket.h"

Rocket::Rocket() : BaseClass() {
	_rect.w = ROCKET_WEIDTH;
	_rect.h = ROCKET_HEIGHT;
	_rect.x = 0;
	_rect.y = 0;
	_A = 0;
	_B = 0;
	_isSide = true;
	_target_x = SCREEN_LENGTH / 2;
	_target_y = SCREEN_WIDTH / 2;
	this->LoadImg("Pictrue//KimTiem(Rocket).png", 0, 0, 0, 0);
	if (this->_object == NULL)
	{
		std::cout << "Rocket can't load" << std::endl;
	}
}
Rocket::~Rocket() {

}

void Rocket::CreateEquation() {

	if (_rect.x < _target_x) {
		_isSide = true;
	}
	else
	{
		_isSide = false;
	}
	_A = (_rect.y - _target_y) * 1.0 / (_rect.x - _target_x);
	_B = _rect.y - _rect.x * _A;
}

void Rocket::CallRocket() {
	if (_isSide == true)
		_rect.x += ROCKET_WEIDTH / 5;
	else
		_rect.x -= ROCKET_WEIDTH / 5;
	_rect.y = _B + (_A * _rect.x);
}

bool Rocket::HandleRocket() {
	if (_isSide == true && _rect.x >= _target_x)
	{
		return true;
	}
	else if (_isSide == false && _rect.x <= _target_x)
	{
		return true;
	}
	return false;
}