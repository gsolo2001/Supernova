#include "headers/GameEngine.h"

GameEngine::GameEngine() 
	:window(sf::VideoMode(), "SuperNova")
{
}

void GameEngine::run() {

	init();

	// main loop --> continues each frame while window is open
	while (window.isOpen()) {

		// event handling
		sf::Event event;
		while (window.pollEvent(event))
			handleEvent(event);

		update();
		draw();
	}
}

//
//	Initializes the game components
//
void GameEngine::init() {
	window.setFramerateLimit(60);

	loadLevel(levelManager.getLevel1());
	background = *levelManager.getLevel1().background;
	player.init();

	gamebar.setFillColor(sf::Color(59, 30, 11));
	
	if (!btnLevel1Texture.loadFromFile("src/resources/Level1Button.png"))
		std::cout << "Could not load level 1 button" << std::endl;
	btnLevel1.setTexture(btnLevel1Texture);

	if (!btnLevel2Texture.loadFromFile("src/resources/Level2Button.png"))
		std::cout << "Could not load level 2 button" << std::endl;
	btnLevel2.setTexture(btnLevel2Texture);

	playMusic();
}

//
// Draws all objects on window
//
void GameEngine::draw() {
	window.clear();
	window.setView(view);

	if (levelManager.currentLevel.hasBackground) {
		window.draw(levelManager.getCurrentBackground().getSprite());
	}

	window.draw(levelManager.getMap());

	//drawGrid();

	player.draw(window);

	window.draw(gamebar);
	window.draw(btnLevel1); window.draw(btnLevel2);

	window.display();
}

//
// Draws grid for development/testing purposes
//
void GameEngine::drawGrid() {
	for (int x = 0; x <= window.getSize().x; x = x + tileSize) {
		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = sf::Vector2f(x, 0);
		lines[0].color = sf::Color::White;
		lines[1].position = sf::Vector2f(x, window.getSize().y);
		lines[1].color = sf::Color::White;

		window.draw(lines);
	}

	for (int y = 0; y <= window.getSize().y; y = y + tileSize) {
		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = sf::Vector2f(0, y);
		lines[0].color = sf::Color::White;
		lines[1].position = sf::Vector2f(window.getSize().x, y);
		lines[1].color = sf::Color::White;

		window.draw(lines);
	}
}

//
// Sets viewport to keep game aspect ratio
// ** Adapted from official SFML wiki (src: https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view)
//
sf::View GameEngine::getViewport(float width, float height) {
	float windowRatio = width / height;
	float viewRatio = viewWidth / viewHeight;
	float sizeX = 1;
	float sizeY = 1;
	float posX = 0;
	float posY = 0;

	bool horizontalSpacing = true;
	if (windowRatio < viewRatio)
		horizontalSpacing = false;

	// If horizontalSpacing is true, the black bars will appear on the left and right side.
	// Otherwise, the black bars will appear on the top and bottom.

	if (horizontalSpacing) {
		sizeX = viewRatio / windowRatio;
		posX = (1 - sizeX) / 2.f;
	}
	else {
		sizeY = windowRatio / viewRatio;
		posY = (1 - sizeY) / 2.f;
	}

	view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

	return view;
}

//
// Handles all our games' events
//
void GameEngine::handleEvent(sf::Event event) {
	// event triggered when window is closed
	if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();

	// sets viewport when window is resized
	if (event.type == sf::Event::Resized) {
		view = getViewport(event.size.width, event.size.height);
		gamebar.setSize(sf::Vector2f(event.size.width, 75));
		btnLevel1.setPosition(gamebar.getPosition().x + 10, gamebar.getPosition().y + 5);
		btnLevel2.setPosition(gamebar.getPosition().x + 20 + btnLevel1.getTexture()->getSize().x, gamebar.getPosition().y + 5);
	}

	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
	if (btnLevel1.getGlobalBounds().contains(worldPos.x, worldPos.y)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (levelManager.getCurrentLevel().levelNumber == 2)
				loadLevel(levelManager.getLevel1());
		}
		if (event.type == sf::Event::MouseButtonReleased) {}
	}
	if (btnLevel2.getGlobalBounds().contains(worldPos.x, worldPos.y)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (levelManager.getCurrentLevel().levelNumber == 1)
				loadLevel(levelManager.getLevel2());
		}
		if (event.type == sf::Event::MouseButtonReleased) {}
	}
		
}

//
// Loads level from LevelManager
//
void GameEngine::loadLevel(LevelManager::Level level) {
	player.startPosition = Vector2(level.startPosition);
	player.respawn();
	levelManager.setLevel(level);


	sf::String title("SuperNova - Level " + std::to_string(level.levelNumber));
	window.setTitle(title);

	auto desktop = sf::VideoMode::getDesktopMode();
	viewWidth = tileSize * level.width;
	viewHeight = tileSize * level.height;

	if (window.getSize().x != desktop.width) { // if window is not full screen

		window.setSize(sf::Vector2u(viewWidth, viewHeight));
		window.setPosition(sf::Vector2i(desktop.width / 2 - window.getSize().x / 2, desktop.height / 2 - window.getSize().y / 2));
	
		view.setSize(tileSize * level.width, tileSize * level.height + gamebar.getSize().y);
		view = getViewport(viewWidth, viewHeight);
		view.setCenter(view.getSize().x / 2, (view.getSize().y / 2));
	}
	else {

		view = getViewport(window.getSize().x, window.getSize().y);
		view.setSize(viewWidth, viewHeight);
		view.setCenter(view.getSize().x / 2, (view.getSize().y / 2));

	}
}

//
// Adding background sound to the game
// ** Using code from url: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Music.php
//
void GameEngine::playMusic()
{
	// Open the Background Music
	if (!music.openFromFile("src/resources/background_music.wav")) {
		std::cout << "Could not load background_music" << std::endl;
		return;
	}

	music.setVolume(25);

	music.setLoop(true);         // make it loop
	// Play it
	music.play();
}

//
// Updates all game objects
//
void GameEngine::update() {
	player.update();

	Sprite sprite; sprite.animateAll();
}