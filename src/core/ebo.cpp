#include "ebo.hpp"

EBO::EBO() : id(0) {}

void EBO::setData(const unsigned int* indices, size_t size)
{
  if (this->id == 0) glGenBuffers(1, &this->id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

EBO::~EBO() { glDeleteBuffers(1, &this->id); }

void EBO::bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id); }

void EBO::unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }