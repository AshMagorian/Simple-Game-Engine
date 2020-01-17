#include <myEngine/Component.h>

class Transform;
class Input;
/**
*This Component is the camera which the Camera object stored in teh engine uses as a reference. It gets the transform from this object
*/
class Camera_FirstPerson : public Component
{
private:
	std::shared_ptr<Transform> m_Transform; ///< The transform component 
	std::shared_ptr<Input> m_Input; ///< The input component of the engine

	glm::vec3 m_forwardVector; ///< A vector which always points in the direction the camera is facing
	glm::vec3 m_rightVector; ///< A vector which points to the rigth of where the camera is facing

	float m_movementSpeed = 10.0f; ///< The speed in which the player moves forward
	float m_rotationSpeed = 80.0f; ///< How quickly the player turns

public:
	Camera_FirstPerson() {}
	~Camera_FirstPerson() {}
	/**
	*\brief called on the first frame
	*/
	void onBegin();
	/**
	*\brief called every frame
	*/
	void onTick();
};