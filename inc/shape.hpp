#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "core/camera.hpp"
#include "core/ebo.hpp"
#include "core/shader.hpp"
#include "core/texture.hpp"
#include "core/vao.hpp"
#include "core/vbo.hpp"
#include "glm/ext/vector_float3.hpp"

class Shape
{
 private:
  glm::vec3 pos;

 protected:
  Camera &camera;

  VBO vbo;
  EBO ebo;
  VAO vao;

  Shader shader;
  Texture texture;

 public:
  Shape(Camera &camera, glm::vec3 pos, Shader shader, Texture texture)
      : camera(camera), pos(pos), shader(shader), texture(texture)
  {
  }

  virtual void render(int width, int height) = 0;

  glm::vec3 getPosition() const { return pos; }
  void setPosition(glm::vec3 &new_pos) { pos = new_pos; }
};

#endif