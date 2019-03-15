#ifndef MATCH_HPP_
#define MATCH_HPP_


#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> // Stream declarations
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <cstddef>  // For size_t
#include <cstdio>
#include <ctime>

#define FACTOR 1

using namespace std;

//Kristine 3/1 - added more includes.
// Bethany 3/5 edited pileType class, added add_to_pile
// Kristine 3/6 added random file call. seg faulting trying to add the string to our matrix vector. not sure why.

class CardType{
public:
    CardType(int index);
    //CardType();
    // default destructor
    //TODO constructor to pass in an index into the jpeg vector

    // Added is_same_card to compare the two cards with x & y positions,
    // just don't have the x & y built in yet
    sf::Sprite& getSprite();
    string getFile_name();
    void flip();
    int get_w();
    int get_h();
    int get_x();
    int get_y();
    // TODO Bethany
    bool is_empty();
    void set_file(string file);
    int getFront();
    bool check_match(CardType card);
    bool is_same_card(CardType card);
    sf::Sprite* sprite;
    //sf::Texture* back_texture;
    //sf::Texture* front_texture;
    bool is_flipped;
    // call set_coords when placing a card so we know where it is
    void set_coords(int x, int y);
    

private:
    int front; // index into jpeg vector
    //const string back; // card_type_vector[0]

    string file_name;
    //sf::Sprite sprite;
    int width = 200;
    int height = 300;
    // TODO: add pair
    int x_coord = 0;
    int y_coord = 0;

};

class BoardType{
public:
    // for when the user doesn't specify a size
    BoardType(); 

     // I think it's easier to have this represent
    // The cards per row (aka 4) rather than
    // the total number of cards on teh board
    int num_cards = 4;

    // changing both of these vectors to a 2D vector of strings
    // BUT might need to change back to CardType
    //vector<vector<string> > matrix(num_cards, vector<string> matrix_r(num_cards, "pics/back.jpg"));

    // TODO: can't get playertypes to work??????
    //PlayerType player1;
    //PlayerType player2;

    // TODO: keep getting seg faults when uncommenting this?
    //CardType* empty;

    vector<vector<CardType*> > matrix;
    vector<vector<int> > matrix2;
    vector<int> cards_to_place;
    vector<string> pics;

    //sf::Texture back;
    //int player_turn;

    //window height/width
    float height = 1250 * FACTOR;
    float width = 1050 * FACTOR;
    float buffer_w = 10 * FACTOR;
    float buffer_h = 10 * FACTOR;

    float card_w = 200 * FACTOR;
    float card_h = 300 * FACTOR;

    void init();
    float set_card_h(int x);
    float set_card_w(int y);
    void set_buffer(int num);
    void set_cards(string path);

    void make_cards_to_place(const int amt);
    void sfml_driver();


    int makeFileList(string filepath, vector<string> &name);
    //string randomFileName(vector<string> &name, int max);
    int randomNumber(int max);
    int runGame();
};

#endif /* MATCH_HPP_ */
