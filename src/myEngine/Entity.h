#include <memory>
#include <list>
#include <string>
#include <algorithm>

class Application;
class Component;
class Transform;

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

	template <typename T>
	std::shared_ptr<T> GetComponent()
	{
		std::shared_ptr<T> rtn;

		for (std::list<std::shared_ptr<Component>>::iterator i = components.begin(); i != components.end(); ++i)
		{
			rtn = std::dynamic_pointer_cast<T>(*i);
			if (rtn)
			{
				return rtn;
			}
		}

		throw std::exception();
	}

	std::shared_ptr<Transform> GetTransform()
	{
		return transform.lock();
	}

private:
	std::weak_ptr<Application> application;
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Entity> self;
	std::weak_ptr<Transform> transform;

	void begin();
	void tick();
	void display();
};