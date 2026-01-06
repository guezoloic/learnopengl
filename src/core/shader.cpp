#include "core/shader.hpp"

#include <iostream>

Shader::Shader() : shaderProgramID(0), vertexShaderID(0), fragmentShaderID(0) {}

void Shader::compile(const char* vertexSource, const char* fragmentSource)
{
  if (this->shaderProgramID != 0) glDeleteProgram(this->shaderProgramID);

  this->vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  this->fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  this->shaderProgramID = glCreateProgram();

  this->addVertShader(vertexSource);
  this->addFragShader(fragmentSource);

  this->compileInProgram();
}

void Shader::addVertShader(const char* vertexSource)
{
  glShaderSource(this->vertexShaderID, 1, &vertexSource, nullptr);
  glCompileShader(this->vertexShaderID);

  GLint success;
  glGetShaderiv(this->vertexShaderID, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    GLchar infoLog[1024];
    glGetShaderInfoLog(this->vertexShaderID, 1024, nullptr, infoLog);

    std::cerr << "ERROR(SHADER): VERTEX COMPILATION FAILED (ID "
              << this->vertexShaderID << ")\n"
              << infoLog << std::endl;
  }
}

void Shader::addFragShader(const char* fragmentSource)
{
  glShaderSource(this->fragmentShaderID, 1, &fragmentSource, nullptr);
  glCompileShader(this->fragmentShaderID);

  GLint success;
  glGetShaderiv(this->fragmentShaderID, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    GLchar infoLog[1024];
    glGetShaderInfoLog(this->fragmentShaderID, 1024, nullptr, infoLog);

    std::cerr << "ERROR(SHADER): FRAGMENT COMPILATION FAILED (ID "
              << this->fragmentShaderID << ")\n"
              << infoLog << std::endl;
  }
}

void Shader::compileInProgram()
{
  glAttachShader(this->shaderProgramID, this->vertexShaderID);
  glAttachShader(this->shaderProgramID, this->fragmentShaderID);
  glLinkProgram(this->shaderProgramID);

  GLint success;
  glGetProgramiv(this->shaderProgramID, GL_LINK_STATUS, &success);
  if (!success)
  {
    GLchar infoLog[1024];
    glGetProgramInfoLog(this->shaderProgramID, 1024, nullptr, infoLog);

    std::cerr << "ERROR(SHADER): LINKING FAILED (Program ID "
              << this->shaderProgramID << ")\n"
              << infoLog << std::endl;
  }

  glDetachShader(this->shaderProgramID, this->vertexShaderID);
  glDetachShader(this->shaderProgramID, this->fragmentShaderID);

  glDeleteShader(this->vertexShaderID);
  glDeleteShader(this->fragmentShaderID);
}

Shader::~Shader() { glDeleteProgram(this->shaderProgramID); }

void Shader::use() const { glUseProgram(this->shaderProgramID); }

GLuint Shader::getShaderProgramID() const { return this->shaderProgramID; }