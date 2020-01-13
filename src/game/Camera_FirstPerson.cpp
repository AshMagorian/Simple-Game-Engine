#include "Camera_FirstPerson.h"

#include <myEngine/Application.h>
#include <myEngine/Entity.h>
#include <myEngine/Camera.h>
#include <myEngine/Input.h>
#include <myEngine/Transform.h>

void Camera_FirstPerson::onBegin()
{
	m_Transform = getEntity()->GetTransform();
	m_Input = getApplication()->GetInput();
}

void Camera_FirstPerson::onTick()
{
	if (m_Input->IsKey('w'))
	{
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * glm::vec3(0.0f, 0.0f, -1.0f)));
	}
	if (m_Input->IsKey('s'))
	{
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * glm::vec3(0.0f, 0.0f, 1.0f)));
	}
	if (m_Input->IsKey('a'))
	{
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * glm::vec3(-1.0f, 0.0f, 0.0f)));
	}
	if (m_Input->IsKey('d'))
	{
		m_Transform->SetPos(m_Transform->GetPos() + (m_movementSpeed * glm::vec3(1.0f, 0.0f, 0.0f)));
	}
}