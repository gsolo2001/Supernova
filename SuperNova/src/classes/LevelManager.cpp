#include "headers/LevelManager.h"
#include <headers/Entity.h>


LevelManager::LevelManager(){
	init();
}

void LevelManager::init() {
	testLevel.map = new int[testLevel.width * testLevel.height] {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};
		testLevel.leftStartPosition = Vector2(5, 11);


	level1.map = new int[level1.width * level1.height] {
		 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
		 6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
		 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  3,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 3,  3,  3,  3,  3,  3,  3,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
		 2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
		 4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
	};
	level1.levelName = "level1";
		level1.leftStartPosition = Vector2(2, 7);
		level1.rightStartPosition = Vector2(18, 7);
		level1.right = &level2;
		level1.left = &level1;

		addEntity(getSpicyFlower(), &level1, sf::Vector2f(11, 8));
		addEntity(getSpicyFlower(), &level1, sf::Vector2f(14, 8));

		allLevels.push_back(level1);


	level2.map = new int[level2.width * level2.height] {
		 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
		 6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6,  6,  6,  6,
		 6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  6,  6,  6,
		 6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  6,  6,  6,
		 6,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  6,  6,
		 6,  0,  0,  0,  0,  0,  0,  3,  2,  0,  0,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  6,
		 6,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  6,
		 6,  6,  3,  3,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  6,
		 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,
		 0,  0,  0,  0,  0,  3,  3,  0,  0,  0,  0,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
		 2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
		 4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
		 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	};

  level2.levelName = "level2";
		level2.leftStartPosition = Vector2(2, 11);
		level2.rightStartPosition = Vector2(23, 11);

		level2.background->setBounds(64 * level2.width, 64 * level2.height);
		level2.left = &level1;
		level2.right = &level3;

		addEntity(getSpicyFlower(), &level2, sf::Vector2f(17, 12));
		addEntity(getSpicyFlower(), &level2, sf::Vector2f(15, 12));
		addEntity(getSpicyFlower(), &level2, sf::Vector2f(1, 6));

		allLevels.push_back(level2);


	level3.map = new int[level3.width * level3.height]{
		 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
		 6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
		 6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,
		 6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,
		 7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,
		 0,  0,  0,  0,  0,  0,  0,  0,  3,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,
		 3,  3,  3,  3,  3,  3,  3,  3,  2,  2,  2,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  2,
		 2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  0,  0,  0,  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
		 4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  0,  0,  0,  0,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
		 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	};
	level3.levelName = "level3";
		level3.leftStartPosition = Vector2(2, 10);
		level3.rightStartPosition = Vector2(28, 4);
		level3.botStartPosition = Vector2(16, 10);

		level3.background->setBounds(64 * level3.width, 64 * level3.height);
		
		level3.left = &level2;
		level3.right = &level5;
		level3.bot = &level4;

		addEntity(getSpicyFlower(), &level3, sf::Vector2f(27, 11));
		addEntity(getSpicyFlower(), &level3, sf::Vector2f(25, 11));
		addEntity(getSpicyFlower(), &level3, sf::Vector2f(23, 11));

		allLevels.push_back(level3);


	level4.map = new int[level4.width * level4.height]{
		 1,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		12,  0,  0,  0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		12,  0,  0,  0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 12,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  8,
		 8,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  8,  9,  9,  9,  8,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
	};
	level4.levelName = "level4";

		level4.topStartPosition = Vector2(2, 8);
		level4.background->setBounds(64 * level4.width, 64 * level4.height);

		level4.top = &level3;


		Object* jetpack = new Object(level4.objects.size(), icons.size(), new Sprite("src/resources/jetpack_icon.png", false, false, 1, 32, 32, 2.f, 0));
		jetpack->setIcon(true);
		jetpack->getObject()->getSprite()->setPosition(15 * 64, 8 * 64);
		
		level4.objects.push_back(jetpack);
		icons.push_back(jetpack);
		allLevels.push_back(level4);

	level5.map = new int[level5.width * level5.height]{
		 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		 5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 23, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		 6,  6,  6,  6,  6,  6,  6,  6,  6,  6, 18, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		 7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 20, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 3,  3,  3,  3,  3,  3,  3,  3,  3,  3, 16,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
		 2,  2,  2,  2,  2,  2,  2,  2,  2,  2, 14,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		 4,  4,  4,  4,  4,  4,  4,  4,  4,  4, 22, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
	};
	level5.levelName = "level5";
			level5.leftStartPosition = Vector2(2, 7);
		level5.rightStartPosition = Vector2(18, 7);

		level5.background->setBounds(64 * level5.width, 64 * level5.height);
		level5.left = &level3;
		level5.right = &level6;
		allLevels.push_back(level5);


	level6.map = new int[level6.width * level6.height]
	{
		 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
			 
		12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 12, 12, 13, 13, 13,
		12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12, 12,  0,  0,  0,
		12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12, 12,  0,  0,  0,
		12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12, 12,  0,  0,  0,
		13,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12, 12,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 27, 27,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 27, 27,  0,  0,  0,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  9,  9,  9,  9,  9,  9,  9,  9,  9,  8,  8,  9,  9,  9,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  8,  0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  8,  8,  0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		 9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  8,  8,  8,  0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
			
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
			 

		//10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		//1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	};
	level6.levelName = "level6";
		level6.leftStartPosition = Vector2(2, 10);
		level6.botStartPosition = Vector2(17, 7);
		level6.rightStartPosition = Vector2(28, 7);

		level6.background->setBounds(64 * level6.width, 64 * level6.height);

		level6.left = &level5;
		level6.right = &level11;
		level6.bot = &level7;
		allLevels.push_back(level6);



	level7.map = new int[level7.width * level7.height]
	{
		// 1,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		//11,  0,  0, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		12,  0,  0, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		12,  0,  0, 12, 12, 12, 12, 12, 12, 12, 12, 12,

		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  8,  8,  8,  0,  0,  8,  8,  8,  8,  8,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  8,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  8,  8,  8,  8,  0,  0,  8,  8,  8,  8,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  8,

		 8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  8,
		//1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	};
	level7.levelName = "level7";
		level7.topStartPosition = Vector2(2, 3);
		level7.botStartPosition = Vector2(9, 25);

		level7.background->setBounds(64 * level7.width, 64 * level7.height);
		//level7.background->getSprite()->setPosition(0,0);

		level7.top = &level6;
		level7.bot = &level8;
		allLevels.push_back(level7);

	level8.map = new int[level8.width * level8.height]
	{
		12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  0,  0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  0,  0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		 0,  0,  0, 27, 27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0, 27, 27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0, 27, 27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 0,  0,  0, 27, 27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		

	};
	level8.levelName = "level8";
		level8.topStartPosition = Vector2(15, 4);
		level8.leftStartPosition = Vector2(2, 4);
		level8.rightStartPosition = Vector2(28, 4);
		level8.background->setBounds(64 * level8.width, 64 * level8.height);

		level8.top = &level7;
		level8.left = &level10;
		level8.right = &level9;
		allLevels.push_back(level8);


	level9.map = new int[level9.width * level9.height]
	{
		12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,

	};
	level9.levelName = "level9";
		level9.leftStartPosition = Vector2(1, 4);
		level9.background->setBounds(64 * level9.width, 64 * level9.height);

		level9.left = &level8;

		Object* drill = new Object(level9.objects.size(), icons.size(), new Sprite("src/resources/drill_icon.png", false, false, 1, 32, 32, 2.f, 0));
		drill->setIcon(true);
		drill->getObject()->getSprite()->setPosition(27 * 64, 4 * 64);

		level9.objects.push_back(drill);
		icons.push_back(drill);

		allLevels.push_back(level9);


	level10.map = new int[level10.width * level10.height]
	{
		12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
		12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		 8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,

	};
	level10.levelName = "level10";
		level10.rightStartPosition = Vector2(28, 4);
		level10.background->setBounds(64 * level10.width, 64 * level10.height);

		level10.right = &level8;
		allLevels.push_back(level10);


	level11.map = new int[level11.width * level11.height]
	{
		 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		11, 11, 25,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,

		13, 13, 21,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  2,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  2,
		 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  2,  3,  3,  2,
		 9,  9, 17,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  2,
		 8,  8, 19,  2,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 8,  8, 19,  2,  2,  2,  2,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		 8,  8, 19,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  0,  3,
		 8,  8, 19,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,

		10, 10, 24,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
		 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
	};
	level11.levelName = "level11";
		level11.leftStartPosition = Vector2(2, 7);
		level11.rightStartPosition = Vector2(28, 5);
		level11.background->setBounds(64 * level11.width, 64 * level11.height);

		level11.left = &level6;
		level11.right = &level11;

		addEntity(getSpicyFlower(), &level11, sf::Vector2f(25, 12));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(25.5, 12));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(26, 12));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(26.5, 12));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(27, 12));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(27.5, 12));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(28, 12));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(28.5, 12));

		addEntity(getSpicyFlower(), &level11, sf::Vector2f(25, 9));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(25.5, 9));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(26, 9));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(26.5, 9));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(27, 9));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(27.5, 9));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(28, 9));
		addEntity(getSpicyFlower(), &level11, sf::Vector2f(28.5, 9));

		allLevels.push_back(level11);


		Object* boots = new Object(level11.objects.size(), icons.size(), new Sprite("src/resources/dashboots_icon.png", false, false, 1, 32, 32, 2.f, 0));
		boots->setIcon(true);
		boots->getObject()->getSprite()->setPosition(26 * 64, 6 * 64);

		level11.objects.push_back(boots);
		icons.push_back(boots);
}

Sprite LevelManager::getCurrentBackground() {
	return *currentLevel.background;
}

LevelManager::Level LevelManager::getCurrentLevel() {
	return currentLevel;
}

LevelManager::Level LevelManager::getLevel1() {
	return LevelManager::level1;
}

LevelManager::Level LevelManager::getLevel2() {
	return LevelManager::level2;
}
LevelManager::Level LevelManager::getLevel3() {
	return LevelManager::level3;
}
LevelManager::Level LevelManager::getLevel4() {
	return LevelManager::level4;
}
LevelManager::Level LevelManager::getLevel5() {
	return LevelManager::level5;
}
LevelManager::Level LevelManager::getLevel6() {
	return LevelManager::level6;
}
LevelManager::Level LevelManager::getLevel7() {
	return LevelManager::level7;
}
LevelManager::Level LevelManager::getLevel8() {
	return LevelManager::level8;
}
LevelManager::Level LevelManager::getLevel9() {
	return LevelManager::level9;
}
LevelManager::Level LevelManager::getLevel10() {
	return LevelManager::level10;
}
LevelManager::Level LevelManager::getLevel11() {
	return LevelManager::level11;
}
LevelManager::Level LevelManager::getTestLevel() {
	return LevelManager::testLevel;
}

TileMap LevelManager::getMap() {
	return map;
}

void LevelManager::loadLevel(Level* level) {
	// create the tilemap from the level definition
	if (!map.load("src/resources/tilemap_v6.png", sf::Vector2u(64, 64), level->map, level->width, level->height))
		std::cout << "Error loading TileMap";

	level->colMap = map.loadColMap(level->map, level->width, level->height);

	level->breakableNum = map.getBreakableTile();
	level->collisionTile = map.getCollisionTile();
	level->emptyTile = map.getEmptyTile();

	if (level->hasBackground)
		level->background->animating = true;
}

void LevelManager::setLevel(Level level) {
	if (currentLevel.hasBackground && currentLevel.background->animating)
		currentLevel.background->animating = false;

	currentLevel = level;
	loadLevel(&currentLevel);
}

std::vector<LevelManager::Level> LevelManager::getAllLevels() {
	return allLevels;
}

// Entities Below

void LevelManager::addEntity(Sprite* sprite, Level* level,	sf::Vector2f position) {
	level->enemies.push_back(Entity(level->enemies.size(), level->levelName, sprite, (position * 64.f)));
}

Sprite* LevelManager::getSpicyFlower() {
	return new Sprite("src/resources/spicy_flower.png", false, false, 10, 44, 64, 1.0f, 75);
}