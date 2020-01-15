#include <iostream>
#include <glm/ext.hpp>

#include <myEngine/myEngine.h>

#include "Camera_FirstPerson.h"
#include "SoundToggle.h"

#include <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[])
{

	try
	{
		std::shared_ptr<Application> application = Application::init();

		application->GetResourceManager()->CreateResource<VertexArray>("../src/resources/models/untitled.obj");
		application->GetResourceManager()->CreateResource<ShaderProgram>("../src/resources/shaders/simpleTex.txt");
		application->GetResourceManager()->CreateResource<Texture>("../src/resources/textures/yellow.png");

		std::shared_ptr<Entity> triangle = application->addEntity();
		triangle->addComponent<Renderer>(application->GetResourceManager()->LoadFromResources <ShaderProgram>("../src/resources/shaders/simpleTex.txt"),
			application->GetResourceManager()->LoadFromResources<VertexArray>("../src/resources/models/untitled.obj"),
			application->GetResourceManager()->LoadFromResources<Texture>("../src/resources/textures/yellow.png"));
		triangle->GetTransform()->SetPos(glm::vec3(0.0f, 0.0f, -2.5f));

		//Camera setup
		std::shared_ptr<Entity> firstPersonCamera = application->addEntity();
		firstPersonCamera->addComponent<Camera_FirstPerson>();
		firstPersonCamera->GetTransform()->SetPos(glm::vec3(0.0f, 0.0f, 10.0f));
		application->GetCamera()->SetCurrentCamera(firstPersonCamera);

		// Sound setup
		application->GetResourceManager()->CreateResource<Sound>("../src/resources/audio/dixie_horn.ogg");
		triangle->addComponent<SoundComponent>(application->GetResourceManager()->LoadFromResources<Sound>("../src/resources/audio/dixie_horn.ogg"));
		triangle->addComponent<SoundToggle>();

		application->run();
	}
	catch (Exception& e)
	{
		std::cout << "myEngine Exception: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "An unknown object was thrown" << std::endl;
	}

  return 0;
}

