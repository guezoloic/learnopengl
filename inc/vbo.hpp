#ifndef VBO_HPP
#define VBO_HPP

#include <stddef.h>

#include "glad/glad.h"

class VBO
{
 private:
  unsigned int id;

 public:
  VBO();
  ~VBO();

  void setData(GLfloat* vertices, size_t size);

  void bind();
  void unbind();
};

#endif