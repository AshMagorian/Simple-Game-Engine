#ifndef RESOURCES_H
#define RESOURCES_H

#include <list>
#include <memory>
#include <iostream>

#include "Resource.h"
class Resources
{
private:
	std::list<std::shared_ptr<Resource>> m_resources;

public:
	template<typename T>
	std::shared_ptr<T> LoadFromResources(std::string _path)
	{
		std::shared_ptr<T> rtn;
		for (std::list<std::shared_ptr<Resource>>::iterator i = m_resources.begin(); i != m_resources.end(); ++i)
		{
			std::cout << "*i-> GetPath() = " << (*i)->GetPath() << std::endl;
			if (_path == (*i)->GetPath())
			{
				rtn = std::dynamic_pointer_cast<T>(*i);
				if (rtn)
				{
					return rtn;
				}
			}
		}
		throw std::exception();
	}

	template<typename T>
	std::shared_ptr<T> CreateResource(std::string _path)
	{
		std::shared_ptr<T> resource = std::make_shared<T>(_path);
		resource->SetPath(_path);
		m_resources.push_back(resource);
		return resource;

	}

	std::list<std::shared_ptr<Resource>> GetResources() { return m_resources; }
};
#endif