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
		d = 100,
		space = 32
	};

	std::vector<int> m_keys;
	std::vector<int> m_pressedKeys;
	std::vector<int> m_releasedKeys;

	int m_deltaMouseX;
	int m_deltaMouseY;
	int m_mouseX;
	int m_mouseY;

	SDL_Event event = { 0 };

	bool m_quit = false;

public:

	Input() {}

	bool UpdateKeys();

	bool IsKey(char _key);
	bool IsKeyPressed(char _key);
	bool IsKeyReleased(char _key);
	int GetDeltaMouseX() { return m_deltaMouseX; }
	int GetDeltaMouseY() { return m_deltaMouseY; }
	void ClearKeys();

};