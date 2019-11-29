#include "Component.h"
#include "glm/glm.hpp"

#include <iostream>


class ShaderProgram;
class VertexArray;

class Renderer : public Component
{
private:

	std::shared_ptr<ShaderProgram> m_shaderProgram;
	std::shared_ptr<VertexArray> m_va;

public:
	Renderer();
	~Renderer();

	void onInit(std::shared_ptr<ShaderProgram> _shader, std::shared_ptr<VertexArray> _va);
	void onDisplay();

	void SayHi() { std::cout << "renderer says hi" << std::endl; }

};