// Advent of Code
// Day 1: Report Repair
//
// Submission by S4kyt

#include <iostream>
#include <fstream>
#include <string>

int main() {

	// 1. Open input.txt
	// 2. Read lines, parse into inputArray
	// 3. Output array to check
	std::ifstream inputFile;
	std::string inputLine;

	int inputFileLength = 0;

	int inputArray[200];

	inputFile.open("input.txt", std::ifstream::in);
	if (inputFile.is_open()) {
		while (std::getline(inputFile, inputLine)) {
			std::cout << inputLine << '\n';
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

	// Looping through the array while 
	int* currentPtr = &inputArray[0];
	int* nextPtr = &inputArray[0];

	int answerSum = 0;

	while (answerSum != 2020) {
		answerSum = *currentPtr + *nextPtr;

		if (answerSum == 2020)
		{
			std::cout << '\n';
			std::cout << *currentPtr << " + " << *nextPtr << std::endl;
			std::cout << '\n';
			std::cout << "Answer found!*NOMS * Calendar chocolate!" << std::endl;
			break;
		}

		if (currentPtr == endPtr)
		{
			nextPtr++;
			currentPtr = startPtr;

			if (nextPtr == endPtr)
			{
				std::cout << "nextPtr reached the nullptr." << std::endl;
			}
		}
		currentPtr++;
	}

	std::cout << "Day 1 - Challenge 1 / 2 - Completed!" << std::endl;

	int calendarKey = (*currentPtr) * (*nextPtr);

	std::cout << '\n';
	std::cout << "The answer ultimately is: " << calendarKey << std::endl;

	return 0;
}