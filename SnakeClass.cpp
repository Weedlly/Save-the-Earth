#include "SnakeClass.h"
SnakeClass::SnakeClass() : BaseClass() {
	x_val_ = y_val_ = 0;
	_restartMeteorites = 0;
	_level = 0;
}
SnakeClass::~SnakeClass() {
}
void SnakeClass::HandleInputAction(SDL_Event event) {
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			/*case SDLK_UP:
				y_val_ -= HEIGHT_MAIN_OBJECT / 4;
				break;
			case SDLK_DOWN:
				y_val_ += HEIGHT_MAIN_OBJECT / 4;
				break;*/
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
			/*case SDLK_UP:
				y_val_ += HEIGHT_MAIN_OBJECT / 4;
				break;
			case SDLK_DOWN:
				y_val_ -= HEIGHT_MAIN_OBJECT / 4;
				break;*/
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
	}
	else {
	}
}
void SnakeClass::HandleMove() {
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

void SnakeClass::InitMeteoritesList() {
	int NumberOfInitMeteorite = _level * 10 + 20;
	std::vector<Meteorite> meteorites(NumberOfInitMeteorite);
	_meteorites = meteorites;
}

bool SnakeClass::HandleUplevel() {
	if (_restartMeteorites >= _level * 10 + 20)
	{
		_restartMeteorites = 0;
		_level++;
		return true;
	}
	return false;
}

bool SnakeClass::HitTheEarth(Meteorite& meteorite) {
	SDL_Rect rectMeteo = meteorite.GetRect();
	for (int i = _rect.x; i <= _rect.x + HEIGHT_MAIN_OBJECT; i++)
	{
		for (int j = _rect.y; j <= _rect.y + WIDTH_MAIN_OBJECT; j++)
		{
			if (i  < (rectMeteo.x + rectMeteo.w) && i > rectMeteo.x && j < (rectMeteo.y + rectMeteo.h) && j > rectMeteo.y) {
				return true;
			}
		}
	}

	return false;
}