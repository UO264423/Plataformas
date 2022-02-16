#pragma once
#include "Actor.h"

class TileDrop : public Actor
{
public:
	TileDrop(string filename, float x, float y, Game* game);
	bool pisado = false;
	void pisar();
	int tiempo = 80;
	void update();
	bool isFalling();
};

