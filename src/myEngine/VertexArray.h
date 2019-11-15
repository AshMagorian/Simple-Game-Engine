#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>

#include "VertexBuffer.h"

class VertexBuffer;

class VertexArray
{
private:
	GLuint id;
	std::vector<std::shared_ptr<VertexBuffer>> buffers;
	bool dirty;

public:
	VertexArray();
	void SetBuffer(std::string attribute, std::shared_ptr<VertexBuffer> buffer);
	int GetVertexCount();
	GLuint GetId();

};
#endif