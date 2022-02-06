#include "Bullet.h"
Bullet::Bullet() : BaseClass() {
	_rect.w = BULLET_WIDGHT;
	_rect.h = BULLET_HEIGHT;
	_rect.x = 0;
	_rect.y = 0;
	_x_val = 0;
	_y_val = 0;
	this->LoadImg("Pictrue//BulletYellow.png", 255, 255, 255, 255);
	if (this->_object == NULL)
	{
		std::cout << "Bullet can't load" << std::endl;
	}
}

Bullet::~Bullet() {
}

void Bullet::CallBullet() {
	_rect.y -= BULLET_HEIGHT/3;
}

bool Bullet::HandleBullet() {
	if (_rect.x < 0 || _rect.x > SCREEN_LENGTH  || _rect.y < 0 || _rect.y > SCREEN_WIDTH)
	{
		return true;
	}
	return false;
}