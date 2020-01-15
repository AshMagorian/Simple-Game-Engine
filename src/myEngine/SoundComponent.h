#ifndef SOUNDCOMPONENT_H
#define SOUNDCOMPONENT_H
#include "Component.h"

class Sound;

class SoundComponent : public Component
{
private:
	std::shared_ptr<Sound> m_soundSource;
	bool m_isPlaying = false;
public:
	void onInit(std::shared_ptr<Sound> _sound);
	void onTick();
	void onBegin();
	void Play();

	void SetIsPlaying(bool _val) { m_isPlaying = _val; }
};
#endif