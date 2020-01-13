#include <vector>
#include <SDL2/SDL.h>

class Appication;

class Input
{
private:
	enum key 
	{
		//w = (int)'w',
		w = 119,
		a = 97,
		s = 115,
		d = 100
	};

	std::vector<int> m_keys;
	std::vector<int> m_pressedKeys;
	std::vector<int> m_releasedKeys;

	SDL_Event event = { 0 };

	bool m_quit = false;

public:

	Input() {}

	bool UpdateKeys();

	bool IsKey(char _key);
	bool IsKeyPressed(char _key);
	bool IsKeyReleased(char _key);
	void ClearKeys();

};