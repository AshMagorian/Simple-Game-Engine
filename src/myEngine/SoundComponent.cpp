#include "SoundComponent.h"
#include "myEngine.h"

void SoundComponent::onInit(std::shared_ptr<Sound> _sound)
{
	m_soundSource = _sound;
}

void SoundComponent::onBegin()
{

}

void SoundComponent::onTick()
{
	if (m_isPlaying == true)
	{
		Play();
		m_isPlaying = false;
	}
}

void SoundComponent::Play()
{
	ALuint sid = 0;
	alGenSources(1, &sid);
	alListener3f(AL_POSITION,	getApplication()->GetCamera()->GetCurrentCamera()->GetTransform()->GetPos().x,
								getApplication()->GetCamera()->GetCurrentCamera()->GetTransform()->GetPos().y, 
								getApplication()->GetCamera()->GetCurrentCamera()->GetTransform()->GetPos().z );
	alSource3f(sid, AL_POSITION, getEntity()->GetTransform()->GetPos().x, 
								 getEntity()->GetTransform()->GetPos().y, 
								 getEntity()->GetTransform()->GetPos().z);
	alSourcei(sid, AL_BUFFER, m_soundSource->GetId());
	alSourcePlay(sid);

}