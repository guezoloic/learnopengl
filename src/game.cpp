#include "game.hpp"
#include "GLFW/glfw3.h"
#include <iostream>

Game::Game(const char *name, int width, int height)
{
	this->width = width;
	this->height = height;

	if(!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW";
        exit(1);
    }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	this->window = glfwCreateWindow(this->width, this->height, name, nullptr, nullptr);
	if (!this->window)
	{
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        exit(1);
    }

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
	}
	
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
}

Game::~Game()
{
	if (window)
	{
		glfwDestroyWindow(window);
	}
	glfwTerminate();
	std::cout << "Game finished with success." << std::endl;
}

void Game::run()
{
	while(!glfwWindowShouldClose(this->window))
	{
		glfwGetWindowSize(window, &this->width, &this->height);
		glViewport(0, 0, this->width, this->height);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

		glDisable(GL_MULTISAMPLE);
		glfwPollEvents();
		glfwSwapBuffers(window);

		GLenum error;
		if ((error = glGetError()) != GL_NO_ERROR)
            std::cout << error << std::endl;
	}
}