#include "insultgenerator_15ds73.h"
#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;


string NumInsultsOutOfBounds::what() {
	return "Number of insults is out of bounds (legal range is 1 - 10000)";  // Printing error message
}


string FileException::what() {
	return "File not found or could not be opened";  // Printing error message
}


void InsultGenerator::initialize() {
	ifstream fileIn("InsultsSource.txt");  // Opening insult file

	if(fileIn.fail())  // Checking if file was opened properly
		throw FileException();

	string colOne, colTwo, colThree;  // Vars to store insults while being parsed

	while(!fileIn.eof()) {  // Filling 3 column vectors
		getline(fileIn, colOne, '\t');
		x.push_back(colOne);  // Storing insult into column one vector
		getline(fileIn, colTwo, '\t');
		y.push_back(colTwo);  // Storing insult into column two vector
		getline(fileIn, colThree, '\n');
		z.push_back(colThree);  // Storing insult into column three vector
	}
	fileIn.close();  // Closing file
}


// Function to check if an insult is already present in the list | Returns true if not found, false found
bool checkInsults(vector<string> prev_insults, string insult) {
	unsigned int i;
	for(i = 0; i < prev_insults.size(); i++) {
		if(prev_insults.at(i) == insult)
			return false;
	}
	return true;
}


string InsultGenerator::talkToMe() {
	string insult = "Thou ";  // Output string
	srand(time(0));
	// Generating 3 random indices to compile insult from
	insult += x.at(rand()%50) + " " +  y.at(rand()%50) + " " +  z.at(rand()%50) + "!";

	return insult;
}


vector<string> InsultGenerator::generate(unsigned int num) {
	vector<string> insults;  // Array to store generated insults
	string current;  // Current insult generated

	if(num < 1 || num > 10000)  // Checking to see if number of insults requested is proper
		throw NumInsultsOutOfBounds();

	while(insults.size() < num) {  // Appending insults into array
		current = "Thou " + x.at(rand()%50) + " " +  y.at(rand()%50) + " " +  z.at(rand()%50) + "!";
		if(checkInsults(insults, current))  // Checking if insult was previously generated
			insults.push_back(current);
	}
	sort(insults.begin(), insults.end());  //Sorting the list

	return insults;
}


void InsultGenerator::generateAndSave(string fileName, unsigned int num) {
	vector<string> insult_list = generate(num);  // Generating the required amount of insults
	ofstream inFile(fileName);

	unsigned int i;
	for(i = 0; i < insult_list.size(); i++) {  // Appending insults into file
		inFile << insult_list.at(i) << endl;
	}
}




