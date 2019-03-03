#include "match.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <cstddef>  
#define USEDEBUG

#ifdef USEDEBUG
#define DEBUG(X) cout << #X << ": " << (X) << endl;
#else
#define DEBUG(X)
#endif

using namespace std;


int main(int argc, char const *argv[])
{
	// BoardType myboard;
	GameType game;

	game.runGame();
	return 0;
}