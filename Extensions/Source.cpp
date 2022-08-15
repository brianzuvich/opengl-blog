//
// Solution: OpenGLBlog
// Project: Extensions
// Module: Source.cpp
// Author: Brian Zuvich
// Date: 2022-08-15
//

#include <iostream>
#include <stdlib.h>

#include <glad/glad.h>
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

	// Attempt to initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		exit(EXIT_FAILURE);
	}

	// Print info about the graphics hardware
	std::cout << "- Shading Language = " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "- Version = " << glGetString(GL_VERSION) << std::endl;
	std::cout << "- Vendor = " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "- Renderer = " << glGetString(GL_RENDERER) << std::endl << std::endl;

	// Print the supported extensions
	GLint numExtensions = 0;
	glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
	std::cout << "- Extensions" << std::endl;
	for (GLint i = 0; i < numExtensions; i++)
	{
		std::cout << glGetStringi(GL_EXTENSIONS, i) << std::endl;
	}

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