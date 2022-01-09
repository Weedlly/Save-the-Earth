#include "Meteorite.h"
Meteorite::Meteorite() : BaseClass() {
	_rect.w = METEORITE_WIDGHT;
	_rect.h = METEORITE_HEIGHT;
	_rect.x = distribution(engine);
	_rect.y = 0;
	_x_val = range_x(engine);
	_y_val = range_y(engine);
	this->LoadImg("meteorite.png", 1, 1, 1, 255);
	if (this->_object == NULL)
	{
		std::cout << "Object can't load" << std::endl;
	}
}

Meteorite::~Meteorite() {
}

void Meteorite::CallMetorite() {
	_rect.x -= _x_val;
	_rect.y += _y_val;
}

bool Meteorite::HandleMetorite() {
	if (_rect.x < 0 /*|| _rect.x > SCREEN_LENGTH */ || _rect.y < 0 || _rect.y > SCREEN_WIDTH)
	{
		_rect.x = distribution(engine);
		_rect.y = 0;
		_x_val = range_x(engine);
		_y_val = range_y(engine);
		return true;
	}
	return false;
}