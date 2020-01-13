#include "Entity.h"
#include "Application.h"
#include "Component.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

std::shared_ptr<Application> Entity::getApplication()
{
	return application.lock();
}

void Entity::tick()
{
	for (std::list < std::shared_ptr<Component>>::iterator i = components.begin(); i != components.end(); ++i)
	{
		if ((*i)->began == false)
		{
			(*i)->onBegin();
			(*i)->began = true;
		}
		(*i)->onTick();
	}
}

void Entity::display()
{
	for (std::list<std::shared_ptr<Component>>::iterator i = components.begin(); i != components.end(); ++i)
	{
		(*i)->onDisplay();
	}
}

void Entity::begin()
{
	for (std::list<std::shared_ptr<Component>>::iterator i = components.begin(); i != components.end(); ++i)
	{
		(*i)->onBegin();
	}
}