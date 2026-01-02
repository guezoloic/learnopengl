#include "GLFW/glfw3.h"

  // Positions           // Normales           // texture coordinate
constexpr GLfloat VERTICE[] = {
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

constexpr unsigned int INDICE[] = {
  0, 1, 2,      // 1
  2, 3, 0,      // 2

  4, 5, 6,      // 3
  6, 7, 4,      // 4

  8, 9, 10,     // 5
  10, 11, 8,    // 6

  12, 13, 14,   // 7
  14, 15, 12,   // 8

  16, 17, 18,   // 9
  18, 19, 16,   // 10

  20, 21, 22,   // 11
  22, 23, 20    // 12
};  

extern unsigned char cube_frag[];
extern unsigned int cube_frag_len;

extern unsigned char cube_vert[];
extern unsigned int cube_vert_len;