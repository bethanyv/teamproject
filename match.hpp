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

    sf::Sprite& getSprite();
    string getFile_name();
    void flip();
    int get_w();
    int get_h();
    int get_x();
    int get_y();
    int getFront();
    bool check_match(CardType card);
    bool is_same_card(CardType card);
    sf::Sprite* sprite;

    bool is_flipped;
    // call set_coords when placing a card so we know where it is
    void set_coords(int x, int y);
    

private:
    int front;

    int width = 200;
    int height = 300;
    int x_coord = 0;
    int y_coord = 0;

};

class BoardType{
public:
    BoardType(); 

    int num_cards = 4;

    vector<vector<CardType*> > matrix;
    vector<int> cards_to_place;
    vector<string> pics;

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
    int randomNumber(int max);
    int runGame();
};

#endif /* MATCH_HPP_ */
