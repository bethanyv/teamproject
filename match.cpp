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

//ALSO: I remembered wnhy there is a black space to the right!
//
//I wanted to make sure that we had a place to display the Player Piles (with the matches they found)
//We originally had those piles on the bottom but we do not have very much vertical real estate
//so I thought we could change it to displaying that info on the right hand side

void PileType::add_to_pile(CardType card) {
	// add to number of cards matched and to the 
	// vector of which card was matched
	num_matched += 1;
	matches.push_back(card);
}

//CardType::CardType() {
CardType::CardType(int index) : front(index) {
	//is flipped - false: back.jpg
	//is flipped - true: face
	bool is_flipped = false;
	const string back = "pics/back.jpg";
	//string* front = fr;

	try {
	sprite = new sf::Sprite;
	}
	catch (bad_alloc& ba) {
		cout << "bad_alloc caught: " << ba.what() << endl;
	}
	

	// sf::Texture* back_texture = new sf::Texture;
	// if(!back_texture->loadFromFile("pics/back.jpg", sf::IntRect(0, 0, width, height))) {
	// 	cout << "Error! back.jpg isn't loading." << endl;
	// }
	// sf::Texture* front_texture = new sf::Texture;
	// if(!front_texture->loadFromFile("pics/meltzer.jpg", sf::IntRect(0, 0, width, height))) {
	// 	cout << "Error! back.jpg isn't loading." << endl;
	// }
	// sprite->setTexture(*back_texture);
	// back = texture;
	// front = texture;
}

sf::Sprite& CardType::getSprite() {
	return *sprite;
}

// this function compares coordinates. If two cards selected have the same 
// x and y, then it can't be selected again in sfml_driver where it's called
//  && card.getFront() == *front
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

PlayerType::PlayerType(int num) {
	number = num;
	PileType pile;
}

void BoardType::make_cards_to_place(const int amt) {
	auto size = cards_to_place.size();
	for(int i = 0; (cards_to_place.size() < (amt*2)); i ++) {
		cards_to_place.push_back(i);
		cards_to_place.push_back(i);
		//size = cards_to_place.size();
		//cout << "Index: " << index << endl;
		//cout << "Size of cards_to_place: " << size << endl;

	}
	random_shuffle(cards_to_place.begin(), cards_to_place.end());
}

BoardType::BoardType() {

	// PlayerType player1;
	// PlayerType player2;
	// player1.setType(1);
 // 	player2.setType(2);
	//makeFileList("female_cs.txt", pics);
	//cout << "Holding: " << pics[16] << endl;
	make_cards_to_place(8);
	//cout << cards_to_place[0] << endl;
	matrix.reserve(num_cards);
	random_shuffle(cards_to_place.begin(), cards_to_place.end());
	//cout << "Holding: " << cards_to_place[0] << endl;
	for (int i = 0; i < num_cards; i++) {
		matrix[i].reserve(num_cards);
		for (int j = 0; j < num_cards; j++) {
			//try {
		
			//cout << *cards_to_place.back() << endl;
		//	cout << *cards_to_place.back() << endl;
			try {
				CardType* card = new CardType(cards_to_place.back());
				cards_to_place.pop_back();
				matrix[i][j] = card;
			}
			catch (std::bad_alloc& ba)
			{
				cerr << "bad_alloc caught: " << ba.what() << endl;
			}
			//CardType* card = new CardType();
			/*cards_to_place.pop_back();*/
			//cout << card->getFront() << endl;
			// TODO Bethany set front
			//}
			//catch (exception& e)
			//{
			//	cout << "Standard exception: " << e.what() << endl;
			//}
			/*matrix[i][j] = card;*/
		}
	}

	// matrix2.resize(num_cards);
	// for (int i = 0; i < matrix2.size(); i++) {
	// 	matrix2[i].resize(num_cards);
	// }

	//placed_cards.reserve(num_cards);
	// empty = new CardType;
	// empty->set_file("pics/empty.png");
	// empty.set_file("pics/empty.png");
 //    empty.flip();
}

// GameType::GameType(){
// 	BoardType board;
// 	player1.setType(1);
// 	player2.setType(2);

// 	//importing 
// }

bool CardType::is_empty() {
	//if(front ==)
	return false;
}

int CardType::get_w() {
	return this -> width;
}

int CardType::get_h() {
	return this -> height;
}

bool CardType::check_match(CardType card) {
	return front == card.getFront();
    // return 0;
}

// void CardType::set_file(string file) {
// 	this -> file_name = file;
// }


// string CardType::getFile_name() {
// 	return *file_name;
// } 

int CardType::getFront() {
	return front;
}

void CardType::flip() {
	// Kristine TODO: add in set textures
	if(is_flipped) {
		//sprite->setTexture(*back_texture);
		//window.draw(matrix[i][j] -> getSprite());
		is_flipped = false;
		return;
	}
	else {
		//sprite->setTexture(*front_texture);
		//window.draw(matrix[i][j] -> getSprite());
		is_flipped = true;
		return;
	}
}

void PlayerType::move() {
    // return 0;
}

void AI::move() {
    // return 0;
}
int AI::random_pick() {
    return 0;
}

// do we need this function if we are just removing cards if they are a match?
void BoardType::update_board() {
    // return 0;
}
bool BoardType::is_empty() {
	// for(int i = 0; i < num_cards; i++) {
	// 	for(int j = 0; j < num_cards; j++) {
	// 		if(!(matrix[i][j]->getFront() == empty->getFront())) {
	// 			return false;
	// 		}
	// 	}
	// }
    return true;
}

// if remove match is found, we want to get rid of the card types
// remove comments once we get pics working
void BoardType::remove_match(CardType card) {
	// for(int i = 0; i < num_cards; i++) {
	// 	for(int j = 0; j < num_cards; j++) {
	// 		if(matrix[i][j]->getFront() == card.getFront()) {
	// 			matrix[i][j] = empty;
	// 		}
	// 	}
	// }
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

int BoardType::makeFileList(string filepath, vector<string> &name) {
    string line;
    ifstream myfile (filepath);
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
        //getline (myfile,line);
        //cout << line << endl;
            while(getline(myfile, line)){
                //cout << "In makeFileList and saving: " << line << endl;
				try {
					string* new_line = new string;
					new_line = &line;
					name.push_back(*new_line);
				}
				catch (bad_alloc& ba)
				{
					cerr << "bad_alloc caught: " << ba.what() << endl;
				}
				/*new_line = &line;*/
				//cout << "after mallocing, we get :" << new_line << endl;
				//cout << "Dereferencing that, we get: " << *new_line << endl;
                /*name.push_back(*new_line);*/
                // cout << "Pushed back: " << name.size() << endl;
            }
        }
        myfile.close();
    }
    // return 0;

  else cout << "Unable to open file";

  return 0;
}

vector<string*> BoardType::populate_random_vector() {
	vector<string*> place_holder;
	return place_holder;
}

int BoardType::randomNumber(int max) {
	//takes in max number
	// returns random number between 1 and max
	int num = 0;
	srand (time(NULL));
    num = (rand() % (max)); // + 1 here if it doesn't work
	return num;

}

// void BoardType::sfml_driver() {
// 	/*******************************************
//      * SFML Events Here
//      ******************************************/
// 	sf::RenderWindow window(sf::VideoMode(width, height), "A Matching Game");

//     //TODO GET RID OF TEMP TEXTURE PLACE HOLDER
//     sf::Texture texture;
// 	if(!texture.loadFromFile("pics/perlman.jpg", sf::IntRect(0, 0, card_w, card_h))) {
// 		cout << "Error! ada_lovelace.jpg isn't loading." << endl;
// 	}

//     /* MAIN SFML PROGRAM LOOP */
//     while (window.isOpen()) {
// 		sf::Event event;
// 		while (window.pollEvent(event)) {

// 			if (event.type == sf::Event::Closed) {
// 				window.close();
// 			}
// 			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				
// 				cout << "Found a mouse click!" << endl;

// 				sf::Vector2i mousePos = sf::Mouse::getPosition(window); // window is a sf::Window

// 				// transform the mouse position from window coordinates to world coordinates
//     			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
// 				for (int i = 0; i < num_cards; i ++) {
// 					for (int j = 0; j < num_cards; j++) {
// 						CardType cardd = *matrix[i][j];
// 						sf::FloatRect boundingBox = (cardd.getSprite()).getGlobalBounds();
// 						// if (matrix[i][j] -> sprite.getGlobalBounds().contains(mousePos))
// 						if (boundingBox.contains(mouse))
// 						{
// 							//TODO: BETHANY! We need to add logic here for what to do when we click 
// 							//on a specific card. YOu can find the card at matrix[i][j]
// 							cout << "Our click happened in matrix[" << i << "][" << j << "]!!!" << endl;

// 						}
// 					}
// 				}

// 			}
// 		}

// 			window.clear();
//             //window.draw(sprite1);

// 			set_cards("female_cs.txt");

// 			// for (int i = 0; i < num_cards; i++) {
// 			// 	for (int j = 0; j < num_cards; j++) {
// 			// 		window.draw(matrix[i][j] -> sprite);
// 			// 	}
// 			// }

// 			//sprite1.setPosition(sf::Vector2f(this -> set_CARD_W.f, 10.f));
// 			// int x = set_card_w(0);
// 			// sprite1.setPosition(sf::Vector2f(x, 10.f));
// 			// window.draw(sprite2);
// 			// x = set_card_w(1);
// 			// sprite2.setPosition(sf::Vector2f(x, 10.f));
// 			// window.draw(sprite3);
// 			// x = set_card_w(2);
// 			// sprite3.setPosition(sf::Vector2f(x, 10.f));
// 			// window.draw(sprite4);
// 			// x = set_card_w(3);
// 			// sprite4.setPosition(sf::Vector2f(x, 10.f));
			
// 			// //vertical
// 			// window.draw(sprite5);
// 			// sprite5.setPosition(sf::Vector2f(10.f, 170.f));
// 			// window.draw(sprite6);
// 			// sprite6.setPosition(sf::Vector2f(10.f, 330.f));
// 			// window.draw(sprite7);
// 			// sprite7.setPosition(sf::Vector2f(10.f, 490.f));


// 			for (int i = 0; i < num_cards; i ++) {
// 				for (int j = 0; j < num_cards; j++) {
// 					CardType cardd = *matrix[i][j];
// 					(cardd.getSprite()).setTexture(texture);
// 					set_buffer(4);
// 					const float x = set_card_h(i);
// 					const float y = set_card_w(j);

// 					//KRISTINE TODO: save x and y into that specific card

// 					(cardd.getSprite()).setPosition(sf::Vector2f(x, y));

// 					window.draw(matrix[i][j] -> getSprite());
// 				}
// 			}
// 			window.display();
// 	}
// }

void BoardType::sfml_driver() {
	/*******************************************
     * SFML Events Here
     ******************************************/
	sf::RenderWindow window(sf::VideoMode(width, height), "A Matching Game");
	//window.setFramerateLimit(60);
	int player_turn = 1;
	int cards_clicked = 0;
	std::vector<CardType*> cards_selected;
	vector<sf::Texture> textures;

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
    //TODO GET RID OF TEMP TEXTURE PLACE HOLDER
 //    sf::Texture texture;
	// if(!texture.loadFromFile("pics/perlman.jpg", sf::IntRect(0, 0, card_w, card_h))) {
	// 	cout << "Error! ada_lovelace.jpg isn't loading." << endl;
	// }
 //    sf::Texture texture2;
	// if(!texture2.loadFromFile("pics/lovelace.jpg", sf::IntRect(0, 0, card_w, card_h))) {
	// 	cout << "Error! ada_lovelace.jpg isn't loading." << endl;
	// }
 //    sf::Texture texture3;
	// if(!texture3.loadFromFile("pics/meltzer.jpg", sf::IntRect(0, 0, card_w, card_h))) {
	// 	cout << "Error! ada_lovelace.jpg isn't loading." << endl;
	// }
 //    sf::Texture texture4;
	// if(!texture4.loadFromFile("pics/sammet.jpg", sf::IntRect(0, 0, card_w, card_h))) {
	// 	cout << "Error! ada_lovelace.jpg isn't loading." << endl;
	// }
	/****** TRANSFORM STUFF HERE *******/
	sf::Transform half;
	half.scale(0.5f, 0.5f); 
	/****** TEXT STUFF HERE ************/
	sf::Font font;
	if (!font.loadFromFile("Aileron/Aileron-Regular.ttf")) {
		cout << "Error loading font" << endl;
	}
	sf::Text p1_txt;
	//select the font
	p1_txt.setFont(font);
	//set the string to display 
	p1_txt.setString("Player 1");
	//set the character size
	p1_txt.setCharacterSize(24); //in pixels, not points
	//set color
	p1_txt.setFillColor(sf::Color::Magenta);
	//set the text style
	p1_txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//setting location
	p1_txt.setPosition(1000, 0);

	sf::Text p2_txt;
	//select the font
	p2_txt.setFont(font);
	//set the string to display 
	p2_txt.setString("Player 2");
	//set the character size
	p2_txt.setCharacterSize(24); //in pixels, not points
	//set color
	p2_txt.setFillColor(sf::Color::Magenta);
	//set the text style
	p1_txt.setStyle(sf::Text::Bold);
	//setting location
	p1_txt.setPosition(900, 0);


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
						sf::FloatRect boundingBox = matrix[i][j] -> getSprite().getGlobalBounds();
						// if (matrix[i][j] -> sprite.getGlobalBounds().contains(mousePos))
						if (boundingBox.contains(mouse))
						{

							cout << "Our click happened in matrix[" << i << "][" << j << "]!!!" << endl;
							cout << matrix[i][j]->getFront() << endl;
							matrix[i][j]->flip();
							// now have flip(), so it should update automatically?
							//cout << "Flipped card at [" << i << "][" << j << "]!!!" << endl;
							cards_selected.push_back(matrix[i][j]);
							cards_clicked = cards_clicked + 1;
							cout << "Cards clicked: " << cards_clicked << endl;

						}
					}
				}


			}
		}

			window.clear(sf::Color::White);
            //window.draw(sprite1);
			window.draw(p1_txt);
			window.draw(p2_txt);
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

			// >= because it clicks seem inconsistent?
			if(cards_clicked >= 2) {
				cout << "Cards clicked is 2" << endl;
				cards_clicked = 0;
				// if(cards_selected[0]->is_same_card(*cards_selected[1])) {
				// 	// TODO HERE: CHANGE TO PICKING A DIFFERENT CARD FOR 2ND
				// 		cout << "Same card! Pick again" << endl;
				// 		//cards_selected[0]->flip();
				// 		cards_selected.erase(cards_selected.begin()+1, cards_selected.end());
				// 		cards_clicked -= 1;
				// 		continue;
				// 	}
					
				
				if(!(cards_selected[0])->check_match(*cards_selected[1])) {
					cout << "Cards don't match" << endl;
					// if the cards don't match, flip them back over
					cards_selected[0]->flip();
					window.draw(cards_selected[0] -> getSprite());
					cards_selected[1]->flip();
					
					window.draw(cards_selected[1] -> getSprite());
					if(player_turn == 1) {
						player_turn = 2;
						cout << "Changing to player 2" << endl;
					}
					else {
						player_turn = 1;
						cout << "Changing to player 1" << endl;
					}
					
				}
				else {
					cout << "Cards match!" << endl;
					// TODO: Can't initialize player for some reason??? Uncomment out when can
					if(player_turn == 1) {
						//(player1.pile).add_to_pile(*cards_selected[0]);
						cout << "Added to player 1's pile" << endl;
					}
					else {
						//(player2.pile).add_to_pile(*cards_selected[0]);
						cout << "Added to player 2's pile" << endl;
					}
					// TODO: make sure this moves the cards
					//remove_match(cards_selected[0]);

				}
				cards_selected.clear();
			}
			cards_selected.clear();
			int ctr = 0;
			for (int i = 0; i < num_cards; i ++) {
				for (int j = 0; j < num_cards; j++) {
					set_buffer(4);
					const float x = set_card_h(i);
					const float y = set_card_w(j);
					matrix[i][j]->set_coords(x, y);
					//TODO: MAKE SURE THIS WORKS ^
					if(matrix[i][j]->is_flipped) {
						matrix[i][j] -> getSprite().setTexture(textures[matrix[i][j]->getFront()]);
					}
					else {
						matrix[i][j] -> getSprite().setTexture(back);
					}
					(matrix[i][j] -> getSprite()).setPosition(sf::Vector2f(x, y));
					ctr += 1;
					window.draw(matrix[i][j] -> getSprite());
				}
			}
			// for (int j = 0; j < num_cards; j++) {

			//matrix[1][2] -> getSprite().setTexture(textures[2]);
			// 	// matrix[2][j] -> getSprite().setTexture(texture3);
			// 	// matrix[3][j] -> getSprite().setTexture(texture4);
				
			//window.draw(matrix[1][2] -> getSprite());


			// 	window.draw(matrix[1][j] -> getSprite());
			// 	window.draw(matrix[2][j] -> getSprite());
			// 	window.draw(matrix[3][j] -> getSprite());
			// }
			window.display();
	}
}

//int GameType::runGame()
int BoardType::runGame()
{
	//this -> board.set_buffer(4);
	// board.set_cards("female_cs.txt");

	sfml_driver();

	// TODO HERE FIX: cout not even working?
	// cout << 5 << endl;
	// int num = randomNumber(15);

	// int size = 0;
	// while(size < 5) {
	// 	cout << randomNumber(15);
	// 	size++;
	// }

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
