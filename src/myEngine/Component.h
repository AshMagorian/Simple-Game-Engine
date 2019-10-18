#include <memory>

class Entity;
class Application;

class Component
{
public:
	Component();
	~Component();

	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Application> getApplication();

	void onInit();
	void onBegin();
	void onTick();
	void onDisplay();

private:
	std::weak_ptr<Entity> entity;

};