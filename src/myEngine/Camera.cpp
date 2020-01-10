#include "Camera.h"
#include "Component.h"
#include "Transform.h"
#include "Entity.h"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::onInit(float _h, float _w, float _angle)
{
	m_windowHeight = _h;
	m_windowWidth = _w;
	m_viewAngle = _angle;
}

void Camera::onTick()
{
	m_projectionMatrix = glm::perspective(glm::radians(m_viewAngle),
		m_windowWidth / m_windowHeight, 0.1f, 100.f);
	m_viewMatrix = glm::inverse(getEntity()->GetTransform()->GetModelMatrix());
}