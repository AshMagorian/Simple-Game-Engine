#include "SoundToggle.h"
#include <myEngine/myEngine.h>

void SoundToggle::onTick()
{
	if (getApplication()->GetInput()->IsKeyPressed(' '))
	{
		getEntity()->GetComponent<SoundComponent>()->SetIsPlaying(true);
	}
}