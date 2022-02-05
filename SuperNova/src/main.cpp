#include <GL/glut.h>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>
#include <iostream>
#include "../src/obj/Player.h"

void draw();
void update();
void drawGrid();

Player player;
//changes
// creates global window
sf::RenderWindow window(sf::VideoMode(1280, 768), "SuperNova");

int main(int argc, char **argv)
{
	window.setFramerateLimit(60);
	
	sf::Clock clock;
	player.init();
	int frames = 0;
	// main loop --> continues each frame while window is open
	while (window.isOpen()) {

		// event handling
		sf::Event event;
		while (window.pollEvent(event)) {

			// event triggered when window is closed
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}

		update();
		draw();
		frames++;
		std::cout << frames<< std::endl;
	}

	return 0;
}

//
// Draws all objects on window
//
void draw() {
	window.clear();

	// draw objects here
	player.draw(window);
	drawGrid();

	window.display();
}

//
// Updates all game objects
//
void update() {
	player.update();
	player.checkMovment();
}

void drawGrid() {
	for (int x = 0; x <= window.getSize().x; x = x+(window.getSize().x / 20)) {
		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = sf::Vector2f(x, 0);
		lines[0].color = sf::Color::White;
		lines[1].position = sf::Vector2f(x, window.getSize().y);
		lines[1].color = sf::Color::White;

		window.draw(lines);
	}

	for (int y = 0; y <= window.getSize().y; y = y + (window.getSize().y / 12)) {
		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = sf::Vector2f(0, y);
		lines[0].color = sf::Color::White;
		lines[1].position = sf::Vector2f(window.getSize().x, y);
		lines[1].color = sf::Color::White;

		window.draw(lines);
	}
}