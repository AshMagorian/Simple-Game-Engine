#include <iostream>
#include <memory>

#include <myEngine/Application.h>


int main()
{
	std::shared_ptr<Application> application = application->init();

	application->run();

  return 0;
}