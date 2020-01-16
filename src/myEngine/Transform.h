#include "Component.h"
#include "glm/glm.hpp"

#include <iostream>

class Transform : public Component
{
private:

	glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);

public:

	Transform() {}
	~Transform() {}

	void onInit();

	glm::vec3 GetPos() { return m_position; }
	glm::vec3 GetRotation() 
	{
		if (m_rotation.x < 500.0f && m_rotation.x > -500.0f && m_rotation.y < 500.0f && m_rotation.y > -500.0f && m_rotation.z < 500.0f && m_rotation.z > -500.0f)
		{
			return m_rotation;
		}
		return glm::vec3(0.0f, 0.0f, 0.0f);
	}
	glm::vec3 GetScale() { return m_scale; }

	void SetPos(glm::vec3 _pos) { m_position = _pos; }
	void SetRotation(glm::vec3 _rot) { m_rotation = _rot; }
	void SetScale(glm::vec3 _sca) { m_scale = _sca; }

	glm::mat4 GetModelMatrix();

	void SayHi() { std::cout << "transform says hi" << std::endl; }

protected:
	glm::mat4 m_model;
};