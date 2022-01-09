#ifndef CommonFunction_h
#define CommonFunction_h
#include <Windows.h>
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <random>
#include <vector>
#include <iostream>
#include <SDL_mixer.h>
//#include "TestObject.h"
#undef main
using std::string;

// Default surface
static SDL_Surface* s_screen = NULL;
static SDL_Surface* s_background = NULL;
static SDL_Event s_event;

//Audio
static Mix_Chunk* s_sound_meteorite = NULL;
static Mix_Chunk* s_sound_explosion = NULL;
static Mix_Chunk* s_sound_ex_main = NULL;

const int SCREEN_LENGTH = 1200;
const int SCREEN_WIDTH = 600;
const int SCREEN_BPP = 32;

const int UNDER_GROUND = 500;

static std::random_device sd{};
/*std::default_random_engine generator;*/
static std::mt19937 engine{ sd() };
static std::uniform_int_distribution<int> distribution(0, SCREEN_LENGTH + 200);
static std::uniform_int_distribution<int> range_x(1, 10);
static std::uniform_int_distribution<int> range_y(1, 6);

namespace SDLCommonFunction {
	SDL_Surface* LoadImage(std::string filename, int RGBa, int RGBb, int RGBc, int RGBd);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	bool LoadContent(int x, int y, string content);
	void CleanUp();
}

#endif // !CommonFunction_h
