#include "CommonFunction.h"
#include "Human.h"
#include "F0.h"
#include "Boss.h"
bool Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)  return false;
	s_screen = SDL_SetVideoMode(SCREEN_LENGTH, SCREEN_WIDTH, SCREEN_BPP, SDL_SWSURFACE);
	if (s_screen == NULL)	return false;
	return true;
}

int main() {
	// Init
	if (Init() != true)
	{
		return -1;
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return -1;
	}
	// Load sound
	s_sound_explosion = Mix_LoadWAV("Sound//ExplosionSound.wav");
	s_sound_bullet = Mix_LoadWAV("Sound//Bullet.wav");
	s_sound_hit_boss = Mix_LoadWAV("Sound//HittingBoss.wav");

	if (s_sound_explosion == NULL || s_sound_bullet == NULL)
	{
		std::cout << "Cant't load audio";
		return -1;
	}
	// Load background
	s_background = SDLCommonFunction::LoadImageW("Pictrue//Background.jpg", 0, 0, 0xFF, 0xFF);
	if (s_background == NULL) {
		std::cout << "Background can't load" << std::endl;
		return -1;
	}

	// Load Earth
	Human Earth;
	Earth.SetRect(INIT_HUMAN_LOCATION_X, INIT_HUMAN_LOCATION_Y);
	Earth.LoadImg("Pictrue//Human.png", 249, 223, 132, 255);
	if (Earth.GetObjectW() == NULL)
	{
		std::cout << "Object can't load" << std::endl;
		return -1;
	}
	Boss Virut;
	Virut.SetRect(INIT_BOSS_LOCATION_X, INIT_BOSS_LOCATION_Y);
	Virut.LoadImg("Pictrue//Virut.png", 248, 251, 250, 255);
	if (Virut.GetObjectW() == NULL)
	{
		std::cout << "Boss can't load" << std::endl;
		return -1;
	}
	Virut.CreateEquation();
	Earth.SetBoss(Virut);

	Earth.Show(s_screen);
	Virut.Show(s_screen);

	bool is_quit = false;
	int spaceBulletFire = 0;
	int spaceF0Fire = 0;
	bool removeAllF0 = false;

	while (!is_quit)
	{
		
		while (SDL_PollEvent(&s_event))
		{
			if (s_event.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			Earth.HandleInputAction(s_event);
		}
		
		// Sound of bullet
		Mix_FreeChunk(s_sound_bullet);
		s_sound_bullet = Mix_LoadWAV("Sound//Bullet.wav");
		Mix_PlayChannel(-1, s_sound_bullet, 0);


		// Counter
		spaceBulletFire++;
		spaceF0Fire++;
		SDLCommonFunction::ApplySurface(s_background, s_screen, 0, 0);

		// Boss action
		if (Virut.HandleBoss() == true)
		{
			Virut.CreateEquation();
		}
		Virut.CallBoss();

		// F0 Action
		if (spaceF0Fire == 50)
		{
			Virut = Earth.GetBoss();
			Virut.FireF0();
			spaceF0Fire = 0;
			
		}
		std::vector<F0*> f0List = Virut.GetFoList();
		for (int i = 0; i < f0List.size(); i++)
		{
			if (removeAllF0 == true)
			{
				f0List.erase(f0List.begin() + i);
			}
			else {
				f0List[i]->CallF0();
				f0List[i]->Show(s_screen);
				if (SDLCommonFunction::CollisionCheck(Earth.GetRect(), f0List[i]->GetRect(), HEIGHT_MAIN_OBJECT / 2, METEORITE_WIDGHT, METEORITE_HEIGHT) == true) {
					is_quit = true;
					break;
				}
				else if (f0List[i]->HandelF0() == true)
				{
					f0List.erase(f0List.begin() + i);
				}
			}
		}
		removeAllF0 = false;

		// Bullet action
		if (spaceBulletFire == 8)
		{
			Earth.FireBullet();
			spaceBulletFire = 0;
		}
		std::vector<Bullet*> bulletList = Earth.GetBulletList();
		for (int i = 0; i < bulletList.size(); i++)
		{
			bulletList[i]->CallBullet();
			bulletList[i]->Show(s_screen);

			if (bulletList[i]->HandleBullet() == true) {
				bulletList.erase(bulletList.begin() + i);
			}
			else if (SDLCommonFunction::CollisionCheck(Virut.GetRect(), bulletList[i]->GetRect(), BOSS_WIDGHT / 2, BULLET_WIDGHT, BULLET_HEIGHT) == true) {
				s_sound_hit_boss = Mix_LoadWAV("Sound//HittingBoss.wav");
				Mix_PlayChannel(-1, s_sound_hit_boss, 0);
		
				std::cout << Virut.GetHeal() << " ";
				bulletList.erase(bulletList.begin() + i);
				if (Virut.BossIsDie() == true) {
					is_quit = true;
					break;
				}
			}

		}
			
		// Rocket action
		std::vector<Rocket*> rocketList = Earth.GetRocketList();
		for (int i = 0; i < rocketList.size(); i++)
		{
			rocketList[i]->CallRocket();
			rocketList[i]->Show(s_screen);

			if (rocketList[i]->HandleRocket() == true) {
				rocketList.erase(rocketList.begin() + i);
				// Call explosion sound 
				Mix_PlayChannel(-1, s_sound_explosion, 0);
				removeAllF0 = true;
			}

		}

		Earth.SetRocketList(rocketList);
		Earth.SetBulletList(bulletList);
		Virut.SetF0List(f0List);
		Earth.SetBoss(Virut);
		// Show
		Virut.Show(s_screen);
		Earth.Show(s_screen);
		Earth.HandleMove();
		if (SDL_Flip(s_screen) == -1)
			return 0;
		
		if (is_quit == true) {
			s_background = SDLCommonFunction::LoadImageW("Pictrue//HittingEarths.jpg", 0, 0, 0xFF, 0xFF);
			if (s_background == NULL) {
				std::cout << "HIT can't load" << std::endl;
				return -1;
			}
			// Free meteo sound to end
			Mix_FreeChunk(s_sound_bullet);
			// Call sound of Explosion
			Mix_PlayChannel(-1, s_sound_explosion, 0);

			SDLCommonFunction::ApplySurface(s_background, s_screen, 0, 0);
			SDL_Flip(s_screen);
			//Stop screen 3s
			SDL_Delay(3000);
		}
	}
	Mix_FreeChunk(s_sound_explosion);


	// Clean
	SDLCommonFunction::CleanUp();
	SDL_Quit();

	return 0;
}