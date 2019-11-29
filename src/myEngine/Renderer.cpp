#include "Renderer.h"
#include "ShaderProgram.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::onInit(std::shared_ptr<ShaderProgram> _shader, std::shared_ptr<VertexArray> _va)
{
	m_id = "Renderer";

	m_shaderProgram = _shader;
	m_va = _va;

}

void Renderer::onDisplay()
{
	m_shaderProgram->Draw(m_va);
}
