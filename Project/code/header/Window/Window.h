#pragma once
#include <GL/glew.h>
#include <iostream>
#include <GLFW/glfw3.h>
void frame_buffer_size_callback(GLFWwindow* window, int fbW, int fbH);

class Window {
public:
	GLFWwindow* window_ID;

	int window_width;
	int window_height;

	Window(int width, int height, const char* title, GLFWmonitor* monitor = NULL, GLFWwindow* window = NULL) 
	{
		initGLFW();
		this->window_height = height;
		this->window_width = width;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window_ID = glfwCreateWindow(width, height, title, monitor, window);

		if (!window_ID) {
			std::cout << "[FETAL: GLFW Window Error]: GLFW Window could not be booted up successfully.\n";
			glfwTerminate();
			}
		glfwMakeContextCurrent(window_ID);
		initGLEW();
		glfwSetFramebufferSizeCallback(window_ID, frame_buffer_size_callback);
		
	}

	void initGLEW()
	{
		if (glewInit() != GLEW_OK)
		{
			std::cout << "[Library Initialization Error]: GLEW Libraray could not be initialized successfully.\n";
		}
		else {
			std::cout << "[OpenGL Library Initialization]: All used Librarys were initialized successfully.\n";
			std::cout << "[OpenGL Version]: " << glGetString(GL_VERSION) << "." << std::endl;
		}
	}
	void initGLFW()
	{
		if (!glfwInit())
		{
			std::cout << "[FATAL: Important Library could not be initialized]: GLFW was not loaded successfully.\n";
		}
	}

	void keyboardInput()
	{

	}
	void mouseInput()
	{

	}
	void inputs();
};