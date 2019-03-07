#include "match.hpp"
#include <ctime>
#include <cstdlib>
#include <cstdio>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// class IOUtils {
// public:
// 	IOUtils();
// 	virtual ~IOUtils();

// 	// If no argument given, open standard in
// 	void openStream(int argc, const char *argv[]);

// 	// Close the input stream
// 	void closeStream();

// 	// Read from the open input stream and return the contents as a string
// 	std::string readFromStream();

// 	// Get the currently open input stream
// 	std::istream getStream();
// private:
// 	bool isFile;
// 	std::istream *inputStream;
// };

IOUtils::IOUtils() : isFile(false), inputStream(& std::cin) {
	// By default, read from standard input (cin)
}

IOUtils::~IOUtils() {
	this->closeStream();
}

void
IOUtils::openStream(int argc, const char *argv[]) {
	// If a file name is given read from file instead of standard input
	if( argc == 2 ) { //checks for an optional input file name
		inputStream = new std::ifstream( argv[1] );	// open the input file
		isFile = true;
	} else {
		std::cout << "Please type some text to encrypt." << std::endl <<
				"To finish, type CTRL-D on a new line (or CTRL-Z in Windows)." << std::endl;
		inputStream = & std::cin;
		isFile = false;
	}
}

void
IOUtils::closeStream() {
	if (isFile && inputStream != NULL) {
		std::ifstream *fstr = dynamic_cast<std::ifstream *>(inputStream);
		if (fstr != NULL) {
			if (fstr->is_open())
				fstr->close();
			delete fstr;
		}
	}
	inputStream = NULL;
	// if it's not a file (i.e., the stream is cin), don't close it
}

std::string
IOUtils::readFromStream() {
	std::string theInput;
	char ch;

	*(this->inputStream) >> std::noskipws;  // disable skipping of whitespace
	while ( ! this->inputStream->eof() ) {
		*(this->inputStream) >> ch;
	    theInput += ch;
	}

	return theInput;
}

int IOUtils::makeFileList(string filepath, vector<string> &name) {
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
                //cout << line << endl;
                name.push_back(line);
            }
        }
        myfile.close();
    }
    // return 0;

  else cout << "Unable to open file";

  return 0;

}

string IOUtils::randomFileName(vector<string> &name) {
    string pic;
    int num = 0;
    /* initialize random seed: */
    srand (time(NULL));
    num = rand() % 1000 + 1;

    //cout << "Num is: " << num << " and we have a total of " << name.size() << endl;
    //cout << "Random word in file: " << name[num] << endl;
    word = name[num];
    return pic;
}