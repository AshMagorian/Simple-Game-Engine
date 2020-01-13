#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <fstream>
#include <string>
#include <vector>

#include "Resource.h"

class VertexArray;
class Texture;

struct Sampler
{
	GLint id;
	std::shared_ptr<Texture> texture;
};

class ShaderProgram : public Resource
{
private:
	GLuint id;
	std::vector<Sampler> samplers;

public:
	ShaderProgram(std::string vert, std::string frag);

	void Draw(std::shared_ptr<VertexArray> vertexArray);

	void SetUniform(std::string uniform, glm::vec3 value);
	void SetUniform(std::string uniform, glm::vec4 value);
	void SetUniform(std::string uniform, float value);
	void SetUniform(std::string uniform, int value);
	void SetUniform(std::string uniform, glm::mat4 value);
	void SetUniform(std::string uniform, std::shared_ptr<Texture> texture);

	GLuint GetId() { return id; }

};


#endif