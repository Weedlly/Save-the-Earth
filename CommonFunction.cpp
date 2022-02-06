#include "CommonFunction.h"
SDL_Surface* SDLCommonFunction::LoadImage(std::string filename, int RGBa, int RGBb, int RGBc, int RGBd) {
	SDL_Surface* image = NULL;
	SDL_Surface* optimize = NULL;
	image = IMG_Load(filename.c_str());
	if (image != NULL) {
		optimize = SDL_DisplayFormat(image);
		SDL_FreeSurface(image);
		if (optimize != NULL)
		{
			UINT32 color_key = SDL_MapRGBA(optimize->format, RGBa, RGBb, RGBc, RGBd);
			SDL_SetColorKey(optimize, SDL_SRCCOLORKEY, color_key);
		}
	}
	return optimize;
}

void SDLCommonFunction::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}

void SDLCommonFunction::CleanUp() {
	SDL_FreeSurface(s_screen);
	SDL_FreeSurface(s_background);
}

bool SDLCommonFunction::LoadContent(int x, int y, string content) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	/*TextObject*/
	return true;
}

bool SDLCommonFunction::CollisionCheck(SDL_Rect obj1, SDL_Rect obj2, double r, int oj2_width, int oj2_length) {
	double R = pow(r,2);
	obj1.x += r;
	obj1.y += r;
	for (int i = obj2.x; i <= obj2.x + oj2_width; i++)
	{
		double D = pow(i - obj1.x, 2) + pow(obj2.y - obj1.y, 2);
		if (D < R)
		{
			return true;
		}
	}
	for (int i = obj2.x; i <= obj2.x + oj2_width; i++)
	{
		double D = pow(i - obj1.x, 2) + pow(oj2_length + obj2.y - obj1.y, 2);
		if (D < R)
		{
			return true;
		}
	}
	for (int i = obj2.y; i <= obj2.y + oj2_length; i++)
	{
		double D = pow(obj2.x - obj1.x, 2) + pow(i - obj1.y, 2);
		if (D < R)
		{
			return true;
		}
	}
	for (int i = obj2.y; i <= obj2.y + oj2_length; i++)
	{
		double D = pow(oj2_width + obj2.x - obj1.x, 2) + pow(i - obj1.y, 2);
		if (D < R)
		{
			return true;
		}
	}
	return false;
}