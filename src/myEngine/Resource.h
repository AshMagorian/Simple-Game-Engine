#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>

class Resource
{
private:
	std::string m_path;
public:
	virtual ~Resource() {}
	std::string GetPath() { return m_path; }
	void SetPath(std::string _path) { m_path = _path; }

};
#endif