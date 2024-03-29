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
		float hp = 1.f;
		int jetpackFuel, dashCooldown, dashDistance;
		sf::Clock walkTimer, jetTimer, drillTimer, damageTimer, deathTimer, dashTimer,
			shootCooldownTimer, drillSoundTimer;
		sf::RectangleShape rect;
		sf::Image playerImage;

		sf::IntRect
			frameDamagedRight = sf::IntRect(0, 257, 36, 64),
			frameDamagedLeft = sf::IntRect(36, 257, 36, 64),
			frameJetpackLeft = sf::IntRect(114, 322, 38, 64),
			frameJetpackRight = sf::IntRect(0, 322, 38, 64),
			frameJumpLeft = sf::IntRect(44, 128, 44, 64),
			frameJumpRight = sf::IntRect(0, 128, 44, 64),
			frameShootRight = sf::IntRect(0, 641, 64, 64),
			frameShootLeft = sf::IntRect(63, 641, 64, 64),
			frameSquatLeft = sf::IntRect(44, 192, 44, 64),
			frameSquatRight = sf::IntRect(0, 192, 44, 64),
			frameStoppedLeft = sf::IntRect(0, 64, 32, 64),
			frameStoppedRight = sf::IntRect(0, 0, 32, 64);

	public:
		Vector2 startPosition;
		sf::Sprite playerSprite;
		sf::Texture texture;
		sf::Music music;

		bool stoppedLeft = false, stoppedRight = true, moving = false, jetPack = false, drilling = false, playingDeath = false, dead = false,
			takingDamage = false, dashing = false, dashBoots = false,
			shooting = false;
		bool transitioningLeft, transitioningRight, transitioningTop, transitioningBot;


		bool* displayingText;

		float getX();
		float getY();
		sf::FloatRect getBoundingBox();

		sf::Sprite getSprite();
		void init(bool* displayingText);
		void animate();
		void checkDeath();
		void draw(sf::RenderWindow& window);
		void checkItems(LevelManager::Level* currentLevel);
		bool checkSideCollision(float velo, sf::Vector2f botRightHigh, sf::Vector2f botLeftHigh, sf::Vector2f topRight, sf::Vector2f topLeft, LevelManager::Level* currentLevel);
		bool checkTransitionCollision(float left, float right, float top, float bot, float velo, sf::Vector2f botRightHigh, sf::Vector2f botLeftHigh, sf::Vector2f topRight, sf::Vector2f topLeft, LevelManager::Level* currentLevel);
		void checkTopBotCollision(sf::Vector2f topRight, sf::Vector2f botRightHigh, sf::Vector2f botRight, sf::Vector2f botMidRight, sf::Vector2f botMid, sf::Vector2f botMidLeft, sf::Vector2f topLeft, sf::Vector2f botLeftHigh, sf::Vector2f botLeft, LevelManager::Level* currentLevel);
		bool checkCollision(float velo, LevelManager::Level* currentLevel);
		void DrillCollision(float velo, LevelManager::Level* currentLevel);

		bool checkTile(LevelManager::Level* currentLevel, sf::Vector2f position, int remainder);
		void checkMovement(LevelManager::Level* currentLevel);
		void respawn();
		void update(LevelManager::Level* currentLevel);
		void playCrouchSound();
		void playJetpackLaunch();
		void playDrillSound();
		void playJumpSound();
		void playWalkSound();
		void playHPUpSound();
		void playDeathSound(); 
		void playDamageSound();
		

		int getJetPackFuel();
		float getHp();
		float takeDamage(float damage);
		float heal(float health);
		sf::Image getImage();

		int const JETPACK_MAXIMUM = 75,
			DASH_COOLDOWN = 120, DASH_TOTAL_DISTANCE = 320, DASH_SPEED = 16,
			SHOOT_COOLDOWN_MILLISECONDS = 150;
		float const HEALTH_PACK_HEAL_VALUE = 0.25;
};

