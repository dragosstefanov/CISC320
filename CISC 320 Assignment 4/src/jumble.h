// Name: Dragos Stefanov
// NetID: 15ds73

#ifndef JUMBLE_H_
#define JUMBLE_H_

#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>


class BadJumbleException {
public:
	BadJumbleException(const std::string&);
	std::string& what();
private:
	std::string message;
};


class JumblePuzzle {
public:
	JumblePuzzle(std::string hiddenWord, std::string difficulty);  // Standard constructor
	JumblePuzzle(JumblePuzzle&);  // Copy constructor
	JumblePuzzle& operator=(JumblePuzzle&);  // Assignment operator
	~JumblePuzzle();  // Destructor

	char** getJumble() { return puzzle; }
	const std::string& getHiddenWord() { return hiddenWord; }
	int getSize() { return pSize; }
	int getRowPos() { return rPos; }
	int getColPos() { return cPos; }
	char getDirection() { return direction; }

private:
	// Private attributes
	int diff;
	std::string hiddenWord;
	char** puzzle;
	int pSize;
	int rPos;
	int cPos;
	char direction;

	// Method to generate the puzzle
	static char** makePuzzle(int pSize, char direction, int rPos, int cPos, const std::string& hiddenWord);
	// Helper method to get direction
	static char setDirection(int rPos, int cPos, int pSize, const std::string& hiddenWord);
};


#endif /* JUMBLE_H_ */
