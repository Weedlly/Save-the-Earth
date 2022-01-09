#ifndef SnakeClass_h
#define SnakeClass_h

#include "BaseClass.h"
#include "Meteorite.h"
#define HEIGHT_MAIN_OBJECT 40
#define WIDTH_MAIN_OBJECT 40
class SnakeClass : public BaseClass
{
public:
	SnakeClass();
	~SnakeClass();
	void HandleInputAction(SDL_Event event);
	void HandleMove();
	bool HandleUplevel();
	void InitMeteoritesList();
	bool HitTheEarth(Meteorite& meteorite);

	int GetLevel() { return _level; }
	void SetRestartMeteorite(int val) { _restartMeteorites = val; }
	void SetMeteoritesList(std::vector<Meteorite> meteorites) { _meteorites = meteorites; }
	int GetRestartMeteorite() { return _restartMeteorites; }
	std::vector<Meteorite> GetMeteoritesList() { return _meteorites; }
private:
	std::vector<Meteorite> _meteorites;
	int x_val_;
	int y_val_;
	int _restartMeteorites;
	int _level;
};
#endif // !SnakeClass
