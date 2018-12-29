#include <vector>
#include <string>
using namespace std;


class NumInsultsOutOfBounds {
public:
	string what();  // Message when insults requested is out of bounds
};


class FileException {
public:
	string what();
};


class InsultGenerator {
public:
	void initialize();  // Reads insults and stores them into 3 vectors
	string talkToMe();  // Returns a single insult
	vector<string> generate(unsigned int num);  // Returns vector with num insults in alphabetical order
	void generateAndSave(string fileName, unsigned int num);  // Stores num random insults into file in alphabetical order

private:
	// 3 vectors for storing the 3 different columns of insults
	vector<string> x;
	vector<string> y;
	vector<string> z;
};
