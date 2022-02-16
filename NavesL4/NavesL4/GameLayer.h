#pragma once

#include "Layer.h"
#include "Player.h"
#include "Background.h"

#include "Enemy.h"
#include "Gooba.h"
#include "Projectile.h"
#include "Text.h"
#include "Tile.h"
#include "TileDrop.h"
#include "Pad.h"

#include "Audio.h"
#include "Space.h" // importar
#include "Item.h";

#include <fstream> // Leer ficheros
#include <sstream> // Leer líneas / String
#include <list>

class GameLayer : public Layer
{
public:
	GameLayer(Game* game);
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;
	void keysToControls(SDL_Event event);
	void mouseToControls(SDL_Event event); // USO DE MOUSE
	void gamePadToControls(SDL_Event event); // USO DE GAMEPAD
	void loadMap(string name);
	void loadMapObject(char character, float x, float y);
	void calculateScroll();
	Actor* message;
	bool pause;
	// Elementos de interfaz
	SDL_GameController* gamePad;
	Pad* pad;
	Actor* buttonJump;
	Actor* buttonShoot;

	Tile* cup; // Elemento de final de nivel
	Space* space;
	float scrollX;
	int mapWidth;
	list<Tile*> tiles;

	Audio* audioBackground;
	Text* textPoints;
	int points;
	int newEnemyTime = 0;
	Player* player;
	Background* background;
	Actor* backgroundPoints;
	list<Enemy*> enemies;
	list<Gooba*> goobas;
	list<TileDrop*> tileDrops;
	list<Tile*> tileSalto;
	list<Projectile*> projectiles;
	list<Projectile*> enemyProjectiles;
	list<Item*> items;
	int timeEnemyProjectile = 150;
	bool controlContinue = false;
	bool controlShoot = false;
	int controlMoveY = 0;
	int controlMoveX = 0;


};

