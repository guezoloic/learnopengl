#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "GLFW/glfw3.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/vector_float3.hpp"

class Camera
{
 private:
  int width;
  int height;

  double mousePosX;
  double mousePosY;
  // first mouse detection
  bool firstMouse = true;

  float cameraYaw = -90.f;   // horizontal angle
  float cameraPitch = 10.f;  // vertical angle

  // front camera vector (where the camera is pointed.)
  glm::vec3 cameraFront = glm::vec3(0.f, 0.f, -1.f);
  // up world vector (absolute up pos)
  glm::vec3 worldUp = glm::vec3(0.f, 1.f, 0.f);

  // up camera vector (relative up from the camera)
  glm::vec3 cameraUp;
  // right camera vector (relative right from the camera)
  glm::vec3 cameraRight;

  // camera position
  glm::vec3 cameraPosition = glm::vec3(0.f, 0.f, 0.f);

  // glfw window
  GLFWwindow* window;

  float speed = 3.f;        // move speed
  float cameraSensitivity;  // mouse sensitivity
  float fov = 45.f;         // Field Of View

  void processInput(float deltaTime);
  void processMouseMovement();
  void updateCameraVectors();

 public:
  Camera(int width, int height, GLFWwindow* window, float sensitivity);

  void update(float deltaTime);

  // view matrix
  glm::mat4 getViewMatrix() const;
  // projection matrix
  glm::mat4 getProjectionMatrix() const;

  float getFov() const { return fov; }
  float getSpeed() const { return speed; }
  float getCameraSensitivity() const { return cameraSensitivity; }
  glm::vec3 getPosition() const { return cameraPosition; }

  void setSpeed(float newSpeed);
  void setCameraSensitivity(float newSensitivity);
  void setFov(float newFov);
  void setPosition(const glm::vec3& newPosition);
};

#endif
