#include "TileDrop.h"

TileDrop::TileDrop(string filename, float x, float y, Game* game)
	: Actor(filename, x, y, 40, 32, game) {
	pisado = false;
	int tiempo = 80;
}

 void TileDrop::pisar() {
	 pisado = true;
}

 void TileDrop::update() {
	 cout << to_string(tiempo) << endl;
	 if (pisado) {
		 tiempo--;
	 }
 }

 bool TileDrop::isFalling() {
	 return tiempo < 30;
 }



