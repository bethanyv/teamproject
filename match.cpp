#include "match.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> // Stream declarations
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <unistd.h>
#include <cassert>
#include <cstddef>  // For size_t
#define USEDEBUG

#ifdef USEDEBUG
#define DEBUG(X) cerr <<"Debugging "<< #X << ": " << (X) << endl;
#else
#define DEBUG(X)
#endif

using namespace std;


CardType::CardType(int index) : front(index) {
	bool is_flipped = false;

	try {
		sprite = new sf::Sprite;
	}
	catch (bad_alloc& ba) {
		cout << "bad_alloc caught: " << ba.what() << endl;
	}
	
}

sf::Sprite& CardType::getSprite() {
	return *sprite;
}

// this function compares coordinates. If two cards selected have the same 
// x and y, then it can't be selected
bool CardType::is_same_card(CardType card) {
	if(card.get_x() == x_coord && card.get_y() == y_coord) {
		return true;
	}
	return false;
}

int CardType::get_x() {
	return x_coord;
}

int CardType::get_y() {
	return y_coord;
}

// call this function when setting the x and y coordinates of a card when it's placed
void CardType::set_coords(int x, int y) {
	x_coord = x;
	y_coord = y;
}

void BoardType::make_cards_to_place(const int amt) {
	auto size = cards_to_place.size();
	srand(unsigned(time(0)));
	for(int i = 0; (cards_to_place.size() < (amt*2)); i ++) {
		cards_to_place.push_back(i);
		cards_to_place.push_back(i);
	}
	random_shuffle(cards_to_place.begin(), cards_to_place.end());
}

BoardType::BoardType() {
	make_cards_to_place(8);
	matrix.reserve(num_cards);
	random_shuffle(cards_to_place.begin(), cards_to_place.end());
	for (int i = 0; i < num_cards; i++) {
		matrix[i].reserve(num_cards);
		for (int j = 0; j < num_cards; j++) {
			try {
				CardType* card = new CardType(cards_to_place.back());
				cards_to_place.pop_back();
				matrix[i][j] = card;
			}
			catch (std::bad_alloc& ba)
			{
				cerr << "bad_alloc caught: " << ba.what() << endl;
			}
		}
	}
}

int CardType::get_w() {
	return this -> width;
}

int CardType::get_h() {
	return this -> height;
}

bool CardType::check_match(CardType card) {
	return front == card.getFront();
}

int CardType::getFront() {
	return front;
}

void CardType::flip() {
	if(is_flipped) {
		is_flipped = false;
		return;
	}
	else {
		is_flipped = true;
		return;
	}
}

void BoardType::set_buffer(int num) {
	// takes in  # of cards and computes
	// where to place them
	// hard-coded card size in but we can change that if needed?
	float leftover_w = width - (card_w*num);
	//buffer_w = leftover_w/5;
	float leftover_h = height - (card_h*num);
	//buffer_h = leftover_h/5;

}

float BoardType::set_card_h(int x) {
	// takes in card position in array
	// returns the x position on the board
	float pos = buffer_w + (card_w * x) + (buffer_w * x);
	return pos;
}

float BoardType::set_card_w(int y) {
	// takes in card position in array
	// returns the y position on the board
	float pos = buffer_h + (card_h * y) + (buffer_h * y);
	return pos;
}

void BoardType::set_cards(string path) {
	//fill our vector up with picture file names
	makeFileList(path, pics);
}


int BoardType::makeFileList(string filepath, vector<string> &name) {
    string line;
    ifstream myfile (filepath);
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            while(getline(myfile, line)){
				try {
					string* new_line = new string;
					new_line = &line;
					name.push_back(*new_line);
				}
				catch (bad_alloc& ba)
				{
					cerr << "bad_alloc caught: " << ba.what() << endl;
				}
            }
        }
        myfile.close();
    }

	else cout << "Unable to open file";

	return 0;
}

int BoardType::randomNumber(int max) {
	//takes in max number
	// returns random number between 1 and max
	int num = 0;
	srand (time(NULL));
    num = (rand() % (max));
	return num;

}

void BoardType::sfml_driver() {
	/*******************************************
     * SFML Events Here
     ******************************************/
	sf::RenderWindow window(sf::VideoMode(width, height), "A Matching Game");
	// for the vertical sync not supported error
	window.setFramerateLimit(60);
	int player_turn = 1;
	int cards_clicked = 0;
	int first_index;
	int first_i;
	int first_j;
	int second_index;
	int second_i;
	int second_j;
	int player1_pile = 0;
	int player2_pile = 0;
	vector<sf::Texture> textures;
	vector<int> matches_found;

	sf::Texture allen;
	if(!allen.loadFromFile("pics/allen.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! ada_lovelace.jpg isn't loading." << endl;
	}
	textures.push_back(allen);

	sf::Texture bartik;
	if(!bartik.loadFromFile("pics/bartik.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! bartik.jpg isn't loading." << endl;
	}
	textures.push_back(bartik);
	
	sf::Texture borg;
	if(!borg.loadFromFile("pics/borg.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! borg.jpg isn't loading." << endl;
	}
	textures.push_back(borg);
	
	sf::Texture haibt;
	if(!haibt.loadFromFile("pics/haibt.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! haibt.jpg isn't loading." << endl;
	}
	textures.push_back(haibt);

	sf::Texture hamilton;
	if(!hamilton.loadFromFile("pics/hamilton.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! hamilton.jpg isn't loading." << endl;
	}
	textures.push_back(hamilton);

	sf::Texture holberton;
	if(!holberton.loadFromFile("pics/holberton.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! holberton.jpg isn't loading." << endl;
	}
	textures.push_back(holberton);

	sf::Texture hopper;
	if(!hopper.loadFromFile("pics/hopper.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! hopper.jpg isn't loading." << endl;
	}
	textures.push_back(hopper);

	sf::Texture keller;
	if(!keller.loadFromFile("pics/keller.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! bartik.jpg isn't loading." << endl;
	}
	textures.push_back(keller);

	sf::Texture liskov;
	if(!liskov.loadFromFile("pics/liskov.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! liskov.jpg isn't loading." << endl;
	}
	textures.push_back(liskov);

	sf::Texture lovelace;
	if(!lovelace.loadFromFile("pics/lovelace.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! lovelace.jpg isn't loading." << endl;
	}
	textures.push_back(lovelace);

	sf::Texture meltzer;
	if(!liskov.loadFromFile("pics/meltzer.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! meltzer.jpg isn't loading." << endl;
	}
	textures.push_back(meltzer);

	sf::Texture perlman;
	if(!liskov.loadFromFile("pics/perlman.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! perlman.jpg isn't loading." << endl;
	}
	textures.push_back(perlman);

	sf::Texture rhodes;
	if(!rhodes.loadFromFile("pics/rhodes.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! rhodes.jpg isn't loading." << endl;
	}
	textures.push_back(rhodes);

	sf::Texture sammet;
	if(!sammet.loadFromFile("pics/sammet.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! sammet.jpg isn't loading." << endl;
	}
	textures.push_back(sammet);

	sf::Texture spence;
	if(!spence.loadFromFile("pics/spence.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! spence.jpg isn't loading." << endl;
	}
	textures.push_back(spence);

	sf::Texture teitelbaum;
	if(!teitelbaum.loadFromFile("pics/teitelbaum.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! teitelbaum.jpg isn't loading." << endl;
	}
	textures.push_back(teitelbaum);

	
	sf::Texture back;
	if(!back.loadFromFile("pics/back.jpg", sf::IntRect(0, 0, card_w, card_h))) {
		cout << "Error! back.jpg isn't loading." << endl;
	}

	/****** TRANSFORM STUFF HERE *******/
	sf::Transform half;
	half.scale(FACTOR, FACTOR); 

	/****** TEXT STUFF HERE ************/
	sf::Font font;
	if (!font.loadFromFile("Aileron/Aileron-Regular.ttf")) {
		cout << "Error loading font" << endl;
	}
	sf::Text p1_txt;
	//select the font
	p1_txt.setFont(font);
	//set the string to display 
	p1_txt.setString("Player 1's Turn");
	//set the character size
	p1_txt.setCharacterSize(24); //in pixels, not points
	//set color
	p1_txt.setFillColor(sf::Color::Magenta);
	//set the text style
	p1_txt.setStyle(sf::Text::Bold);
	//setting location
	p1_txt.setPosition(875, 0);

	sf::Text p2_txt;
	//select the font
	p2_txt.setFont(font);
	//set the string to display 
	p2_txt.setString("Player 2's Turn");
	//set the character size
	p2_txt.setCharacterSize(24); //in pixels, not points
	//set color
	p2_txt.setFillColor(sf::Color::Magenta);
	//set the text style
	p2_txt.setStyle(sf::Text::Bold);
	//setting location
	p2_txt.setPosition(875, 0);

	bool repick = false;
	bool is_match = false;
    /* MAIN SFML PROGRAM LOOP */
    while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window); // window is a sf::Window

				// transform the mouse position from window coordinates to world coordinates
    			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				for (int i = 0; i < num_cards; i ++) {
					for (int j = 0; j < num_cards; j++) {
						sf::FloatRect boundingBox = matrix[i][j] -> getSprite().getGlobalBounds();
						// if (matrix[i][j] -> sprite.getGlobalBounds().contains(mousePos))
						if (boundingBox.contains(mouse))
						{

							cout << "Our click happened in matrix[" << i << "][" << j << "]!!!" << endl;
							if(!(find(matches_found.begin(), matches_found.end(), matrix[i][j]->getFront()) != matches_found.end())) {
								if(cards_clicked == 0) {
									first_index = matrix[i][j]->getFront();
									first_i = i;
									first_j = j;
								}
								else if(cards_clicked == 1) {
									second_index = matrix[i][j]->getFront();
									second_i = i;
									second_j = j;
								}
								matrix[i][j]->flip();
								matrix[i][j] -> getSprite().setTexture(textures[matrix[i][j]->getFront()]);
								//repick = false;

								cards_clicked = cards_clicked + 1;
							}

						}
					}
				}



			}
		}

			window.clear(sf::Color::White);
            if(player_turn == 1) {
				window.draw(p1_txt);
			}
			else {
				window.draw(p2_txt);
			}
			set_cards("female_cs.txt");
			int ctr = 0;
			is_match = false;
			if(cards_clicked >= 2) {

				cards_clicked = 0;
				if(first_i == second_i && first_j == second_j) {
					cout << "Same card! Pick again" << endl;
					cards_clicked = 1;
					repick = true;
				}
					
				
				else if(first_index != second_index) {
					cout << "Cards don't match" << endl;
			
					if(matrix[first_i][first_j]->is_flipped) {
						matrix[first_i][first_j] -> getSprite().setTexture(textures[first_index]);
					}
					else {
						matrix[first_i][first_j] -> getSprite().setTexture(back);
					}
					
					matrix[second_i][second_j] -> getSprite().setTexture(textures[second_index]);
					
					if(player_turn == 1) {
						player_turn = 2;
						cout << "Changing to player 2" << endl;
						window.draw(p2_txt);
					}
					else {
						player_turn = 1;
						cout << "Changing to player 1" << endl;
						window.draw(p1_txt);
					}
					matrix[second_i][second_j] -> getSprite().setTexture(textures[second_index]);
					window.draw(matrix[second_i][second_j]->getSprite());
					
				}
				else {
					cout << "Cards match!" << endl;
					matches_found.push_back(first_index);
					
					if(player_turn == 1) {
						player1_pile += 1;
						cout << "Added to player 1's pile" << endl;
						window.draw(p1_txt);

					}
					else {
						player2_pile += 1;
						cout << "Added to player 2's pile" << endl;
						window.draw(p2_txt);
					}
					is_match = true;

				}
				cout << endl;
				if(player_turn == 1) {
					window.draw(p1_txt);
				}
				else {
					window.draw(p2_txt);
				}
				if(!is_match) {
					for (int i = 0; i < num_cards; i ++) {
						for (int j = 0; j < num_cards; j++) {
							set_buffer(4);
							const float x = set_card_h(i);
							const float y = set_card_w(j);
							matrix[i][j]->set_coords(x, y);
							
							if(matrix[i][j]->is_flipped) {
								matrix[i][j] -> getSprite().setTexture(textures[matrix[i][j]->getFront()]);
							}
							else {
								matrix[i][j] -> getSprite().setTexture(back);
							}
							(matrix[i][j] -> getSprite()).setPosition(sf::Vector2f(x, y));
							ctr += 1;
							window.draw(matrix[i][j] -> getSprite(), half);
						}
					}
					window.display();
					usleep(1000000);
					matrix[second_i][second_j]->flip();
					matrix[first_i][first_j]->flip();
				}
			}
			
			ctr = 0;
			if(player_turn == 1) {
				
				window.draw(p1_txt);

			}
			else {
				
				window.draw(p2_txt);
			}
			for (int i = 0; i < num_cards; i ++) {
				for (int j = 0; j < num_cards; j++) {
					set_buffer(4);
					const float x = set_card_h(i);
					const float y = set_card_w(j);
					matrix[i][j]->set_coords(x, y);
					
					if(matrix[i][j]->is_flipped) {
						matrix[i][j] -> getSprite().setTexture(textures[matrix[i][j]->getFront()]);
					}
					else {
						matrix[i][j] -> getSprite().setTexture(back);
					}
					(matrix[i][j] -> getSprite()).setPosition(sf::Vector2f(x, y));
					ctr += 1;
					window.draw(matrix[i][j] -> getSprite(), half);
				}
			}
			window.display();
	if (matches_found.size() >= 8) {
		cout << endl << "Player 1 had " << player1_pile << " matches!" << endl;
		cout << "Player 2 had " << player2_pile << " matches!" << endl << endl;
		if(player1_pile > player2_pile) {
			cout << "Player 1 WINS!" << endl << endl;
		}
		else {
			cout << "Player 2 WINS!" << endl << endl;
		}
		break;
		}
	} 
}

int BoardType::runGame()
{

	sfml_driver();

    return 0;
}
