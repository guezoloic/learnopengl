#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "game.hpp"
#include <time.h>
#include <cstdlib>
#include <format>
#include <iostream>

Game::Game(int width, int height, const char *window_name)
    : width(width), height(height), WINDOW_NAME(window_name)
{
  glfwSetErrorCallback([](int error, const char *desc)
                       { Game::error("GLFW", error, desc); });

  if (glfwInit() == GLFW_FALSE)
  {
    Game::error("GLFW", 0, "Failed to initialize GLFW.");
    std::exit(EXIT_FAILURE);
  }

  // OpenGL CORE 4.1
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // window properties
  glfwWindowHint(GLFW_DEPTH_BITS, 24);   // request a 24 bits depth buffer
  glfwWindowHint(GLFW_STENCIL_BITS, 8);  // request an 8 bits stencil buffer
  glfwWindowHint(GLFW_SAMPLES, 4);       // activate MSAA (x4)
  
#ifdef __APPLE__  // disable deprecated functionalities on Apple devices
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  this->window = glfwCreateWindow(width, height, WINDOW_NAME, nullptr, nullptr);

  if (window == NULL)
  {
    Game::error("GLFW", 0, "Failed to create GLFW window.");
    glfwTerminate();
    std::exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    Game::error("GLAD", 0, "Failed to initialize GLAD.");
    glfwDestroyWindow(window);
    glfwTerminate();
    std::exit(EXIT_FAILURE);
  }

  glfwSwapInterval(1);  // activate vsync

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);
}

void Game::error(const char *type, int errortype, const char *desc)
{
  std::cerr << type << "ERROR"
            << ((errortype) ? std::format("({})", errortype) : "") << ": "
            << desc << std::endl;
}

void Game::run()
{
  time.start();
  while (!glfwWindowShouldClose(window))
  {
    glfwGetFramebufferSize(window, &width, &height);
    glfwGetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(0.5f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(window);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
      Game::error("OpenGL", error, "");
      std::exit(EXIT_FAILURE);
    }

    time.update();
  }
}