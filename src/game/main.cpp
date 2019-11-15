#include <iostream>

#include <myEngine/Application.h>
#include <myEngine/Component.h>
#include <myEngine/Entity.h>


class TriangleRenderer : public Component
{
	void onDisplay()
	{
		//std::cout << "Hello Triangle" << std::endl;
	}
};

int main(int argc, char *argv[])
{
	std::shared_ptr<Application> application = Application::init();
	application->MakeObjects();

	std::shared_ptr<Entity> entity = application->addEntity();
	std::shared_ptr<TriangleRenderer> triangle1 = entity->addComponent<TriangleRenderer>();

	application->run();

  return 0;
}