#include "Window.h"


void frame_buffer_size_callback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
	glfwGetFramebufferSize(window, &fbW, &fbH);
}
