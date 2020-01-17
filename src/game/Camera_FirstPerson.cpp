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
	// rotate it by angle (the camera’s Y rotation)
	t = glm::rotate(t, glm::radians(m_Transform->GetRotation().y), glm::vec3(0, 1, 0));
	// move forward 1 unit
	t = glm::translate(t, glm::vec3(0, 0, 1));
	// apply to an initial position
	m_forwardVector = t * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	// normalize to get the unit vector
	m_forwardVector = glm::normalize(m_forwardVector);


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
		m_Transform->SetRotation(m_Transform->GetRotation() + glm::vec3(0.0f, (m_rotationSpeed * getApplication()->GetDeltaTime()), 0.0f));
		//m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * getApplication()->GetDeltaTime() * -glm::vec3(1.0f, 0.0f, 0.0f)));
	}
	if (m_Input->IsKey('d')) // rotate right
	{

		m_Transform->SetRotation(m_Transform->GetRotation() + glm::vec3(0.0f, -(m_rotationSpeed * getApplication()->GetDeltaTime()), 0.0f));
		//m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * getApplication()->GetDeltaTime() * glm::vec3(1.0f, 0.0f, 0.0f)));
	} 

}