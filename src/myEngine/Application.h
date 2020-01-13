#include <memory>
#include <list>

#include <GL/glew.h>
#include <SDL2/SDL.h>


class Entity;
class ShaderProgram;
class VertexArray;
class Camera;
class Environment;
class Input;

class Application
{
public:
	Application();
	~Application();

	static std::shared_ptr<Application> const init();
	
	void run();
	void stop();

	std::shared_ptr<Camera> GetCamera() { return m_mainCamera; }
	std::shared_ptr<Input> GetInput() { return m_input; }
	float GetDeltaTime();

	std::shared_ptr<Entity> addEntity();

private:
	bool running;
	std::list<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Application> self;

	std::shared_ptr<Camera> m_mainCamera = std::make_shared<Camera>();
	std::shared_ptr<Environment> m_time = std::make_shared<Environment>();
	std::shared_ptr<Input> m_input = std::make_shared<Input>();

	SDL_Window *window;


};