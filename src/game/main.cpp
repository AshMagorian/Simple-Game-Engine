#include <iostream>
#include <glm/ext.hpp>

#include "Camera_FirstPerson.h"

#include <myEngine/Application.h>
#include <myEngine/Component.h>
#include <myEngine/Entity.h>

#include <myEngine/ShaderProgram.h>
#include <myEngine/VertexArray.h>
#include <myEngine/VertexBuffer.h>
#include <myEngine/Texture.h>

#include <myEngine/Renderer.h>
#include <myEngine/Transform.h>
#include <myEngine/Camera.h>

#include <myEngine/stb_image.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[])
{
	std::shared_ptr<Application> application = Application::init();


	std::shared_ptr<VertexArray> triangleVA = std::make_shared<VertexArray>("../src/resources/untitled.obj");


	std::shared_ptr<Texture> texture = std::make_shared<Texture>("../src/resources/yellow.png");

	std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>("../src/myEngine/shaders/simpleTex.vert", "../src/myEngine/shaders/simpleTex.frag");

	std::shared_ptr<Entity> triangle = application->addEntity();
	triangle->addComponent<Renderer>(shaderProgram, triangleVA, texture);
	triangle->GetTransform()->SetPos(glm::vec3(0.0f, 0.0f, -2.5f));

	//Camera setup

	std::shared_ptr<Entity> firstPersonCamera = application->addEntity();
	firstPersonCamera->addComponent<Camera_FirstPerson>();
	firstPersonCamera->GetTransform()->SetPos(glm::vec3(0.0f, 0.0f, 10.0f));

	application->GetCamera()->SetCurrentCamera(firstPersonCamera);


	application->run();

  return 0;
}

