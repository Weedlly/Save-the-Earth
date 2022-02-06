#include "F0.h"
F0::F0() : BaseClass() {
	_rect.w = METEORITE_WIDGHT;
	_rect.h = METEORITE_HEIGHT;
	_rect.x = 0;
	_rect.y = 0;
	_x_val = 0;
	_y_val = 0;
	_type = 0;
	this->LoadImg("Pictrue//F0(BossBullet).png", 255, 255, 255, 255);
	if (this->_object == NULL)
	{
		std::cout << "Object can't load" << std::endl;
	}
}

F0::~F0() {
}

void F0::CallF0() {
	switch (_type)
	{
	case 1: {
		_rect.x += F0_SPEED;
		_rect.y += F0_SPEED;
		break;
	}
	case 2: {
		_rect.y += F0_SPEED;
		break;
	}
	case 3: {
		_rect.x -= F0_SPEED;
		_rect.y -= F0_SPEED;
		break;
	}
	case 4: {
		_rect.y -= F0_SPEED;
		break;
	}
	case 5: {
		_rect.x += F0_SPEED;
		break;
	}
	case 6: {
		_rect.x -= F0_SPEED;
		break;
	}
	default:
		break;
	}
}

bool F0::HandelF0() {
	if (_rect.x < 0 || _rect.x > SCREEN_LENGTH  || _rect.y < 0 || _rect.y > SCREEN_WIDTH)
	{
		return true;
	}
	return false;
}