#ifndef SOUND_H
#define SOUND_H

#include <vector>
#include <AL/al.h>

#include "Resource.h"

class Sound : public Resource
{
private:
	ALuint id;

public:
	Sound(std::string _path);
	~Sound() { alDeleteBuffers(1, &id); }

	void Load(std::string _path);

	void LoadOggFile(const std::string& fileName, std::vector<char>& buffer,
		ALenum &format, ALsizei &freq);

	ALuint GetId() { return id; }
};
#endif