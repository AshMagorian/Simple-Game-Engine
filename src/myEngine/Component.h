#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include <string>

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

	std::string GetId() { return m_id; }

private:
	std::weak_ptr<Entity> entity;
	bool began;

	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();

protected: 
	std::string m_id;

};
#endif