#ifndef GAME_HPP
#define GAME_HPP

#include "visual.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Game
{
private:
	bool finished = false;
	int frame     = 60;
	
	Visual v;
public:
	Game();

	void run();
};

#endif
