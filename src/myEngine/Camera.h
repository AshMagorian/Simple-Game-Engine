#include "Component.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Camera : public Component
{
private:

	float m_windowHeight;
	float m_windowWidth;
	float m_viewAngle;

	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;

public:
	Camera();
	~Camera();

	void onInit(float _h, float _w, float _angle);

	void onTick();

	glm::mat4 GetViewMatrix() { return m_viewMatrix; }
	glm::mat4 GetProjectionMatrix() { return m_projectionMatrix; }
};