#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <exception>
#include <string>



struct Exception : public std::exception
{
	Exception(const std::string& _message);
	virtual ~Exception() throw();
	virtual const char* what() const throw();

private:
	std::string m_Message;

};
#endif