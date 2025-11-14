#ifndef GAME_HPP
#define GAME_HPP

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Game
{
private:
	// window size
	int width, height;
	// window conf
	GLFWwindow *window = nullptr;

public:
	Game(const char *name, int width, int height);
	~Game();
	void run();
};

#endif
