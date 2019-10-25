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
	void stop();

	std::shared_ptr<Entity> addEntity();

private:
	bool running;
	std::list<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Application> self;
};