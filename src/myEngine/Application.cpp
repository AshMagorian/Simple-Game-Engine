#include "Application.h"
#include "Entity.h"
#include "Component.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


Application::Application()
{

}

Application::~Application()
{

}

std::shared_ptr<Application> const Application::init()
{
	std::shared_ptr<Application> app = std::make_shared<Application>();
	app->running = false;
	app->self = app;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}
	
	app->window = SDL_CreateWindow("my game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	
	if (!SDL_GL_CreateContext(app->window))
	{
		throw std::exception();
	}
	
	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	return app;
}

void Application::run()
{
	running = true;

	while (running)
	{

		SDL_Event event = { 0 };
		
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				stop();
			}
		}

		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); ++i)
		{
			(*i)->tick();
		}

		glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); ++i)
		{
			(*i)->display();
			
		}

		SDL_GL_SwapWindow(window);
	}
}

void Application::stop()
{
	running = false;
}

std::shared_ptr<Entity> Application::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.push_back(entity);
	entity->self = entity;
	entity->application = self;

	return entity;
}