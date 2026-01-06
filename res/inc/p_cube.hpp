#ifndef P_CUBE_HPP
#define P_CUBE_HPP

#include <cstddef>

#include "GLFW/glfw3.h"

namespace mesh
{
// clang-format off
  constexpr GLfloat P_CUBE_VERTICE[] = {
    // Positions           // normales           // texture coordinate
    // front side
    -0.5f, -0.5f, 0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 0.0f,
     0.5f, -0.5f, 0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 0.0f,
     0.5f,  0.5f, 0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 1.0f,
    -0.5f,  0.5f, 0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 1.0f,
    
    // back side 
    -0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,    1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,   0.0f, 0.0f, -1.0f,    0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,   0.0f, 0.0f, -1.0f,    0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,   0.0f, 0.0f, -1.0f,    1.0f, 1.0f,
    
    // left side
    -0.5f, -0.5f, -0.5f,   -1.0f, 0.0f, 0.0f,    0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,   -1.0f, 0.0f, 0.0f,    1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,   -1.0f, 0.0f, 0.0f,    1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,   -1.0f, 0.0f, 0.0f,    0.0f, 1.0f,
    
    // right side
    0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,     1.0f, 0.0f,
    0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,     0.0f, 0.0f,
    0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,     0.0f, 1.0f,
    0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,     1.0f, 1.0f,
    
    // bottom side
    -0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f,    0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 
     0.5f, -0.5f,  0.5f,   0.0f, -1.0f, 0.0f,    1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,   0.0f, -1.0f, 0.0f,    0.0f, 0.0f,
    
    // up side
    -0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,     0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,     1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f,     1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f,     0.0f, 0.0f,
  };
// clang-format on

constexpr const std::size_t P_CUBE_VERTICE_LEN =
    sizeof(P_CUBE_VERTICE) / sizeof(GLfloat);

constexpr unsigned int P_CUBE_INDICE[] = {
    0,  1,  2,  // 1
    2,  3,  0,  // 2

    4,  5,  6,  // 3
    6,  7,  4,  // 4

    8,  9,  10,  // 5
    10, 11, 8,   // 6

    12, 13, 14,  // 7
    14, 15, 12,  // 8

    16, 17, 18,  // 9
    18, 19, 16,  // 10

    20, 21, 22,  // 11
    22, 23, 20   // 12
};

constexpr const std::size_t P_CUBE_INDICE_LEN =
    sizeof(P_CUBE_VERTICE) / sizeof(unsigned int);

extern "C"
{
  extern const unsigned char CUBE_VERT[];
  extern const unsigned int CUBE_VERT_LEN;
  extern const unsigned char CUBE_FRAG[];
  extern const unsigned int CUBE_FRAG_LEN;
}
}  // namespace mesh

#endif