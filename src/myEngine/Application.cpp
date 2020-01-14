#include "Application.h"
#include "Entity.h"
#include "Component.h"

#include "Renderer.h"
#include "ShaderProgram.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Transform.h"
#include "Camera.h"
#include "Environment.h"
#include "Input.h"
#include "Resource.h"
#include "Resources.h"

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
	//---------------------------------------------------------------------------------------------------

	app->device = alcOpenDevice(NULL);

	if (!app->device)
	{
		throw std::exception();
	}

	app->context = alcCreateContext(app->device, NULL);

	if (!app->context)
	{
		alcCloseDevice(app->device);
		throw std::exception();
	}

	if (!alcMakeContextCurrent(app->context))
	{
		alcDestroyContext(app->context);
		alcCloseDevice(app->device);
		throw std::exception();
	}
	
	return app;
}

void Application::run()
{
	running = true;

	float angle = 0.0f;
	int windowWidth = 0;
	int windowHeight = 0;

	for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); ++i)
	{
		(*i)->begin();

	}

	while (running)
	{
		m_time->StartOfFrame();

		SDL_GetWindowSize(window, &windowWidth, &windowHeight);
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);


		if (!m_input->UpdateKeys()) { stop(); }

		if (m_input->IsKeyPressed('w')) { std::cout << "w is pressed! WOOOOOO!" << std::endl; }
		if (m_input->IsKeyReleased('w')) { std::cout << "w is released! WOOOOOO!" << std::endl; }

		if (m_input->IsKeyPressed('a')) { std::cout << "a is pressed! WOOOOOO!" << std::endl; }
		if (m_input->IsKeyReleased('a')) { std::cout << "a is released! WOOOOOO!" << std::endl; }

		if (m_input->IsKeyPressed('s')) { std::cout << "s is pressed! WOOOOOO!" << std::endl; }
		if (m_input->IsKeyReleased('s')) { std::cout << "s is released! WOOOOOO!" << std::endl; }

		if (m_input->IsKeyPressed('d')) { std::cout << "d is pressed! WOOOOOO!" << std::endl; }
		if (m_input->IsKeyReleased('d')) { std::cout << "d is released! WOOOOOO!" << std::endl; }


		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); ++i)
		{
			(*i)->tick();
		}

		glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_mainCamera->UpdateMatrix(windowWidth, windowHeight);

		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); ++i)
		{
			(*i)->display();
			
		}

		SDL_GL_SwapWindow(window);


		// Spin
		std::list<std::shared_ptr<Entity>>::iterator i = entities.begin();
		(*i)->GetTransform()->SetRotation(glm::vec3(0.0f, angle, 0.0f));
		angle += 1.0f;

		m_time->CapFramerate(60.0f);
	}

	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);

	SDL_DestroyWindow(window);
}

void Application::stop()
{
	running = false;
}

float Application::GetDeltaTime()
{
	return m_time->GetDeltaTime(); 
}

std::shared_ptr<Entity> Application::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entity->self = entity;
	entity->application = self;
	entity->transform = entity->addComponent<Transform>();
	entities.push_back(entity);


	return entity;
}