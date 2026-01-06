#ifndef TIME_HPP
#define TIME_HPP

#include "GLFW/glfw3.h"

class Time
{
 private:
  double deltaTime = 0.;
  double lastDTime = 0.;

 public:
  double getDeltaTime() const { return deltaTime; }
  double getLastDeltaTime() const { return lastDTime; }

  void start()
  {
    deltaTime = glfwGetTime();
    lastDTime = 0.;
  }

  void update()
  {
    double currentTime = glfwGetTime();
    deltaTime = currentTime - lastDTime;
    lastDTime = currentTime;
  }
};

#endif