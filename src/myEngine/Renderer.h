#include "Component.h"
#include "glm/glm.hpp"

#include <iostream>


class ShaderProgram;
class VertexArray;
class Texture;

class Renderer : public Component
{
private:

	std::shared_ptr<ShaderProgram> m_shaderProgram;
	std::shared_ptr<VertexArray> m_va;
	std::shared_ptr<Texture> m_tex;

public:
	Renderer();
	~Renderer();

	void onInit(std::shared_ptr<ShaderProgram> _shader, std::shared_ptr<VertexArray> _va, std::shared_ptr<Texture> _tex);
	void onDisplay();

	void SayHi() { std::cout << "renderer says hi" << std::endl; }

};