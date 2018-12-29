// Name: Dragos Stefanov
// NetID: 15ds73

#include "jumble.h"
#include <iostream>


BadJumbleException::BadJumbleException(const std::string& m) : message(m) {}
std::string& BadJumbleException::what() { return message; }


JumblePuzzle::JumblePuzzle(std::string hiddenWord, std::string difficulty) {
	//std::cout << "-----Constructor Test 1-----" << std::endl;
	// Setting difficulty level
	if (difficulty == "easy")
		this->diff = 2;
	else if (difficulty == "medium")
		this->diff = 3;
	else if (difficulty == "hard")
		this->diff = 4;
	else {  // Throwing invalid difficulty exception
		throw BadJumbleException("Invalid Difficulty: Please enter /easy/, /medium/ or /hard/");
	}

	//std::cout << "-----Constructor Test 2-----" << std::endl;
	int word_length = hiddenWord.length();

	// Checking for correct word length
	if (word_length < 3 || word_length > 10) {
		throw BadJumbleException("Invalid Word Length: Please enter a word that is between 3 - 10 characters");
	}
	for(int i = 0; i < word_length; i++) {
		if(hiddenWord[i] <= 'a' || hiddenWord[i] >= 'z') {
			throw BadJumbleException("Invalid Character: Only characters between a - z are allowed");
		}
	}

	this->pSize = diff * word_length;  // Setting puzzle size
	//std::cout << "-----Constructor Test 3-----" << std::endl;
	// Setting random position for hidden word

	this->rPos = std::rand() % pSize;

	this->cPos = std::rand() % pSize;
	// Setting direction
	this->direction = JumblePuzzle::setDirection(rPos, cPos, pSize, hiddenWord);
	//std::cout << "-----Constructor Test 4-----" << std::endl;
	this->puzzle = JumblePuzzle::makePuzzle(pSize, direction, rPos, cPos, hiddenWord);
	//std::cout << "-----Constructor Test 5-----" << std::endl;
}


JumblePuzzle::JumblePuzzle(JumblePuzzle& right) {
	this->diff = right.diff;
	this->hiddenWord = right.hiddenWord;
	this->pSize = right.pSize;
	this->rPos = right.rPos;
	this->cPos = right.cPos;
	this->direction = right.direction;

	this->puzzle = new char*[pSize];
	for(int i = 0; i < pSize; i++) {
		puzzle[i] = new char[pSize];
		for(int j = 0; j < pSize; j++) {
			puzzle[i][j] = right.puzzle[i][j];
		}
	}
}


JumblePuzzle& JumblePuzzle::operator=(JumblePuzzle& right) {
	if (this == &right) {
		return right;
	}
	for(int i = 0; i < pSize; i++) {
		char* x = this->puzzle[i];
		delete[] x;
	}
	delete this->puzzle;

	this->diff = right.diff;
	this->hiddenWord = right.hiddenWord;
	this->pSize = right.pSize;
	this->rPos = right.rPos;
	this->cPos = right.cPos;
	this->direction = right.direction;

	this->puzzle = new char*[pSize];
	for(int i = 0; i < pSize; i++) {
		puzzle[i] = new char[pSize];
		for(int j = 0; j < pSize; j++) {
			puzzle[i][j] = right.puzzle[i][j];
		}
	}

	return *this;
}


JumblePuzzle::~JumblePuzzle() {
	for(int i = 0; i < pSize; i++) {
		char* x = this->puzzle[i];
		delete[] x;
	}
	delete[] this->puzzle;
}


 char** JumblePuzzle::makePuzzle(int pSize, char direction, int rPos, int cPos,
		 	 	 	 	 	 	 const std::string& hiddenWord) {
	 //std::cout << "-----makePuzzle Test 1-----" << std::endl;
	 int word_length = hiddenWord.length();
	 char** puzzle = new char*[pSize];
	 //std::cout << "-----makePuzzle Test 2-----" << std::endl;
	 //std::cout << "-----makePuzzle pSize: " << pSize << "-----" << std::endl;
	 // Making the puzzle
	 for(int i = 0; i < pSize; i++) {
		 puzzle[i] = new char[pSize];
		 //std::cout << "For loop Test" << std::endl;
		 //std::cout << i << std::endl;
		 for(int j = 0; j < pSize; j++) {
			 char rand_letter = std::rand() % 26 + 'a';
			 puzzle[i][j] = rand_letter;
		 }
		 //std::cout << "End of primary loop" << std::endl;
	 }
	 //std::cout << "-----makePuzzle Test 3-----" << std::endl;
	 // Adding word to puzzle
	 if (direction == 'n') {
		 for(int y = 0; y < word_length; y++) {
			 puzzle[rPos][cPos - y] = hiddenWord[y];
		 }
	 } else if (direction == 'e') {
		 for(int x = 0; x < word_length; x++) {
			 puzzle[rPos + x][cPos] = hiddenWord[x];
		 }
	 } else if (direction == 's') {
		 for(int y = 0; y < word_length; y++) {
			 puzzle[rPos][cPos + y] = hiddenWord[y];
		 }
	 } else if (direction == 'w') {
		 for(int x = 0; x < word_length; x++) {
			 puzzle[rPos - x][cPos] = hiddenWord[x];
		 }
	 }
	 //std::cout << "-----makePuzzle Test-----" << std::endl;
	 return puzzle;
 }


char JumblePuzzle::setDirection(int rPos, int cPos, int pSize, const std::string& hiddenWord) {
	//std::cout << "-----setDirection Test 1-----" << std::endl;
	int dirs[4] = {1, 1, 1, 1};  // Possible direction {N, E, S, W}
	int word_length = hiddenWord.length();
	if (cPos < word_length - 1)
		dirs[0] = 0;  // Can't go North
	if (rPos > pSize - word_length)
		dirs[1] = 0;  // Can't go East
	if (cPos > pSize - word_length)
		dirs[2] = 0;  // Can't go South
	if (rPos < word_length)
		dirs[3] = 0;  // Can't go West

	int rand_dir = std::rand() % 4;

	//std::cout << "-----setDirection Test 2-----" << std::endl;
	//std::cout << rand_dir << std::endl;

	//std::cout << "-----setDirection Test 3-----" << std::endl;
	//for(int i = 0; i < 4; i++) {
	//	std::cout << dirs[i] << std::endl;
	//}
	// Iterating through possible directions to check if random direction is possible
	while(dirs[rand_dir] == 0) {
		if (rand_dir == 3) {
			rand_dir = 0;
		}
		else {
			rand_dir++;
		}
	}
	//std::cout << "-----setDirection Test 4-----" << std::endl;
	//std::cout << rand_dir << std::endl;
	if (rand_dir == 0)
		return 'n';
	else if (rand_dir == 1)
		return 'e';
	else if (rand_dir == 2)
		return 's';
	else
		return 'w';
}
