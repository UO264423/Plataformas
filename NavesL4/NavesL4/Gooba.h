#pragma once

#include "Actor.h"
#include "Animation.h" 
#include "Projectile.h"

class Gooba : public Actor
{
public:
	Gooba(float x, float y, Game* game);
	void draw(float scrollX = 0) override; // Va a sobrescribir
	void update();
	void impacted(); // Recibe impacto y pone animación de morir
	Projectile* shoot();
	float vxIntelligence;
	int state;
	Animation* aDying;
	Animation* aMoving;
	Animation* animation; // Referencia a la animación mostrada
};

