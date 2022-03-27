#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <stdlib.h>
#include <headers/LevelManager.h>
#include <SFML/Audio.hpp>

class Player
{
	private:
		float x, y;
		int tileSize = 64;

	public:
		Vector2 startPosition;
		sf::Sprite playerSprite;
		sf::Texture texture;
		sf::Music music;
		bool stoppedLeft = false, stoppedRight = true, moving = false;
		bool transitioningLeft;
		bool transitioningRight;
		bool transitioningTop;
		bool transitioningBot;
		bool jetPack;
		float getX();
		float getY();
		sf::FloatRect getBoundingBox();

		void init();
		void animate();
		void draw(sf::RenderWindow& window);
		bool checkSideCollision(float velo, sf::Vector2f botRightHigh, sf::Vector2f botLeftHigh, sf::Vector2f topRight, sf::Vector2f topLeft, LevelManager::Level currentLevel);
		bool checkTransitionCollision(float left, float right, float top, float bot, float velo, sf::Vector2f botRightHigh, sf::Vector2f botLeftHigh, sf::Vector2f topRight, sf::Vector2f topLeft, LevelManager::Level currentLevel);
		void checkTopBotCollision(sf::Vector2f topRight, sf::Vector2f botRightHigh, sf::Vector2f botRight, sf::Vector2f botMidRight, sf::Vector2f botMid, sf::Vector2f botMidLeft, sf::Vector2f topLeft, sf::Vector2f botLeftHigh, sf::Vector2f botLeft, LevelManager::Level currentLevel);
		bool checkCollision(float velo, LevelManager::Level currentLevel);
		bool checkTile(LevelManager::Level currentLevel, sf::Vector2f position, int remainder);
		void checkMovement(LevelManager::Level currentLevel);
		void respawn();
		void update(LevelManager::Level currentLevel);
		void playCrouchSound();
		void playJumpSound();
};

