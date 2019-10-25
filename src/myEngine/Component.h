#include <memory>

class Entity;
class Application;

class Component
{
	friend class Entity;

public:
	Component();
	virtual ~Component();

	std::shared_ptr<Entity> getEntity();

	std::shared_ptr<Application> getApplication();

private:
	std::weak_ptr<Entity> entity;
	bool began;

	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();

};