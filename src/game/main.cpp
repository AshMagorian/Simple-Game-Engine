#include <iostream>

#include <myEngine/Application.h>
#include <myEngine/Component.h>
#include <myEngine/Entity.h>

#include <myEngine/ShaderProgram.h>
#include <myEngine/VertexArray.h>
#include <myEngine/VertexBuffer.h>
#include <myEngine/Renderer.h>
#include <myEngine/Transform.h>


int main(int argc, char *argv[])
{
	std::shared_ptr<Application> application = Application::init();


	std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
	positions->add(glm::vec3(-0.5f, 0.5f, 0.0f));
	positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
	positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

	std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
	colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	colors->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	colors->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	std::shared_ptr<VertexArray> triangleVA = std::make_shared<VertexArray>();
	triangleVA->SetBuffer("in_Position", positions);
	triangleVA->SetBuffer("in_Color", colors);

	std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>("../src/myEngine/shaders/simple.vert", "../src/myEngine/shaders/simple.frag");

	std::shared_ptr<Entity> triangle = application->addEntity();
	std::shared_ptr<Renderer> tRenderer = triangle->addComponent<Renderer>(shaderProgram, triangleVA);

	triangle->GetComponent<Renderer>()->SayHi();
	triangle->GetTransform()->SayHi();

	std::shared_ptr<Entity> camera = application->addEntity();


	application->run();

  return 0;
}

