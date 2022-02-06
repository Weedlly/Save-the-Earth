#include "Human.h"
Human::Human() : BaseClass() {
	x_val_ = y_val_ = 0;
}
Human::~Human() {
}
void Human::HandleInputAction(SDL_Event event) {
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_ -= HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_DOWN:
			y_val_ += HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_RIGHT:
			x_val_ += WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_LEFT:
			x_val_ -= WIDTH_MAIN_OBJECT / 4;
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_ += HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_DOWN:
			y_val_ -= HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_RIGHT:
			x_val_ -= WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_LEFT:
			x_val_ += WIDTH_MAIN_OBJECT / 4;
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{
		Rocket* rocket = new Rocket;
		rocket->SetRect(_rect.x, _rect.y);
		rocket->CreateEquation();
		_rocketList.push_back(rocket);
	}
	else {
	}
}
void Human::HandleMove() {
	_rect.x += x_val_;
	if (_rect.x < 0 || _rect.x + WIDTH_MAIN_OBJECT > SCREEN_LENGTH)
	{
		_rect.x -= x_val_;
	}
	_rect.y += y_val_;
	if (_rect.y < 0 || _rect.y + HEIGHT_MAIN_OBJECT > SCREEN_WIDTH)
	{
		_rect.y -= y_val_;
	}
}
void Human::FireBullet() {
	Bullet* bullet = new Bullet;
	bullet->SetRect(_rect.x + HEIGHT_MAIN_OBJECT/2,_rect.y - WIDTH_MAIN_OBJECT/2);
	_bulletList.push_back(bullet);
}


