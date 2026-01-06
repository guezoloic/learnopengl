#include "res/inc/cube.hpp"

#include "ebo.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "p_cube.hpp"
#include "vao.hpp"
#include "vbo.hpp"

static GLsizei stride = 8 * sizeof(float);

Cube::Cube(Camera &camera, glm::vec3 pos, std::string texture)
    : Shape(camera, pos, Shader{}, Texture{texture})
{
  this->vao.bind();
  this->vbo.bind();
  this->ebo.bind();

  this->vbo.setData(P_CUBE_VERTICE, sizeof(P_CUBE_VERTICE));

  // positions
  this->vao.setAttributePointer(0, 3, GL_FLOAT, stride, (void *)(0));
  // normales
  this->vao.setAttributePointer(1, 3, GL_FLOAT, stride,
                                (void *)(3 * sizeof(float)));
  // texture
  this->vao.setAttributePointer(2, 2, GL_FLOAT, stride,
                                (void *)(6 * sizeof(float)));

  this->ebo.setData(P_CUBE_INDICE, sizeof(P_CUBE_INDICE));

  this->shader.compile((char *)P_CUBE_VERT, (char *)P_CUBE_FRAG);
}

void Cube::render(int width, int height)
{
  shader.use();
  glActiveTexture(GL_TEXTURE0);

  glm::vec3 coordinate = glm::vec3(0.0f, 0.0f, -1.0f);
  glm::mat4 projection = glm::perspective(
      glm::radians(this->camera.getFov()),
      static_cast<float>(width) / static_cast<float>(height), 0.1f, 100.0f);

  GLint texLoc =
      glGetUniformLocation(shader.getShaderProgramID(), "material.diffuse");
  glUniform1i(texLoc, 0);

  GLint projectionLoc =
      glGetUniformLocation(shader.getShaderProgramID(), "projection");
  glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

  GLint viewLoc = glGetUniformLocation(shader.getShaderProgramID(), "view");
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE,
                     glm::value_ptr(camera.getViewMatrix()));

  glm::mat4 model = glm::translate(glm::mat4(1.0f), coordinate);
  GLint modelLoc = glGetUniformLocation(shader.getShaderProgramID(), "model");
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

  vao.drawElement(GL_TRIANGLES, sizeof(P_CUBE_INDICE) / sizeof(unsigned int),
                  GL_UNSIGNED_INT, 0);
}