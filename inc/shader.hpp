#ifndef SHADER_HPP
#define SHADER_HPP

#include "glad/glad.h"

class Shader
{
 private:
  GLuint vertexShaderID;      // vertex shader id
  GLuint fragmentShaderID;    // fragment shader id

  // final compiled shader program id used by the gpu
  GLuint shaderProgramID;

  // compile vertex shader source code
  void addVertShader(const char* vertexSource);
  // compile fragment shader source code
  void addFragShader(const char* fragmentSource);
  // link both compile vertex and fragment shader
  void compileInProgram();

 public:
  // Does nothing apart initializing all IDs to 0
  Shader();
  // compile and link vertex and fragment into the shader struct
  void compile(const char* vertexSource, const char* fragmentSource);
  // free shader program
  ~Shader();

  GLuint getShaderProgramID() const;
  // activate shader program into gpu pipeline
  void use() const;
};

#endif