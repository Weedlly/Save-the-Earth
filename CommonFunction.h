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

#undef main
using std::string;

// Default surface
static SDL_Surface* s_screen = NULL;
static SDL_Surface* s_background = NULL;
static SDL_Event s_event;

//Audio
static Mix_Chunk* s_sound_hit_boss = NULL;
static Mix_Chunk* s_sound_explosion = NULL;
static Mix_Chunk* s_sound_bullet = NULL;

const int SCREEN_LENGTH = 1200;
const int SCREEN_WIDTH = 600;
const int SCREEN_BPP = 32;

const int INIT_HUMAN_LOCATION_X = 580;
const int INIT_HUMAN_LOCATION_Y = 500;
const int INIT_BOSS_LOCATION_X = 550;
const int INIT_BOSS_LOCATION_Y = 100;

static std::random_device sd{};
/*std::default_random_engine generator;*/
static std::mt19937 engine{ sd() };
static std::uniform_int_distribution<int> distribution(0, SCREEN_LENGTH + 200);
static std::uniform_int_distribution<int> range_x(100, 1110);
static std::uniform_int_distribution<int> range_y(100, 500);

namespace SDLCommonFunction {
	SDL_Surface* LoadImage(std::string filename, int RGBa, int RGBb, int RGBc, int RGBd);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	bool LoadContent(int x, int y, string content);
	bool CollisionCheck(SDL_Rect obj1,SDL_Rect object2, double r, int oj2_width, int oj2_length);
	void CleanUp();
	
}

#endif // !CommonFunction_h
