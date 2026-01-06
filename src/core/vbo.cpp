#include "vbo.hpp"

VBO::VBO() : id(0) {}

void VBO::setData(const GLfloat* vertices, size_t size)
{
  if (this->id == 0) glGenBuffers(1, &this->id);
  glBindBuffer(GL_ARRAY_BUFFER, this->id);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

VBO::~VBO() { glDeleteBuffers(1, &this->id); }

void VBO::bind() { glBindBuffer(GL_ARRAY_BUFFER, this->id); }

void VBO::unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }