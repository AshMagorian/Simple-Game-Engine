#include <memory>
#include <list>

class Application;
class Component;

class Entity
{
public:
	Entity();
	~Entity();

	std::shared_ptr<Application> getApplication();
	void tick();
	void display();
	std::shared_ptr<Component> addComponent();

private:
	std::weak_ptr<Application> application;
	std::list<std::shared_ptr<Component>> components;
};