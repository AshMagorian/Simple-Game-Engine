#ifndef APPLICATION_H
#define APPLICATION_H
#include <memory>
#include <list>

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <AL/al.h>
#include <AL/alc.h>

#include <vector>

class Entity;
class ShaderProgram;
class VertexArray;
class Camera;
class Environment;
class Input;
class Resources;
class Resource;

class Application
{
private:
	bool running;
	std::list<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Application> self;

	std::shared_ptr<Camera> m_mainCamera = std::make_shared<Camera>();
	std::shared_ptr<Environment> m_time = std::make_shared<Environment>();
	std::shared_ptr<Input> m_input = std::make_shared<Input>();
	std::shared_ptr <Resources> m_resourceManager = std::make_shared<Resources>();

	SDL_Window *window;
	ALCdevice* device;
	ALCcontext* context;

public:
	Application();
	~Application();

	static std::shared_ptr<Application> const init();

	void run();
	void stop();

	std::shared_ptr<Camera> GetCamera() { return m_mainCamera; }
	std::shared_ptr<Input> GetInput() { return m_input; }
	std::shared_ptr<Resources> GetResourceManager() { return m_resourceManager; }
	float GetDeltaTime();

	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<Entity> MakeCube();

	template <typename T>
	void GetEntities(std::vector<std::shared_ptr<Entity>> &_entities)
	{
		std::shared_ptr<T> testComponent;
		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); ++i)
		{
			std::list<std::shared_ptr<Component>> components = (*i)->GetComponents();
			for (std::list<std::shared_ptr<Component>>::iterator j = components.begin(); j != components.end(); ++j)
			{
				testComponent = std::dynamic_pointer_cast<T>(*j);
				if (testComponent)
				{
					_entities.push_back(*i);
					testComponent = NULL;
				}
			}
		}
	}




};
#endif