#pragma once
#include <GL/glew.h>

class EBO {
public:
	GLuint ID;
	unsigned int* indices;
	EBO(unsigned int* indices, GLsizeiptr size)
	{
		glGenBuffers(1, &ID);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	}
	void Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}
	void Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	void Delte()
	{
		glDeleteBuffers(1, &ID);
	}
}; 
