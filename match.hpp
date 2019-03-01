#ifndef MATCH_HPP_
#define MATCH_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PileType{
public:
    PileType();
    // default destructor

    vector<CardType> matches;
    
    int num_matched;
    // in notes we said function call
    // but couldn't it just be an running total
    // with an int? Yes!
    void total_cards_matched();
};

class PlayerType{
    PlayerType();
    // default destructor

    int number; // number of player (player 1/player 2)
    PileType pile; // each player has a pile

    virtual void move(); // each player makes a move
};

class AI : public PlayerType {
public:
    AI();
    // default destructor

    PileType pile;
    
    // memory of last four cards picked
    vector<CardType> last_four(4); 

    void move();
    int random_pick();

};

class CardType{
public:
    CardType();
    // default destructor

    bool is_flipped;
    int front; // index into card_type vector
    int back; // card_type_vector[0]
    void flip();
    void check_match();
    // TODO: add pair
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
    int size;

    BoardType board();

    PlayerType player1;
    PlayerType player2;

    // need if's in the run_game() to determine what type players are ->
    void run_game();
};

#endif /* IOUTILS_HPP_ */
