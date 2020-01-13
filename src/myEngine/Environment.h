#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <SDL2/SDL.h>

class Environment
{
private:
	unsigned int m_currentTime;
	unsigned int m_lastTime;
	float m_deltaTime ;

public:
	Environment::Environment() {}

	void StartOfFrame();
	void CapFramerate(float _framerate);

	float GetDeltaTime() { return m_deltaTime; }
};
#endif