#pragma once
#include <GL/glew.h>

class VBO {
public:
	GLuint ID;
	GLfloat* vertices;
	VBO(GLfloat* vertices, GLsizeiptr size)
	{
		glGenBuffers(1, &ID);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}
	void Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}
	void Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void Delte()
	{
		glDeleteBuffers(1, &ID);
	}
};