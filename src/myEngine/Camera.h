#include "Component.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Camera 
{
private:

	float m_viewAngle;

	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;

	std::shared_ptr<Entity> m_currentCamera;

public:
	Camera();
	~Camera();

	void UpdateMatrix(int _w, int _h);

	void SetViewAngle(float _angle) { m_viewAngle = _angle; }
	void SetCurrentCamera(std::shared_ptr<Entity> _cam) { m_currentCamera = _cam; }
	std::shared_ptr<Entity> GetCurrentCamera() { return m_currentCamera; }

	glm::mat4 GetViewMatrix() { return m_viewMatrix; }
	glm::mat4 GetProjectionMatrix() { return m_projectionMatrix; }
};