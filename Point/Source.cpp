//
// Solution: OpenGLBlog
// Project: Point
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

	//////////////////////////////////////////////////
	// Create a vertex shader
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);

	// Create some shader source code
	const char* pVSSource =
		"#version 460\n"
		"void main()"
		"{"
		"	gl_Position = vec4(0.0f, 0.0f, 0.0f, 1.0f);"
		"}";

	// Set the shader source
	glShaderSource(vShader, 1, &pVSSource, 0);

	// Attempt to compile the shader
	glCompileShader(vShader);

	// Check if there were any compile errors
	int vsSuccess;
	char vsCompileLog[512];
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vsSuccess);
	if (!vsSuccess)
	{
		glGetShaderInfoLog(vShader, 512, nullptr, vsCompileLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILE" << std::endl << vsCompileLog << std::endl;
	}

	//////////////////////////////////////////////////
	// Create a fragment shader
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Create some shader source code
	const char* pFSSource =
		"#version 460\n"
		"out vec4 fragColor;"
		"void main()"
		"{"
		"	fragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);"
		"}";

	// Set the shader source
	glShaderSource(fShader, 1, &pFSSource, 0);

	// Attempt to compile the shader
	glCompileShader(fShader);

	// Check if there were any compile errors
	int fsSuccess;
	char fsCompileLog[512];
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &fsSuccess);
	if (!fsSuccess)
	{
		glGetShaderInfoLog(fShader, 512, nullptr, fsCompileLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILE" << std::endl << fsCompileLog << std::endl;
	}

	//////////////////////////////////////////////////
	// Create a shader program
	GLuint shaderProgram = glCreateProgram();

	// Attach the vertex and fragment shader
	glAttachShader(shaderProgram, vShader);
	glAttachShader(shaderProgram, fShader);

	// Attempt to link the program
	glLinkProgram(shaderProgram);

	// Check for link errors
	int linkSuccess;
	char linkCompileLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkSuccess);
	if (!linkSuccess)
	{
		glGetProgramInfoLog(shaderProgram, 512, nullptr, linkCompileLog);
		std::cout << "ERROR::SHADER_PROGRAM::LINKING" << std::endl << linkCompileLog << std::endl;
	}

	// Set the shader program as the current
	glUseProgram(shaderProgram);

	// Increase the point size
	glPointSize(32.0f);

	// Begin the draw loop
	while (!glfwWindowShouldClose(pWindow))
	{
		// Prepare the frame
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw
		glDrawArrays(GL_POINTS, 0, 1);

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