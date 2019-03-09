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
	int back = 0;
	string file_name = "pics/back.jpg";
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
	int leftover_w = width - (card_w*num);
	buffer_w = leftover_w/5;
	int leftover_h = height - (card_h*num);
	buffer_h = leftover_h/5;
}

int BoardType::set_card_h(int x) {
	// takes in card position in array
	// returns the x position on the board
	int pos = this -> buffer_w + (this -> card_w * (x)) + (this->buffer_w * x);
	return pos;
}

int BoardType::set_card_w(int y) {
	// takes in card position in array
	// returns the y position on the board
	int pos = this -> buffer_h + (this -> card_h * (y)) + (this->buffer_h * y);
	return pos;
}
void BoardType::set_cards(string path) {
	string pic;
	//fill our vector up with picture file names
	makeFileList(path, pics);
	int max = 16;
	for (int i = 0; i < num_cards; i++) {
		for (int j = 0; j < num_cards; j++) {
			//testing random number instead of strin
			int rand_num = randomNumber(max);
			matrix2[i][j] = rand_num;
			// use random number to index into pics
			// check placed_cards and if not there then 
			// set it to this position on the board
			string file_name = pics[rand_num];
			if (find(placed_cards.begin(), placed_cards.end(), file_name) == placed_cards.end());
				matrix[i][j] -> file_name = file_name;
				matrix[i][j] -> sprite.setTexture(file_name);

				//TODO: figure out why this isn't adding file_name to placed cards
				placed_cards.push_back(file_name);
				pics.erase(std::remove(pics.begin(), pics.end(), file_name), pics.end());
			max --;
			//NON-WORKING CODE BELOW
			//Keeping for now, just in case I need syntax or really break something
			//cout << "Stored filename:" << board.matrix[i][j].file_name << endl;
			//

			//board.matrix[i][j].file_name = rand_num;
			// if (find(board.placed_cards.begin(), board.placed_cards.end(), rand_num) == board.placed_cards.end());
			// 	board.placed_cards.push_back(rand_num);
			// max--;
			//below worked (kinda) for strings
			// string file_name = randomFileName(pics, max);
			// board.matrix2[i][j] = file_name;
			// board.matrix[i][j].file_name = file_name;
			// //if (find(board.placed_cards.begin(), board.placed_cards.end(), file_name) == board.placed_cards.end());
			// board.placed_cards.push_back(file_name);
			// max--;
			//cout << "Pics matrix[" << i << "][" << j << "] is:" << this -> board.matrix[i][j] << endl;
			// cout << "Pics placed_cards[" << i << "][" << j << "] is:" << this -> board.matrix[i][j] << endl;
		}
	}
	for (int i = 0; i < num_cards; i++) {
		cout << "Placed card:" << placed_cards[i] << endl;
	}
	for (int i = 0; i < num_cards; i++) {
		for (int j = 0; j < num_cards; j++) {
			cout << "matrix at [" << i << "][" << j << "] is: " << matrix[i][j].file_name << endl;
		}
	}


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

int BoardType::makeFileList(string filepath, vector<string> &name) {
    // vector<string> one_syl_nouns;
    string line;
    ifstream myfile (filepath);
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
        //getline (myfile,line);
        //cout << line << endl;
            while(getline(myfile, line)){
                //cout << line << endl;
                name.push_back(line);
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

// string GameType::randomFileName(vector<string> &name_vec, int max) {
// 	// takes in vector of file names and 
// 	// upper bound to generate random number
// 	// returns string of file name
//     string pic;
//     int num = 0;
//     /* initialize random seed: */
//     srand (time(NULL));
//     num = (rand() % (max)) + 1;
	
// 	// cout << "random number is:" << num << endl;

// 	pic = name_vec[num-1];

//     // cout << "Pic name is: " << pic << " and we have a total of " << name_vec.size() << endl;
//     // cout << "Random pic name in file: " << name_vec[num] << endl;
// 	// name_vec.erase(name_vec.begin()+ (num -1));
//     return pic;
// }

void BoardType::sfml_driver() {
	/*******************************************
     * SFML Events Here
     * To Compile:
     * g++ -c match_main.cpp main.cpp main.ppp
     * g++ main.o -o match-app -lsfml-graphics -lsfml-window -lsfml-system
     * ./match-app
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

			//set_cards();
			//set_cards();

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
	//fill our vector up with picture file names
	GameType::makeFileList("female_cs.txt", pics);
	int max = 16;
	for (int i = 0; i < board.num_cards; i++) {
		for (int j = 0; j < board.num_cards; j++) {
			//testing random number instead of strin
			int rand_num = randomNumber(max);
			board.matrix2[i][j] = rand_num;
			// use random number to index into pics
			// check placed_cards and if not there then 
			// set it to this position on the board
			string file_name = pics[rand_num];
			if (find(board.placed_cards.begin(), board.placed_cards.end(), file_name) == board.placed_cards.end());
				board.matrix[i][j].file_name = file_name;
				//TODO: figure out why this isn't adding file_name to placed cards
				board.placed_cards.push_back(file_name);
				pics.erase(std::remove(pics.begin(), pics.end(), file_name), pics.end());
			max --;
			//NON-WORKING CODE BELOW
			//Keeping for now, just in case I need syntax or really break something
			//cout << "Stored filename:" << board.matrix[i][j].file_name << endl;
			//

			//board.matrix[i][j].file_name = rand_num;
			// if (find(board.placed_cards.begin(), board.placed_cards.end(), rand_num) == board.placed_cards.end());
			// 	board.placed_cards.push_back(rand_num);
			// max--;
			//below worked (kinda) for strings
			// string file_name = randomFileName(pics, max);
			// board.matrix2[i][j] = file_name;
			// board.matrix[i][j].file_name = file_name;
			// //if (find(board.placed_cards.begin(), board.placed_cards.end(), file_name) == board.placed_cards.end());
			// board.placed_cards.push_back(file_name);
			// max--;
			//cout << "Pics matrix[" << i << "][" << j << "] is:" << this -> board.matrix[i][j] << endl;
			// cout << "Pics placed_cards[" << i << "][" << j << "] is:" << this -> board.matrix[i][j] << endl;
		}
	}
	for (int i = 0; i < board.num_cards; i++) {
		cout << "Placed card:" << board.placed_cards[i] << endl;
	}
	for (int i = 0; i < board.num_cards; i++) {
		for (int j = 0; j < board.num_cards; j++) {
			cout << "matrix at [" << i << "][" << j << "] is: " << board.matrix[i][j].file_name << endl;
		}
	}

    board.sfml_driver();

    return 0;
}
