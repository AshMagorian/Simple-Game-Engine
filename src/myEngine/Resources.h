#ifndef RESOURCES_H
#define RESOURCES_H

#include <list>
#include <memory>
#include <iostream>

#include "Resource.h"
#include "Exception.h"
#include "Material.h"

/**
*The resources class Creates resources and then stores them in a list. This list can then be accessed to load multiple of the
*same resource without having to create an entirely new object from scratch every time
*/
class Resources
{
private:
	std::list<std::shared_ptr<Resource>> m_resources; ///< The list of resources

public:

	Resources();
	/**
	*Takes a string and then compares it with the path of every resource. When it finds the correct
	*resource it returns it using dynamic pointer cast. If it can't find the resource it throws and catches
	*an exception to prevent the game from crashing and displays an error message
	*/
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
	/**
	*Takes the path provided and creates the resource defined. This resource is then
	*pushed back onto the list
	*/
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

	std::shared_ptr<Material> CreateMaterial(std::string _name, std::shared_ptr<Texture> _diff, std::shared_ptr<Texture> _spec, float _shine);
	std::shared_ptr<Material> CreateMaterial(std::string _name, std::shared_ptr<Texture> _diff, float _shine);
};
#endif