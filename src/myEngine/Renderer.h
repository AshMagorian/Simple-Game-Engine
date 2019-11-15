#include "Component.h"
#include "glm/glm.hpp"


class ShaderProgram;
class VertexArray;

class Renderer : public Component
{
private:

	std::shared_ptr<ShaderProgram> m_shaderProgram;
	std::shared_ptr<VertexArray> m_va;

	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;

public:
	Renderer();
	~Renderer();

	void onInit(std::shared_ptr<ShaderProgram> _shader, std::shared_ptr<VertexArray> _va, glm::vec3 _pos, glm::vec3 _rotation, glm::vec3 _scale);
	void onDisplay();

	glm::vec3 GetPos() { return m_position; }
	glm::vec3 GetRotation() { return m_rotation; }
	glm::vec3 GetScale() { return m_scale; }

protected:
	glm::mat4 m_model;
};