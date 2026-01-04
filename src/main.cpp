#include <cstddef>
#include <cstdlib>
#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
// #include "imgui.h"
// #include "backends/imgui_impl_glfw.h"
// #include "backends/imgui_impl_opengl3.h"

#include "camera.hpp"
#include "cube.hpp"

constexpr const char *WINDOW_NAME = "window";

int width = 800;
int height = 600;

int main(void)
{
  // define error callback
  glfwSetErrorCallback(
      [](int error, const char *desc)
      { std::cerr << "GLFW ERROR (" << error << "): " << desc << std::endl; });

  if (glfwInit() == GLFW_FALSE)
  {
    std::cerr << "GLFW ERROR: Failed to initialize glfw." << std::endl;
    return EXIT_FAILURE;
  }

  // OpenGL CORE 4.1
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // window properties
  glfwWindowHint(GLFW_DEPTH_BITS, 24);   // set depth buffer to 3 bytes  (24 bits)
  glfwWindowHint(GLFW_STENCIL_BITS, 8);  // set stencil buffer to 1 byte (8 bits)
  glfwWindowHint(GLFW_SAMPLES, 4);       // activate MSAA (4 samples per pixels)
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,
                 GL_TRUE);               // disable deprecated functionalities
#endif

  GLFWwindow *window =
      glfwCreateWindow(width, height, WINDOW_NAME, nullptr, nullptr);

  if (window == NULL)
  {
    std::cerr << "GLFW ERROR: Failed to create GLFW window." << std::endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cerr << "GLAD ERROR: Failed to initialize GLAD" << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwSwapInterval(1);

  // IMGUI_CHECKVERSION();
  // ImGui::CreateContext();
  // ImGuiIO &io = ImGui::GetIO();
  // (void)io;

  // ImGui::StyleColorsDark();

  // ImGui_ImplGlfw_InitForOpenGL(window, true);
  // ImGui_ImplOpenGL3_Init("#version 410");

  Camera camera(width, height, window, 0.1f);
  Cube cube{camera, glm::vec3{0.f, 0.f, 0.f}, "stone.png"};

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);

  double deltaTime = 0.f;
  double lastTime = glfwGetTime();
  while (!glfwWindowShouldClose(window))
  {
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(0.5f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    double currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    camera.update(deltaTime);
    cube.render(width, height);

    glfwPollEvents();
    glfwSwapBuffers(window);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
      std::cerr << "error:" << error << std::endl;
      exit(1);
    }
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}