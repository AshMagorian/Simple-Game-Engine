#include "Renderer.h"
#include "ShaderProgram.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::onInit(std::shared_ptr<ShaderProgram> _shader, std::shared_ptr<VertexArray> _va, glm::vec3 _pos, glm::vec3 _rotation, glm::vec3 _scale)
{
	m_shaderProgram = _shader;
	m_va = _va;
	m_position = _pos;
	m_rotation = _rotation;
	m_scale = _scale;
}

void Renderer::onDisplay()
{
	m_shaderProgram->Draw(m_va);
}