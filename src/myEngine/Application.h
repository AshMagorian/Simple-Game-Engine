#include <memory>
#include <list>

#include <GL/glew.h>
#include <SDL2/SDL.h>


class Entity;
class ShaderProgram;
class VertexArray;

class Application
{
public:
	Application();
	~Application();

	static std::shared_ptr<Application> const init();
	
	void run();
	void stop();

	std::shared_ptr<Entity> addEntity();

private:
	bool running;
	std::list<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Application> self;

	SDL_Window *window;


};