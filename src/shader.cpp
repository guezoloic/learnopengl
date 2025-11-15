#include "shader.hpp"

Shaders::Shaders(const char* vertexShaderSource, const char* fragmentShaderSource)
{
    vertexShader = glCreateShader(GL_VERTEX_SHADER);     
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); 
    shaderProgram = glCreateProgram();                   

    addVertShader(vertexShaderSource);
    addFragShader(fragmentShaderSource);

    compileInProgram();
}

void Shaders::addVertShader(const char* vertexShaderSource)
{
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
}

void Shaders::addFragShader(const char* fragmentShaderSource)
{
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);
}

void Shaders::compileInProgram()
{
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDetachShader(shaderProgram, vertexShader);
    glDetachShader(shaderProgram, fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shaders::~Shaders()
{
    glDeleteProgram(shaderProgram);
}

void Shaders::use() const
{
    glUseProgram(shaderProgram);
}

GLuint Shaders::getProgram() const
{
    return shaderProgram;
}