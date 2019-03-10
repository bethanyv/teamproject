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

//Bethany: We are now able to tell which sprite we clicked on. Search for the TODO in sfml driver
// I'm going to bed and probably won't touch this project at all tomorrow unless you ask me to
//or unless something crazy happens.

void PileType::add_to_pile(CardType card) {
	// add to number of cards matched and to the 
	// vector of which card was matched
	this->num_matched += 1;
	this->matches.push_back(card);
}

CardType::CardType() {
	//is flipped - false: back.jpg
	//is flipped - true: face
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
			// int rand_num = randomNumber(max);
			// matrix2[i][j] = rand_num;
			// // use random number to index into pics
			// // check placed_cards and if not there then 
			// // set it to this position on the board
			// cout << "pics[rand_num] is: " << pics[rand_num] << endl;
			// cout << "Dereferencing that we get: " << *pics[rand_num] << endl;
			// string* file_name = pics[rand_num];
			// cout << "File_name is: " << *file_name << endl;
			//file_name = file_name.c_str();

			// sf::Texture texture;
			// if(!texture.loadFromFile("pics/perlman.jpg", sf::IntRect(0, 0, card_w, card_h))) {
			// 	cout << "Error! File isn't loading." << endl;
			// }			

			// if (find(placed_cards.begin(), placed_cards.end(), file_name) == placed_cards.end());
			// 	matrix[i][j] -> file_name = file_name;
			// 	matrix[i][j] -> sprite.setTexture(texture);

			// 	//TODO: figure out why this isn't adding file_name to placed cards
			// 	placed_cards.push_back(file_name);
			// 	pics.erase(std::remove(pics.begin(), pics.end(), file_name), pics.end());

			// set buffer only does one row and one column
			// set_buffer(4);
			// float x = set_card_h(i);
			// float y = set_card_w(j);

			// matrix[i][j] -> sprite.setPosition(sf::Vector2f(x, y));


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
        //getline (myfile,line);
        //cout << line << endl;
            while(getline(myfile, line)){
                // cout << "In makeFileList and saving: " << line << endl;
				string* new_line = new string;
				new_line = &line;
				//cout << "after mallocing, we get :" << new_line << endl;
				//cout << "Dereferencing that, we get: " << *new_line << endl;
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

    sf::Texture textures[16];
    textures[0] = sf::Texture texture1;
	if(!texture1.loadFromFile("pics/allen.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! ada_lovelace.jpg isn't loading." << endl;
	}
	sf::Texture texture2;
	if(!texture2.loadFromFile("pics/bartik.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! ada_lovelace.jpg isn't loading." << endl;
	}
	
	
	// pics/borg.jpg
	// pics/haibt.jpg
	// pics/hamilton.jpg
	// pics/holberton.jpg
	// pics/hopper.jpg
	// pics/keller.jpg
	// pics/liskov.jpg
	// pics/lovelace.jpg
	// pics/meltzer.jpg
	// pics/perlman.jpg
	// pics/rhodes.jpg
	// pics/sammet.jpg
	// pics/spence.jpg
	// pics/teitelbaum.jpg
	// pics/back.jpg

    /* MAIN SFML PROGRAM LOOP */
    while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				
				cout << "Found a mouse click!" << endl;

				sf::Vector2i mousePos = sf::Mouse::getPosition(window); // window is a sf::Window

				// transform the mouse position from window coordinates to world coordinates
    			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				for (int i = 0; i < num_cards; i ++) {
					for (int j = 0; j < num_cards; j++) {
						sf::FloatRect boundingBox = matrix[i][j] -> sprite.getGlobalBounds();
						// if (matrix[i][j] -> sprite.getGlobalBounds().contains(mousePos))
						if (boundingBox.contains(mouse))
						{
							//TODO: BETHANY! We need to add logic here for what to do when we click 
							//on a specific card. YOu can find the card at matrix[i][j]
							cout << "Our click happened in matrix[" << i << "][" << j << "]!!!" << endl;

						}
					}
				}

			}
		}

			window.clear();
            //window.draw(sprite1);

			set_cards("female_cs.txt");

			// for (int i = 0; i < num_cards; i++) {
			// 	for (int j = 0; j < num_cards; j++) {
			// 		window.draw(matrix[i][j] -> sprite);
			// 	}
			// }

			//sprite1.setPosition(sf::Vector2f(this -> set_CARD_W.f, 10.f));
			// int x = set_card_w(0);
			// sprite1.setPosition(sf::Vector2f(x, 10.f));
			// window.draw(sprite2);
			// x = set_card_w(1);
			// sprite2.setPosition(sf::Vector2f(x, 10.f));
			// window.draw(sprite3);
			// x = set_card_w(2);
			// sprite3.setPosition(sf::Vector2f(x, 10.f));
			// window.draw(sprite4);
			// x = set_card_w(3);
			// sprite4.setPosition(sf::Vector2f(x, 10.f));
			
			// //vertical
			// window.draw(sprite5);
			// sprite5.setPosition(sf::Vector2f(10.f, 170.f));
			// window.draw(sprite6);
			// sprite6.setPosition(sf::Vector2f(10.f, 330.f));
			// window.draw(sprite7);
			// sprite7.setPosition(sf::Vector2f(10.f, 490.f));


			for (int i = 0; i < num_cards; i ++) {
				for (int j = 0; j < num_cards; j++) {
					matrix[i][j] -> sprite.setTexture(texture);
					set_buffer(4);
					const float x = set_card_h(i);
					const float y = set_card_w(j);

					//KRISTINE TODO: save x and y into that specific card

					matrix[i][j] -> sprite.setPosition(sf::Vector2f(x, y));

					window.draw(matrix[i][j] -> sprite);
				}
			}
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
