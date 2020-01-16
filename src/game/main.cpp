#include <myEngine/myEngine.h>

#include "Camera_FirstPerson.h"
#include "SoundToggle.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[])
{
	//"../src/resources/models/untitled.obj"
	
	std::shared_ptr<Application> application = Application::init();


	application->GetResourceManager()->CreateResource<Texture>("../src/resources/textures/yellow.png");

	std::shared_ptr<Entity> box1 = application->MakeCube();

	//box1->GetComponent<Renderer>()->SetTexture(application->GetResourceManager()->LoadFromResources<Texture>("../src/resources/textures/yellow.png"));
	box1->GetTransform()->SetPos(glm::vec3(0.0f, 0.0f, -2.5f));

	//Camera setup
	std::shared_ptr<Entity> firstPersonCamera = application->addEntity();
	firstPersonCamera->addComponent<Camera_FirstPerson>();
	firstPersonCamera->GetTransform()->SetPos(glm::vec3(0.0f, 0.0f, 10.0f));
	application->GetCamera()->SetCurrentCamera(firstPersonCamera);

	// Sound setup
	application->GetResourceManager()->CreateResource<Sound>("../src/resources/audio/dixie_horn.ogg");
	box1->addComponent<SoundComponent>(application->GetResourceManager()->LoadFromResources<Sound>("../src/resources/audio/dixie_horn.ogg"));
	box1->addComponent<SoundToggle>();

	box1->addComponent<BoxCollider>();
	firstPersonCamera->addComponent<BoxCollider>();

	application->run();
	


  return 0;
}

