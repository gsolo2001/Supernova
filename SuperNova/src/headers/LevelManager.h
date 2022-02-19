#pragma once
#include "Vector2.h"
#include "iostream"
#include <headers/TileMap.h>
#include <headers/Sprite.h>


static class LevelManager
{
	public:
		int numberOfLevels = 0;

		struct Level {
			LevelManager* levelManager;
			Sprite* background = NULL;
			bool hasBackground = false;
			int width = 20, height = 12, levelNumber = (levelManager->numberOfLevels)++;
			int* map;
			Vector2 startPosition;
		} testLevel = {this}, 
			level1 = { this, new Sprite("src/resources/space_background_sprite_sheet.png", true, true, 4, 1280, 768, 1000), true },
			level2 = {this, new Sprite("src/resources/Background.jpg"), true, 25, 17 },
			currentLevel = {this};

		LevelManager();
		Sprite getCurrentBackground();
		Level getCurrentLevel();
		Level getLevel1();
		Level getLevel2();
		Level getTestLevel();
		TileMap getMap();
		void refreshLevel();
		void setLevel(Level level);

	private:
		TileMap map;

		void init();
		void loadLevel(Level level);
};
