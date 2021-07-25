#pragma once
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
class Shader {
private:

	std::string LOAD(std::string filename)
	{
		std::ifstream file;
		std::string src;
		std::string temp;

		file.open(filename);
		if (file.is_open())
		{
			while (std::getline(file, temp))
				src += temp + '\n';
		}
		else
			std::cout << "[ERROR: Shader File]: Failed to load shaderfile at file: " << filename << std::endl;
		file.close();
		return src;
	}
	GLuint COMPILE(GLenum type, std::string filename)
	{
		char infoLog[512];
		GLint success;

		GLuint shader = glCreateShader(type);
		std::string str_src = this->LOAD(filename);
		const GLchar* src = str_src.c_str();
		glShaderSource(shader, 1, &src, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "[ERROR: Shader Compilation]: Shader at file: " << filename << " could not be compiled.\n";
			std::cout << infoLog << "\n";
		}
		return shader;
	} 

	void LINK(GLuint vertexShader, GLuint fragmentShader, GLuint geometryShader)
	{
		char infoLog[512];
		GLint success;

		this->shader_ID = glCreateProgram();
		glAttachShader(this->shader_ID, vertexShader);
		glAttachShader(this->shader_ID, fragmentShader);
		if(geometryShader)
			glAttachShader(this->shader_ID, geometryShader);
		glLinkProgram(this->shader_ID);

		glGetProgramiv(this->shader_ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(this->shader_ID, 512, NULL, infoLog);
			std::cout << "[ERROR: Shader Proram Linking]: Failed to link shaderprogram.\n";
			std::cout << infoLog << "\n";
		}
		glUseProgram(0);
	}
public:
	GLuint shader_ID;
	Shader(std::string vertexFile, std::string fragmentFile, std::string geometryFile = "")
	{
		GLuint vertexShader = 0;
		GLuint geometryShader = 0;
		GLuint fragmentShader = 0;

		vertexShader = COMPILE(GL_VERTEX_SHADER, vertexFile);
		fragmentShader = COMPILE(GL_FRAGMENT_SHADER, fragmentFile);
		if(geometryFile != "")
			geometryShader = COMPILE(GL_GEOMETRY_SHADER, geometryFile);

		this->LINK(vertexShader, fragmentShader, geometryShader);

		glDeleteShader(vertexShader);
		glDeleteShader(geometryShader);
		glDeleteShader(fragmentShader);
	}
	~Shader()
	{
		glDeleteProgram(this->shader_ID);
	}
	void use()
	{
		glUseProgram(this->shader_ID);
	}
	void unuse()
	{
		glUseProgram(0);
	}
	void setMat4fv(const char* name, glm::mat4 matrix, bool use = true)
	{
		if (use)
			this->use();
		glUniformMatrix4fv(glGetUniformLocation(this->shader_ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
		if(use)
			this->unuse();
	}
};