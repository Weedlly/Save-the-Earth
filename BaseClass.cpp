#include "BaseClass.h"

BaseClass::BaseClass() {
	_rect.x = _rect.y = 0;
	_object = NULL;
}
BaseClass::~BaseClass() {
	if (_object == NULL)
	{
		delete _object;
	}
}
void BaseClass::Show(SDL_Surface* des) {
	if (_object != NULL)
	{
		SDLCommonFunction::ApplySurface(_object, des, _rect.x, _rect.y);
	}
}

bool BaseClass::LoadImg(std::string name, int RGBa, int RGBb, int RGBc, int RGBd) {
	_object = SDLCommonFunction::LoadImageW(name, RGBa, RGBb, RGBc, RGBd);
	if (_object == NULL)
		return false;
	return true;
}