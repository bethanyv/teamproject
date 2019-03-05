#include "match.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> // Stream declarations
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <cstddef>  // For size_t
#define USEDEBUG

#ifdef USEDEBUG
#define DEBUG(X) cerr <<"Debugging "<< #X << ": " << (X) << endl;
#else
#define DEBUG(X)
#endif

using namespace std;

GameType::GameType(){}

void CardType::check_match() {
    // return 0;
}

void PlayerType::move() {
    // return 0;
}

void AI::move() {
    // return 0;
}
int AI::random_pick() {
    // return 0;
}

void BoardType::set_card() {
    // return 0;
}
void BoardType::update_board() {
    // return 0;
}
void BoardType::is_full() {
    // return 0;
}
void BoardType::remove_match() {
    // return 0;
}

int GameType::runGame()
{
    /*******************************************
     * SFML Events Here
     * To Compile:
     * g++ -c match_main.cpp main.cpp main.ppp
     * g++ main.o -o match-app -lsfml-graphics -lsfml-window -lsfml-system
     * ./match-app
     ******************************************/

    sf::RenderWindow window(sf::VideoMode(800, 650), "A Matching Game");

    //TODO GET RID OF TEMP TEXTURE PLACE HOLDER
    sf::Texture texture;
	if(!texture.loadFromFile("ada_lovelace.jpg", sf::IntRect(0, 0, 100, 150))) {
		cout << "Error! ada_lovelace.jpg isn't loading." << endl;
	}

    //TODO Change to pile of sprites
    sf::Sprite sprite1;
	sprite1.setTexture(texture);

	sf::Sprite sprite2;
	sprite2.setTexture(texture);
	sf::Sprite sprite3;
	sprite3.setTexture(texture);
	sf::Sprite sprite4;
	sprite4.setTexture(texture);
	sf::Sprite sprite5;
	sprite5.setTexture(texture);

	sf::Sprite sprite6;
	sprite6.setTexture(texture);
	sf::Sprite sprite7;
	sprite7.setTexture(texture);
	sf::Sprite sprite8;
	sprite8.setTexture(texture);

    /* MAIN SFML PROGRAM LOOP */
    while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

			window.clear();
			//window.draw(shape);
            window.draw(sprite1);
			//sprite.setTextureRect(sf::IntRect(10,10,32,32));
			sprite1.setPosition(sf::Vector2f(10.f, 10.f));
			window.draw(sprite2);
			sprite2.setPosition(sf::Vector2f(130.f, 10.f));
			window.draw(sprite3);
			sprite3.setPosition(sf::Vector2f(250.f, 10.f));
			window.draw(sprite4);
			sprite4.setPosition(sf::Vector2f(370.f, 10.f));
			
			//vertical
			window.draw(sprite5);
			sprite5.setPosition(sf::Vector2f(10.f, 170.f));
			window.draw(sprite6);
			sprite6.setPosition(sf::Vector2f(10.f, 330.f));
			window.draw(sprite7);
			sprite7.setPosition(sf::Vector2f(10.f, 490.f));
			window.display();
	}
    return 0;
}

// int main(int argc, char const *argv[])
// {
// 	// BoardType myboard;
// 	GameType game;

// 	game.runGame();
// 	return 0;
// }