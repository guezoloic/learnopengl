#ifndef CORE_HPP
#define CORE_HPP

// I chose GLAD to dynamically load OpenGL functions at runtime.
// Since OpenGL implementations differ between GPUs and OS, GLAD
// ensures that my code always calls the correct function pointers
// for the current platform and driver. It’s modern, header-only
// unlike GLEW which is much heavier than GLAD, and lets me
// select exactly which OpenGL version and extensions I need.
#include "glad/glad.h"

// I chose GLFW for its simplicity and cross-platform support.
// It handles window creation, OpenGL context management, and input
// (keyboard/mouse), It is allowing me to focus on graphics
// programming rather than writing platform specific code. GLFW is
// lightweight and works consistently on Windows, macOS, and Linux.
#include "GLFW/glfw3.h"

// I chose GLM because I didn’t want to implement all vector and matrix
// math from scratch. I already experimented with a custom SIMD-based
// math library, but GLM is more convenient, header-only, and highly
// optimized for graphics, letting me focus on rendering instead of
// low-level math.
#include "glm/glm.hpp"

// I chose stb_image for image loading to easily handle textures.
// It’s header-only, simple to integrate, and supports common formats
// like PNG and JPEG without adding heavy dependencies.
#include "stb_image.h"

//  used **ImGui** as an optional GUI to debug and tweak rendering parameters in
//  real time. It’s lightweight, immediate-mode, and lets me inspect and modify
//  values without stopping the program.
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"

//
//
//
//
//
//
//
//
#include "camera.hpp"
#include "ebo.hpp"
#include "logger.hpp"
#include "shader.hpp"
#include "time.hpp"
#include "vao.hpp"
#include "vbo.hpp"

#endif