#pragma once
#include <GL/glew.h>
#include <header/data/VBO.h>

class VAO {
public:
	GLuint ID;
	VAO()
	{
		glGenVertexArrays(1, &ID);
		glBindVertexArray(ID);
	}
	void link_layout_VBO(VBO VBO, unsigned int index, int size, const void* distance_from_0, GLsizei stride = sizeof(float) * 3,  GLenum type = GL_FLOAT, GLboolean normalized = GL_FALSE)
	{
		glVertexAttribPointer(index, size, type, normalized, stride, distance_from_0);
		glEnableVertexAttribArray(index);
	}
	void Bind()
	{
		glBindVertexArray(ID);
	}
	void Unbind()
	{
		glBindVertexArray(0);
	}
	void Delete()
	{
		glDeleteVertexArrays(1, &ID);
	}
};