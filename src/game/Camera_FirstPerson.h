#include <myEngine/Component.h>

class Camera_FirstPerson : public Component
{
private:
	float m_viewAngle = 45.0f;
public:
	Camera_FirstPerson() {}
	~Camera_FirstPerson() {}

	void onTick();
};