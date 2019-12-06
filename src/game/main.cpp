#include <iostream>
#include <glm/ext.hpp>

#include <myEngine/Application.h>
#include <myEngine/Component.h>
#include <myEngine/Entity.h>

#include <myEngine/ShaderProgram.h>
#include <myEngine/VertexArray.h>
#include <myEngine/VertexBuffer.h>
#include <myEngine/Texture.h>

#include <myEngine/Renderer.h>
#include <myEngine/Transform.h>

#include <myEngine/stb_image.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[])
{
	std::shared_ptr<Application> application = Application::init();

	std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
	positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
	positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
	positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

	std::shared_ptr<VertexBuffer> texCoords = std::make_shared<VertexBuffer>();
	texCoords->add(glm::vec2(0.5f, 0.0f));
	texCoords->add(glm::vec2(0.0f, 1.0f));
	texCoords->add(glm::vec2(1.0f, 1.0f));

	//std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
	//colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	//colors->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	//colors->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	std::shared_ptr<VertexArray> triangleVA = std::make_shared<VertexArray>();
	triangleVA->SetBuffer("in_Position", positions);
	triangleVA->SetBuffer("in_TexCoord", texCoords);
	//triangleVA->SetBuffer("in_Color", colors);

	std::shared_ptr<Texture> texture = std::make_shared<Texture>("../src/resources/yellow.png");

	std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>("../src/myEngine/shaders/simple.vert", "../src/myEngine/shaders/simple.frag");
	shaderProgram->SetUniform("in_Projection", glm::perspective(glm::radians(45.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f));

	std::shared_ptr<Entity> triangle = application->addEntity();
	std::shared_ptr<Renderer> tRenderer = triangle->addComponent<Renderer>(shaderProgram, triangleVA, texture);

	triangle->GetTransform()->SetPos(glm::vec3(0.0f, 0.0f, -2.5f));

	triangle->GetComponent<Renderer>()->SayHi();
	triangle->GetTransform()->SayHi();

	std::shared_ptr<Entity> camera = application->addEntity();


	application->run();

  return 0;
}

