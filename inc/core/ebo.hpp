#ifndef EBO_HPP
#define EBO_HPP

#include <stddef.h>

#include "glad/glad.h"
namespace core
{
class EBO
{
 private:
  GLuint id;

 public:
  EBO();
  ~EBO();

  void setData(const unsigned int* indices, size_t size);

  void bind();
  void unbind();
};
};  // namespace core
#endif  // EBO_HPP