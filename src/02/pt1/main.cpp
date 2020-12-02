// Advent of Code
// Day 2: Password Philosophy - Part 1/2
//
// Submission by S4kyt

#include <iostream>
#include <fstream>
#include <string>

int main() {

	// 1. Get input
	std::ifstream inputFile;
	std::string inputLine;

	int inputFileLength = 0;

	int inputArray[1000];

	inputFile.open("src/02/input.txt", std::ifstream::in);
	if (inputFile.is_open()) {
		while (std::getline(inputFile, inputLine)) {
			inputArray[inputFileLength] = std::stoi(inputLine);
			inputFileLength++;

			if (isdigit(inputArray[inputFileLength]))
			{
				std::cout << inputLine;
			}
		}
		inputFile.close();
	}
	else {
		std::cout << "Failed to load input.txt" << std::endl;
	}
}