#include "Transform.h"

void Transform::onInit()
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

glm::mat4 Transform::GetModelMatrix()
{
	m_model = glm::mat4(1.0f);

	//change model by transforms

	return m_model;
}