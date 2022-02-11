#include "Gooba.h"
Gooba::Gooba(float x, float y, Game* game)
	: Actor("res/goba.png", x, y, 39, 36, game) {

	state = game->stateMoving;

	aDying = new Animation("res/gobas_muertos.png", width, height,
		78, 36, 2, 2, false, game);

	aMoving = new Animation("res/gobas.png", width, height,
		78, 36, 2, 2 , true, game);
	animation = aMoving;

	vx = 1;
	vxIntelligence = -1;
	vx = vxIntelligence;

}

void Gooba::update() {
	// Actualizar la animación
	bool endAnimation = animation->update();

	// Acabo la animación, no sabemos cual
	if (endAnimation) {
		// Estaba muriendo
		if (state == game->stateDying) {
			state = game->stateDead;
		}
	}


	if (state == game->stateMoving) {
		animation = aMoving;
	}
	if (state == game->stateDying) {
		animation = aDying;
	}

	// Establecer velocidad
	if (state != game->stateDying) {
		// no está muerto y se ha quedado parado
		if (vx == 0) {
			vxIntelligence = vxIntelligence * -1;
			vx = vxIntelligence;
		}
		if (outRight) {
			// mover hacia la izquierda vx tiene que ser negativa
			if (vxIntelligence > 0) {
				vxIntelligence = vxIntelligence * -1;
			}
			vx = vxIntelligence;
		}
		if (outLeft) {
			// mover hacia la derecha vx tiene que ser positiva
			if (vxIntelligence < 0) {
				vxIntelligence = vxIntelligence * -1;
			}
			vx = vxIntelligence;
		}

	}
	else {
		vx = 0;
	}



}

void Gooba::impacted() {
	if (state != game->stateDying) {
		state = game->stateDying;
	}
}


void Gooba::draw(float scrollX) {
	animation->draw(x - scrollX, y);
}
