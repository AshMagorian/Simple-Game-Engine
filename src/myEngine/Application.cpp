#include "myEngine.h"

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
	try { if (SDL_Init(SDL_INIT_VIDEO) < 0){throw Exception("SDL_VIDEO not initialised");}}
	catch (Exception& e) { std::cout << "myEngine Exception: " << e.what() << std::endl; }

	app->window = SDL_CreateWindow("my game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	
	try { if (!SDL_GL_CreateContext(app->window)) { throw Exception("Window couldn't be created"); } }
	catch (Exception& e) { std::cout << "myEngine Exception: " << e.what() << std::endl; }

	try { if (glewInit() != GLEW_OK) { throw Exception("GLEW couldn't be initialised"); } }
	catch (Exception& e) { std::cout << "myEngine Exception: " << e.what() << std::endl; }

	app->device = alcOpenDevice(NULL);

	try { if (!app->device) { throw Exception("alc OpenDevice failed"); } }
	catch (Exception& e) { std::cout << "myEngine Exception: " << e.what() << std::endl; }

	app->context = alcCreateContext(app->device, NULL);

	try { if (!app->context) { throw Exception("alc CreateContext failed"); } }
	catch (Exception& e) { alcCloseDevice(app->device); std::cout << "myEngine Exception: " << e.what() << std::endl; }

	try { if (!alcMakeContextCurrent(app->context)) { throw Exception("alc MakeContextCurrent failed"); } }
	catch (Exception& e) 
	{ 
		alcDestroyContext(app->context);
		alcCloseDevice(app->device); 
		std::cout << "myEngine Exception: " << e.what() << std::endl; 
	}
	try
	{ 
		if (!app->m_resourceManager)
		{
			throw Exception("Resource manager not loaded"); 
		}
		app->GetResourceManager()->CreateResource<VertexArray>("../src/myEngine/engineRes/Cube.obj");
		app->GetResourceManager()->CreateResource<ShaderProgram>("../src/resources/shaders/simpleTex.txt");
		app->GetResourceManager()->CreateResource<Texture>("../src/myEngine/engineRes/Grey.png");
	}
	catch (Exception& e) { std::cout << "myEngine Exception: " << e.what() << std::endl; }

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

		SDL_WarpMouseInWindow(window, 320, 240); // moves the mouse to the middle of the window
		SDL_ShowCursor(SDL_DISABLE); // Hides the cursor

		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); ++i)
		{
			try
			{
				(*i)->tick();
			} 
			catch (Exception& e) 
			{ 
				std::cout << "myEngine Exception: " << e.what() << std::endl; 
			}
		}

		glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_mainCamera->UpdateMatrix(windowWidth, windowHeight);

		for (std::list<std::shared_ptr<Entity>>::iterator i = entities.begin(); i != entities.end(); ++i)
		{
			(*i)->display();
		}

		SDL_GL_SwapWindow(window);

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

std::shared_ptr<Entity> Application::MakeCube()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entity->self = entity;
	entity->application = self;
	entity->transform = entity->addComponent<Transform>();
	entity->addComponent<Renderer>(m_resourceManager->LoadFromResources<ShaderProgram>("../src/resources/shaders/simpleTex.txt"),
									m_resourceManager->LoadFromResources<VertexArray>("../src/myEngine/engineRes/Cube.obj"),
									m_resourceManager->LoadFromResources<Texture>("../src/myEngine/engineRes/Grey.png"));
	entities.push_back(entity);


	return entity;
}