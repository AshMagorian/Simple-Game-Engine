#include "Component.h"
#include "glm/glm.hpp"

#include <iostream>


class ShaderProgram;
class VertexArray;
class Texture;
class Camera;

class Renderer : public Component
{
private:

	std::shared_ptr<ShaderProgram> m_shaderProgram;
	std::shared_ptr<VertexArray> m_va;
	std::shared_ptr<Texture> m_tex;
	std::shared_ptr<Camera> m_mainCamera;

public:
	Renderer();
	~Renderer();

	void onInit() {}
	void onInit(std::shared_ptr<ShaderProgram> _shader, std::shared_ptr<VertexArray> _va, std::shared_ptr<Texture> _tex);
	void onTick();
	void onDisplay();

	void SetMesh(std::shared_ptr<VertexArray> _va) { m_va = _va; }
	void SetTexture(std::shared_ptr<Texture> _tex) { m_tex = _tex; }
	void SetShader(std::shared_ptr<ShaderProgram> _shader) { m_shaderProgram = _shader; }

};