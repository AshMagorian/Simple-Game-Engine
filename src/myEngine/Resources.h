#ifndef RESOURCES_H
#define RESOURCES_H

#include <list>
#include <memory>
#include <iostream>

#include "Resource.h"
#include "Exception.h"

class Resources
{
private:
	std::list<std::shared_ptr<Resource>> m_resources;

public:
	template<typename T>
	std::shared_ptr<T> LoadFromResources(std::string _path)
	{
		try
		{
			std::shared_ptr<T> rtn;
			for (std::list<std::shared_ptr<Resource>>::iterator i = m_resources.begin(); i != m_resources.end(); ++i)
			{
				if (_path == (*i)->GetPath())
				{
					rtn = std::dynamic_pointer_cast<T>(*i);
					if (rtn)
					{
						std::cout << (*i)->GetPath() << " loaded" << std::endl;
						return rtn;
					}
				}
			}
			throw Exception(_path + " cannot be loaded from Resources");
		}
		catch (Exception& e)
		{
			std::cout << "myEngine Exception: " << e.what() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "exception: " << e.what() << std::endl;
		}
		return NULL;
	}
	
	template<typename T>
	std::shared_ptr<T> CreateResource(std::string _path)
	{
		std::shared_ptr<T> resource;
		try
		{
			resource = std::make_shared<T>(_path);
		}
		catch (Exception& e)
		{
			std::cout << "myEngine Exception: " << e.what() << std::endl;
			return NULL;
		}
		resource->SetPath(_path);
		m_resources.push_back(resource);
		std::cout << _path << " created" << std::endl;
		return resource;

	}

	std::list<std::shared_ptr<Resource>> GetResources() { return m_resources; }
};
#endif