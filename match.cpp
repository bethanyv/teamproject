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

void PileType::add_to_pile(CardType card) {
	// add to number of cards matched and to the 
	// vector of which card was matched
	this->num_matched += 1;
	this->matches.push_back(card);
}

CardType::CardType() {
	bool is_flipped = false;
	int front = 0;
	int back = 0;
}

PileType::PileType() {
	vector<CardType> matches;
}

void PlayerType::setType(int num) {
	this -> number = num;
}

PlayerType::PlayerType() {
	this -> number = 0;
	PileType pile;
}

BoardType::BoardType() {
	vector<CardType> matrix;
	vector<CardType> placed_cards_array;
}

GameType::GameType(){
	BoardType board;
	this -> player1.setType(1);
	this -> player2.setType(2);

	//importing 
}

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

// void BoardType::set_card() {
//     // return 0;
// }
void BoardType::update_board() {
    // return 0;
}
void BoardType::is_full() {
    // return 0;
}
void BoardType::remove_match() {
    // return 0;
}

void BoardType::set_buffer(int num) {
	// takes in  # of cards and spot on board and computes
	// where to place them
	// hard-coded card size in but we can change that if needed?
	int leftover_w = this -> width - (this -> card_w*num);
	this -> buffer_w = leftover_w/5;
	int leftover_h = this -> height - (this -> card_h*num);
	this -> buffer_h = leftover_h/5;
}

int BoardType::set_card_h(int x) {
	// takes in card position in array
	// returns the x position on the board
	int pos = this -> buffer_w + (this -> card_w * (x + 1)) + (this->buffer_w * x) + this -> buffer_w;
	return pos;
	
}

int BoardType::set_card_w(int y) {
	// takes in card position in array
	// returns the y position on the board
	int pos = this -> buffer_h + (this -> card_h * (y + 1)) + (this->buffer_h * y) + this -> buffer_h;
	return pos;
}

// void BoardType::set_cards() {
// 	for (int i = 0; i < (this -> num_cards + 1); i++) {
// 		for (int j = 0; j < (this -> num_cards + 1); j++) {
// 			int x = this -> set_card_w(i);
// 			int y = this -> set_card_h(j);
// 			//call to sfm with new nums
// 			int sprite_num = i + j;
// 			string string_i = to_string(i);
// 			string string_j = to_string(j);
// 			string sprite_name = "sprite_" + string_i + "_" + string_j;
// 			cout << "sprite_name is:" << sprite_name << endl;
// 			sf::Sprite sprite_name;
// 			window.draw(sprite_name);
// 			sprite_name.setPosition(sf::Vector2f(x.f, y.f));
// 		}
// 	}
// }

void BoardType::sfml_driver() {
	/*******************************************
     * SFML Events Here
     * To Compile:
     * g++ -c match_main.cpp main.cpp main.ppp
     * g++ main.o -o match-app -lsfml-graphics -lsfml-window -lsfml-system
     * ./match-app
     ******************************************/
	sf::RenderWindow window(sf::VideoMode(this -> width, this -> height), "A Matching Game");

    //TODO GET RID OF TEMP TEXTURE PLACE HOLDER
    sf::Texture texture;
	if(!texture.loadFromFile("pics/lovelace.jpg", sf::IntRect(0, 0, this -> card_w, this -> card_h))) {
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
			window.draw(shape);
            window.draw(sprite1);

			//set_cards();

			sprite.setTextureRect(sf::IntRect(10,10,32,32));
			//sprite1.setPosition(sf::Vector2f(this -> set_card_w.f, 10.f));
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
}

int GameType::runGame()
{

	//this -> board.set_buffer(4);
	string pic;
	makeWordList("female_cs.txt", this -> pics);
    pic = randomWord(this -> pics);
    cout << "In main, word is: " << pic << endl;

    this -> board.sfml_driver();

    return 0;
}

// int main(int argc, char const *argv[])
// {
// 	// BoardType myboard;
// 	GameType game;

// 	game.runGame();
// 	return 0;
// }