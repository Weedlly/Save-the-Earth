#include "CommonFunction.h"
#include "SnakeClass.h"
#include "Meteorite.h"
bool Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)  return false;
	s_screen = SDL_SetVideoMode(SCREEN_LENGTH, SCREEN_WIDTH, SCREEN_BPP, SDL_SWSURFACE);
	if (s_screen == NULL)	return false;
	return true;
}

int main() {
	if (Init() != true)
	{
		return -1;
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return -1;
	}

	s_sound_meteorite = Mix_LoadWAV("MeteoriteSound.wav");
	s_sound_explosion = Mix_LoadWAV("ExplosionSound.wav");

	if (s_sound_explosion == NULL)
	{
		std::cout << "Cant't load audio";
		return -1;
	}

	s_background = SDLCommonFunction::LoadImageW("bkg2.jpg", 0, 0, 0xFF, 0xFF);
	if (s_background == NULL) {
		std::cout << "Background can't load" << std::endl;
		return -1;
	}

	SnakeClass Snake;
	Snake.SetRect(100, UNDER_GROUND);
	Snake.LoadImg("earthObjectOptimize.jpg", 7, 7, 7, 255);
	if (Snake.GetObjectW() == NULL)
	{
		std::cout << "Object can't load" << std::endl;
		return -1;
	}
	Snake.InitMeteoritesList();
	Snake.Show(s_screen);

	bool is_quit = false;
	while (!is_quit)
	{
		while (SDL_PollEvent(&s_event))
		{
			if (s_event.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			Snake.HandleInputAction(s_event);
		}
		if (Snake.HandleUplevel() == true) {
			Snake.InitMeteoritesList();
		}
		std::vector<Meteorite> listMeteor = Snake.GetMeteoritesList();

		for (int i = 0; i < Snake.GetMeteoritesList().size(); i++)
		{
			listMeteor[i].CallMetorite();
			Mix_PlayChannel(-1, s_sound_meteorite, 0);
			if (Snake.HitTheEarth(listMeteor[i]) == true)
			{
				is_quit = true;
				std::cout << "Hit" << std::endl;
				break;
			}
			if (Snake.HandleUplevel() == false) {
				if (listMeteor[i].HandleMetorite() == true)
				{
					Snake.SetRestartMeteorite(Snake.GetRestartMeteorite() + 1);
				}
			}
		}
		if (is_quit != true)
		{
			SDLCommonFunction::ApplySurface(s_background, s_screen, 0, 0);
			Snake.Show(s_screen);
			Snake.HandleMove();
			for (int i = 0; i < Snake.GetMeteoritesList().size(); i++)
			{
				listMeteor[i].Show(s_screen);
			}
			std::cout << Snake.GetLevel() << " ";
			Snake.SetMeteoritesList(listMeteor);
			if (SDL_Flip(s_screen) == -1)
				return 0;
		}
		else {
			s_background = SDLCommonFunction::LoadImageW("HitEarthsNew.jpg", 0, 0, 0xFF, 0xFF);
			if (s_background == NULL) {
				std::cout << "HIT can't load" << std::endl;
				return -1;
			}
			int pause_on = 1;
			Mix_FreeChunk(s_sound_meteorite);
			Mix_PlayChannel(-1, s_sound_explosion, 0);
			SDLCommonFunction::ApplySurface(s_background, s_screen, 0, 0);
			SDL_Flip(s_screen);
			SDL_Delay(3000);
		}
	}
	Mix_FreeChunk(s_sound_explosion);
	SDLCommonFunction::CleanUp();
	SDL_Quit();

	return 0;
}