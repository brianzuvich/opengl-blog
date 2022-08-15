//
// Solution: OpenGLBlog
// Project: Point
// Module: Source.cpp
// Author: Brian Zuvich
// Date: 2022-08-15
//

#include <stdlib.h>

#include <GLFW/glfw3.h>

int main(int argc, char** argv)
{
	// Attempt to initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	// Attempt to create a GLFW window
	GLFWwindow* pWindow = glfwCreateWindow(500, 500, "GLFW Based OpenGL Window", nullptr, nullptr);

	// Check if the widow object creation succeeded
	if (!pWindow)
	{
		exit(EXIT_FAILURE);
	}

	// Set the current OpenGL context
	glfwMakeContextCurrent(pWindow);

	// Begin the draw loop
	while (!glfwWindowShouldClose(pWindow))
	{
		// Prepare the frame
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw

		// Flip the front and back buffer
		glfwSwapBuffers(pWindow);

		// Check for user input
		glfwPollEvents();
	}

	// Destroy the window
	glfwDestroyWindow(pWindow);
	pWindow = nullptr;

	// Terminate GLFW
	glfwTerminate();

	// Satisfy the main function
	return 0;
}