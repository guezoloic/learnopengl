#ifndef CUBE_HPP
#define CUBE_HPP

#include "glm/ext/vector_float3.hpp"
#include "shape.hpp"

class Cube : public Shape
{
 public:
  Cube(Camera &camera, glm::vec3 pos, const char *texture);
  void render(int width, int height) override;
};

#endif