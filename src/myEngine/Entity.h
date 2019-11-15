#include <memory>
#include <list>

class Application;
class Component;

class Entity
{
	friend class Application;

public:
	Entity();
	~Entity();

	std::shared_ptr<Application> getApplication();

	template <typename T, typename... A>
	std::shared_ptr<T> addComponent(A... args)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->entity = self;
		rtn->began = false;
		components.push_back(rtn);

		rtn->onInit(args...);

		return rtn;
	}

private:
	std::weak_ptr<Application> application;
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Entity> self;

	void tick();
	void display();
};