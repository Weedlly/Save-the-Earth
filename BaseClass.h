#ifndef BaseClass_h
#define BaseClass_h

#include "CommonFunction.h"

class BaseClass
{
public:
	BaseClass();
	~BaseClass();
	void Show(SDL_Surface* des);
	bool LoadImg(std::string name, int RGBa, int RGBb, int RGBc, int RGBd);
	void SetRect(int x, int y) { _rect.x = x, _rect.y = y; }
	SDL_Rect GetRect() { return _rect; }
	SDL_Surface* GetObject() { return _object; }
protected:
	SDL_Rect _rect;
	SDL_Surface* _object;
};

#endif // !BaseClass_h
