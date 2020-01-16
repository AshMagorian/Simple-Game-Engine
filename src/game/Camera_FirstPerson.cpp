#include <myEngine/myEngine.h>
#include "Camera_FirstPerson.h"

#include <glm/ext.hpp>
#include <iostream>

void Camera_FirstPerson::onBegin()
{
	m_Transform = getEntity()->GetTransform();
	m_Input = getApplication()->GetInput();
}

void Camera_FirstPerson::onTick()
{
	// Calculate the new Front vector
	//m_forwardVector.x = cos(glm::radians(m_Transform->GetRotation().y)) * cos(glm::radians(m_Transform->GetRotation().x));
	//m_forwardVector.y = sin(glm::radians(m_Transform->GetRotation().x));
	//m_forwardVector.z = sin(glm::radians(m_Transform->GetRotation().y)) * cos(glm::radians(m_Transform->GetRotation().x));
	//m_forwardVector = glm::normalize(m_forwardVector);
	//m_rightVector = glm::normalize(glm::cross(m_forwardVector, glm::vec3(0.0f, 1.0f, 0.0f)));

	if (m_Input->IsKey('w'))
	{
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * getApplication()->GetDeltaTime() * -glm::vec3 (0.0f, 0.0f, 1.0f)));
	}
	if (m_Input->IsKey('s'))
	{
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * getApplication()->GetDeltaTime() * glm::vec3(0.0f, 0.0f, 1.0f)));
	}
	if (m_Input->IsKey('a'))
	{
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * getApplication()->GetDeltaTime() * -glm::vec3(1.0f, 0.0f, 0.0f)));
	}
	if (m_Input->IsKey('d'))
	{
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * getApplication()->GetDeltaTime() * glm::vec3(1.0f, 0.0f, 0.0f)));
	}


	//std::cout << "delta x = " << (float)m_Input->GetDeltaMouseX() * getApplication()->GetDeltaTime() << ", delta y = " << (float)m_Input->GetDeltaMouseY() * getApplication()->GetDeltaTime() << std::endl;

	//m_Transform->SetRotation(m_Transform->GetRotation() +	glm::vec3((float)m_Input->GetDeltaMouseY() * getApplication()->GetDeltaTime(),
	//																(float)m_Input->GetDeltaMouseX() * getApplication()->GetDeltaTime(),
	//																0.0f));

	//std::cout << m_Transform->GetRotation().x << ", " << m_Transform->GetRotation().y << ", " << m_Transform->GetRotation().z << std::endl;

}