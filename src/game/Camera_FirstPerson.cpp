#include <myEngine/myEngine.h>
#include "Camera_FirstPerson.h"

#include <glm/ext.hpp>
#include <iostream>
/**
*\brief Sets the transform and input variables
*/
void Camera_FirstPerson::onBegin()
{
	m_Transform = getEntity()->GetTransform();
	m_Input = getApplication()->GetInput();
}
/**
*\brief Calculates the forward vector and then updates the position by checking if the wasd keys are pressed
*/
void Camera_FirstPerson::onTick()
{
	// create arbitary matrix
	glm::mat4 t(1.0f);

	//// rotate it by angle (the camera’s Y rotation)
	//t = glm::rotate(t, glm::radians(m_Transform->GetRotation().y), glm::vec3(0, 1, 0));
	//// move forward 1 unit
	//t = glm::translate(t, glm::vec3(0, 0, 1));
	//// apply to an initial position
	//m_forwardVector = t * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	//// normalize to get the unit vector
	//m_forwardVector = glm::normalize(m_forwardVector);


	m_upVector = glm::vec3(0.0f, 1.0f, 0.0f);
	  // Calculate the new Front vector
	m_forwardVector.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_forwardVector.y = sin(glm::radians(m_pitch));
	m_forwardVector.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_forwardVector = glm::normalize(m_forwardVector);
	// Also re-calculate the Right and Up vector
	m_rightVector = glm::normalize(glm::cross(m_forwardVector, m_upVector));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	m_upVector = glm::normalize(glm::cross(m_rightVector, m_forwardVector));

	if (m_Input->IsKey('w'))
	{
		m_Transform->SetPos(m_Transform->GetPos() - (m_movementSpeed * getApplication()->GetDeltaTime() * m_forwardVector));
	}
	if (m_Input->IsKey('s'))
	{
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * getApplication()->GetDeltaTime() * m_forwardVector));
	}
	if (m_Input->IsKey('a')) // rotate left
	{
		//m_Transform->SetRotation(m_Transform->GetRotation() + glm::vec3(0.0f, (m_rotationSpeed * getApplication()->GetDeltaTime()), 0.0f));
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * getApplication()->GetDeltaTime() * m_rightVector));
	}
	if (m_Input->IsKey('d')) // rotate right
	{
		//m_Transform->SetRotation(m_Transform->GetRotation() + glm::vec3(0.0f, -(m_rotationSpeed * getApplication()->GetDeltaTime()), 0.0f));
		m_Transform->SetPos(m_Transform->GetPos() - (m_movementSpeed * getApplication()->GetDeltaTime() * m_rightVector));
	} 
	m_yaw -= m_Input->GetDeltaMouseX() * getApplication()->GetDeltaTime();
	m_pitch -= m_Input->GetDeltaMouseY() * getApplication()->GetDeltaTime();
	std::cout << "yaw: " << m_yaw << std::endl;
	std::cout << "pitch: " << m_pitch << std::endl;
	std::cout << "delta x: " << m_Input->GetDeltaMouseX() << std::endl;
	std::cout << "delta y: " << m_Input->GetDeltaMouseY() << std::endl;


	
}