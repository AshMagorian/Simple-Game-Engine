#include <myEngine/Component.h>

class Transform;
class Input;

class Camera_FirstPerson : public Component
{
private:
	float m_viewAngle = 45.0f;
	std::shared_ptr<Transform> m_Transform;
	std::shared_ptr<Input> m_Input;

	float m_movementSpeed = 0.1f;

public:
	Camera_FirstPerson() {}
	~Camera_FirstPerson() {}

	void onBegin();
	void onTick();
};