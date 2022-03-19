#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "headers/Player.h"
#include "headers/TileMap.h"
#include "headers/LevelManager.h"
#include "headers/Sprite.h"
#include "headers/EntityManager.h"
#include "headers/StoryManager.h"

class GameEngine
{
private:
	Player player;
	LevelManager levelManager;
	StoryManager storyManager;
	const int tileSize = 64;
	float viewWidth, viewHeight;
	bool scenePlaying = false;

	// creates global window
	sf::RenderWindow gameWindow, menuWindow;
	sf::View view;
	sf::Music music;
	Sprite *btnLevel1 = new Sprite("src/resources/Level1Button.png"), 
		*btnLevel2 = new Sprite("src/resources/Level2Button.png"),
		*pixiguide = new Sprite("src/resources/pixiguide.png", true, false, 6, 32, 48, 1.0f, 150);
	sf::Texture backgroundTexture;
	sf::RectangleShape gamebar;
	sf::Texture texture;
	std::vector<Vector2> levelVector;

	enum Mode {menu, scene, game};
	Mode gameMode = menu;

public:
	GameEngine();

	LevelManager* getLevelManager() { return &levelManager; }
	Player* getPlayer() { return &player; };
	sf::RenderWindow* getWindow() { return &gameWindow; }
	bool isScenePlaying() { return scenePlaying; }

	void run();
	void init();
	void drawGame();
	void drawGrid();
	void drawMenu();
	sf::View getViewport(float width, float height);
	void handleEvent(sf::Event event);
	void loadLevel(LevelManager::Level level);
	void playMusic();
	void startplayingScene() { scenePlaying = true; }
	void stopPlayingScene() { scenePlaying = false; }
	void updateGame();
	void updateMenu();
};