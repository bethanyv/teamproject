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

using namespace std;

//Kristine 3/1 - added more includes.
// Bethany 3/5 edited pileType class, added add_to_pile

class CardType{
public:
    CardType();
    // default destructor
    //TODO constructor to pass in an index into the jpeg vector
    bool is_flipped;
    int front; // index into jpeg vector
    int back; // card_type_vector[0]
    void flip();
    void check_match();
    // TODO: add pair
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
    virtual void setType(int);
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
    // for when the user does specify the size
    BoardType(int size); 

    vector<CardType> matrix;
    vector<CardType> placed_cards_array;

    void init();
    void set_card();
    // in update board, update the screen too
    void update_board();
    void is_full();
    void remove_match();
};

class GameType{
public:
    GameType();
    // default destructor

    BoardType board;

    PlayerType player1;
    PlayerType player2;

    // need if's in the run_game() to determine what type players are ->
    int runGame();
};

#endif /* MATCH_HPP_ */
