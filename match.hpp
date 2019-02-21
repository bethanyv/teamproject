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
    
    // in notes we said function call
    // but couldn't it just be an running total
    // with an int?
    void total_cards_matched();
};

class PlayerType{
    PlayerType();
    // default destructor

    int number;
    PileType pile;

    virtual void move();
};

class AI : public PlayerType{
public:
    AI();
    // default destructor

    PileType pile;
    //TODO add memory?

    void move():
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
    // I don't know what type -> (int, int) pair was ...
};

class BoardType{
public:
    BoardType();
    // default destructor

    vector<CardType> matrix;
    vector<CardType> placed_cards_array;

    void init();
    void set_card();
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
    // TODO add AI stuff???

    void run_game();
};

