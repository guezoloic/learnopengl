#ifndef VISUAL_HPP
#define VISUAL_HPP

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Visual
{
private:
	// window size
	int width, height;
	// window conf
	GLFWwindow *window = nullptr;

public:
	Visual(const char *name, int width, int height);
	~Visual();

	void run();
	
	GLFWwindow *getWindow();
	int getWidth();
	int getHeight();
};

#endif
