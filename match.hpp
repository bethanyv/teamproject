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

class PileType{
public:
    PileType();
    // default destructor

    vector<CardType> matches;
    
    int num_matched;
    // in notes we said function call
    // but couldn't it just be an running total
    // with an int? Yes!

    // Maybe add in later a view for piletype
    void add_to_pile(CardType card);
    //TODO write a remove_card function
    //TODO Maybe add an init function to fill the board's pile?
};

class PlayerType {
public:
    PlayerType(int number);
    PlayerType();
    // default destructor

    int number; // number of player (player 1/player 2)
    PileType pile; // each player has a pile

    virtual void move(); // each player makes a move
    void setType(int num);
};

class AI : public PlayerType {
public:
    AI();
    // default destructor

    PileType pile;

    // memory of lastfour cards picked
    vector<CardType> last_four; 

    void move();
    int random_pick();

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
    int height =625;
    int width = 525;
    int buffer_w = 5;
    int buffer_h = 5;

    int card_w = 200;
    int card_h = 300;

    void init();
    int set_card_h(int x);
    int set_card_w(int y);
    void set_buffer(int num);
    void set_cards(string path);
    // in update board, update the screen too
    void update_board();
    bool is_empty();
    void make_cards_to_place(const int amt);
    void remove_match(CardType card);
    void sfml_driver();
    vector<string*> populate_random_vector();


    int makeFileList(string filepath, vector<string> &name);
    //string randomFileName(vector<string> &name, int max);
    int randomNumber(int max);
    int runGame();
};

// class GameType{
// public:
//     GameType();
//     // default destructor

//     BoardType board;

//     PlayerType player1;
//     PlayerType player2;

//     vector<CardType> all_cards;

//     // need if's in the run_game() to determine what type players are ->
//     int runGame();
// };

#endif /* MATCH_HPP_ */
