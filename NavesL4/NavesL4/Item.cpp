#include "Item.h"

Item::Item(float x, float y, Game* game) : Actor("res/icono_recolectable.png", x, y, 40, 40, game) {
	aMoving = new Animation("res/recolectable.png", width, height,
		256, 32, 8, 8, true, game);
	animation = aMoving;
}

void Item::draw(float scrollX) {
	animation->draw(x-scrollX, y);
}

void Item::update() {
	animation->update();
}