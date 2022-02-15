#pragma once

#include "Actor.h"
#include "Animation.h" 

class Item : public Actor
{
	public:
		Item(float x, float y, Game* game);
		void draw(float scrollX = 0) override; // Va a sobrescribir
		void update();
		Animation* aMoving;
		Animation* animation;
};

