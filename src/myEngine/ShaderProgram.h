#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <fstream>
#include <string>
#include <vector>

class VertexArray;

class ShaderProgram
{
private:
	GLuint id;

public:
	ShaderProgram(std::string vert, std::string frag);

	void Draw(VertexArray *vertexArray);

	void SetUniform(std::string uniform, glm::vec3 value);
	void SetUniform(std::string uniform, glm::vec4 value);
	void SetUniform(std::string uniform, float value);
	void SetUniform(std::string uniform, int value);
	void SetUniform(std::string uniform, glm::mat4 value);

	GLuint GetId() { return id; }

};


#endif