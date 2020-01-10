#include "Renderer.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::onInit(std::shared_ptr<ShaderProgram> _shader, std::shared_ptr<VertexArray> _va, std::shared_ptr<Texture> _tex)
{
	m_id = "Renderer";

	m_shaderProgram = _shader;
	m_va = _va;
	m_tex = _tex;

}

void Renderer::onTick()
{
	//m_shaderProgram->setUniform("in_Projection", )
}

void Renderer::onDisplay()
{

	m_shaderProgram->SetUniform("in_Model", getEntity()->GetTransform()->GetModelMatrix());
	m_shaderProgram->SetUniform("in_Texture", m_tex);

	m_shaderProgram->Draw(m_va);
}
