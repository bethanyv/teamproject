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

//Note to Bethany: I thought that I converted all of our fiile name strings to string*'s
//but somewhere along the line I didn't do it right. At least that's what I could
//gather after googling the seg fault error.
//feel free to look around and figure it out.

//Kristine - added a sprite data member to CardType

void PileType::add_to_pile(CardType card) {
	// add to number of cards matched and to the 
	// vector of which card was matched
	this->num_matched += 1;
	this->matches.push_back(card);
}

CardType::CardType() {
	bool is_flipped = false;
	int front = 0;
	// int back = 0;
	string file_name = "pics/back.jpg";
	// sf::Sprite* = new new_sprite;
	// sprite = new_sprite;
	sf::Texture texture;
	if(!texture.loadFromFile("pics/back.jpg", sf::IntRect(0, 0, width, height))) {
		cout << "Error! back.jpg isn't loading." << endl;
	}
	back = texture;
}

PileType::PileType() {
	vector<CardType> matches;
}

void PlayerType::setType(int num) {
	number = num;
}

PlayerType::PlayerType() {
	number = 0;
	PileType pile;
}

BoardType::BoardType() {
	matrix.resize(num_cards);
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(num_cards);
		for (int j = 0; j < matrix.size(); j++) {
			//TODO clean up memory aka delete[]
			CardType* card = new CardType;
			matrix[i][j] = card;
		}
	}

	matrix2.resize(num_cards);
	for (int i = 0; i < matrix2.size(); i++) {
		matrix2[i].resize(num_cards);
	}
	placed_cards.resize(num_cards);
}

GameType::GameType(){
	BoardType board;
	player1.setType(1);
	player2.setType(2);

	//importing 
}

bool CardType::check_match(CardType card) {
	return card.front == front;
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

// do we need this function if we are just removing cards if they are a match?
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
	// takes in  # of cards and computes
	// where to place them
	// hard-coded card size in but we can change that if needed?
	int leftover_w = width - (card_w*num);
	//buffer_w = leftover_w/5;
	int leftover_h = height - (card_h*num);
	//buffer_h = leftover_h/5;

}

int BoardType::set_card_h(int x) {
	// takes in card position in array
	// returns the x position on the board
	int pos = buffer_w + (card_w * x) + (buffer_w * x);
	return pos;
}

int BoardType::set_card_w(int y) {
	// takes in card position in array
	// returns the y position on the board
	int pos = buffer_h + (card_h * y) + (buffer_h * y);
	return pos;
}

void BoardType::set_cards(string path) {
	string pic;
	//fill our vector up with picture file names
	makeFileList(path, pics);
	int max = 16;
	for (int i = 0; i < num_cards; i++) {
		for (int j = 0; j < num_cards; j++) {
			//testing random number instead of string
			int rand_num = randomNumber(max);
			matrix2[i][j] = rand_num;
			// use random number to index into pics
			// check placed_cards and if not there then 
			// set it to this position on the board
			//cout << "pics[rand_num] is: " << pics[rand_num] << endl;
			//cout << "Dereferencing that we get: " << *pics[rand_num] << endl;
			const char* file_name = pics[rand_num];
			// cout << "File_name is: " << *file_name << endl;
			//file_name = file_name.c_str();

			sf::Texture texture;
			//cout << "file_name: " << file_name << endl;
			//cout << "*file_name: " << *file_name << endl;
			string new_name = file_name;
			if(!texture.loadFromFile(new_name, sf::IntRect(0, 0, card_w, card_h))) {
				cout << "Error! File isn't loading." << endl;
			}			

			//if (find(placed_cards.begin(), placed_cards.end(), file_name) == placed_cards.end());
			matrix[i][j] -> file_name = *file_name;
			matrix[i][j] -> sprite.setTexture(texture);

			// 	//TODO: figure out why this isn't adding file_name to placed cards
			// 	placed_cards.push_back(file_name);
			// 	pics.erase(std::remove(pics.begin(), pics.end(), file_name), pics.end());

			// set buffer only does one row and one column
			set_buffer(4);
			float x = set_card_h(i);
			float y = set_card_w(j);

			max --;
			
		}
	}
}

int BoardType::makeFileList(string filepath, vector<string*> &name) {
    // vector<string> one_syl_nouns;
    string line;
    ifstream myfile (filepath);
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
        getline (myfile,line);
        //cout << line << endl;
            while(getline(myfile, line)){
                //cout << "In makeFileList and saving: " << line << endl;
				const char* new_line = new char;
				new_line = line.c_str();
				//cout << "after mallocing, we get :" << new_line << endl;
				//cout << "Dereferencing that, we get: " << *new_line << endl;
				string* new_line = new string;
				new_line = &line;
				// cout << "after mallocing, we get :" << new_line << endl;
				// cout << "Dereferencing that, we get: " << *new_line << endl;
                name.push_back(new_line);
            }
        }
        myfile.close();
    }
    // return 0;

  else cout << "Unable to open file";

  return 0;
}

int BoardType::randomNumber(int max) {
	//takes in max number
	// returns random number between 1 and max
	int num = 0;
	srand (time(NULL));
    num = (rand() % (max)) + 1;
	return num;

}

void BoardType::sfml_driver() {
	/*******************************************
     * SFML Events Here
     ******************************************/
	sf::RenderWindow window(sf::VideoMode(width, height), "A Matching Game");

    //TODO GET RID OF TEMP TEXTURE PLACE HOLDER
    sf::Texture texture;
	if(!texture.loadFromFile("pics/lovelace.jpg", sf::IntRect(0, 0, card_w, card_h))) {
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
            window.draw(sprite1);

			set_cards("female_cs.txt");

			// for (int i = 0; i < num_cards; i++) {
			// 	for (int j = 0; j < num_cards; j++) {
			// 		window.draw(matrix[i][j] -> sprite);
			// 	}
			// }

			//sprite1.setPosition(sf::Vector2f(this -> set_CARD_W.f, 10.f));
			int x = set_card_w(0);
			sprite1.setPosition(sf::Vector2f(x, 10.f));
			window.draw(sprite2);
			x = set_card_w(1);
			sprite2.setPosition(sf::Vector2f(x, 10.f));
			window.draw(sprite3);
			x = set_card_w(2);
			sprite3.setPosition(sf::Vector2f(x, 10.f));
			window.draw(sprite4);
			x = set_card_w(3);
			sprite4.setPosition(sf::Vector2f(x, 10.f));
			
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
	// board.set_cards("female_cs.txt");

	board.sfml_driver();

	// for (int i = 0; i < board.num_cards; i++) {
	// 	cout << "Placed card:" << board.placed_cards[i] << endl;
	// }
	// for (int i = 0; i < board.num_cards; i++) {
	// 	for (int j = 0; j < board.num_cards; j++) {
	// 		cout << "matrix at [" << i << "][" << j << "] is: " << board.matrix[i][j]->file_name << endl;
	// 	}
	// }

    return 0;
}
