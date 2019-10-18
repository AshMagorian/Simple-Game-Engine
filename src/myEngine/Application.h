#include <memory>
#include <list>

class Entity;

class Application
{
public:
	Application();
	~Application();

	std::shared_ptr<Application> const init();
	void run();

	std::shared_ptr<Entity> addEntity();

private:
	std::list<std::shared_ptr<Entity>> entities;
};