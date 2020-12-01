// Advent of Code
// Day 1: Report Repair - Part 2/2
//
// Submission by S4kyt

#include <iostream>
#include <fstream>
#include <string>

int main() {

	// 1. Open input.txt
	// 2. Read lines, parse into inputArray
	// 3. Output array to check its working correctly
	std::ifstream inputFile;
	std::string inputLine;

	int inputFileLength = 0;

	int inputArray[200];

	inputFile.open("src/01/input.txt", std::ifstream::in);
	if (inputFile.is_open()) {
		while (std::getline(inputFile, inputLine)) {
			std::cout << inputLine << '\n';
			// std::stoi used for converting strings into integers
			inputArray[inputFileLength] = std::stoi(inputLine);
			inputFileLength++;
		}
		inputFile.close();
	}
	else {
		std::cout << "Failed to load input.txt" << std::endl;
	}

	// Start + End pointers for comparison
	int* startPtr = &inputArray[0];
	int* endPtr = &inputArray[199];

	// Looping through the array with pointers
	int* currentPtr = &inputArray[0];
	int* nextPtr = &inputArray[0];
	int* lastPtr = &inputArray[0];

	int secondAnswerSum = 0;

	while (secondAnswerSum != 2020) {

		secondAnswerSum = *currentPtr + *nextPtr + *lastPtr;

		if (secondAnswerSum == 2020) {
				std::cout << '\n';
				std::cout << *currentPtr << " + " << *nextPtr << " + " << *lastPtr << std::endl;
				std::cout << '\n';
				std::cout << "Answer found!*NOMS * Calendar chocolate!" << std::endl;
				std::cout << "Day 1 - Challenge 2 / 2 - Completed!" << std::endl;

				int secondCalendarKey = (*currentPtr) * (*nextPtr) * (*lastPtr);

				std::cout << '\n';
				std::cout << "The answer ultimately is: " << secondCalendarKey << std::endl;
				break;
		}

		// In this order:
		// 1. currentPtr
		// 2. nextPtr
		// 3. lastPtr
		if (currentPtr == endPtr) {
			if (nextPtr == endPtr) {
				lastPtr++;
				nextPtr = startPtr;
				currentPtr = startPtr;
				if (lastPtr == endPtr) {
					std::cout << "lastPtr reached the nullptr." << std::endl;
				}
			}
			nextPtr++;
			currentPtr = startPtr;
		}
		currentPtr++;
	}
	return 0;
}