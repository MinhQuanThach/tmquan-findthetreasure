#ifndef OPEN_THE_TREASURE_H_INCLUDED
#define OPEN_THE_TREASURE_H_INCLUDED

#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <random>
#include <sstream>
#include <chrono>
#include <Windows.h>
#define int32 int
#define FString std::string
#define FText std::string

class Utils
{
public:
	int32 static CaptureIntFromUser(FText message);
private:
};

// capture input from user and checks if is a valid number
int32 Utils::CaptureIntFromUser(FText message)
{
	int32 Response = 0;
	FString Input = "";

	do
	{
		std::cout << message;
		std::getline(std::cin, Input);

		// This code converts from string to number safely.
		std::stringstream MyStream(Input);
		if (MyStream >> Response) return Response;
		std::cout << std::endl << "That's not a number :(" << std::endl << std::endl; //FIXME im not happy with this, change it
	} while (true);
	return Response;
}

class openTheTreasure
{
public:
	openTheTreasure(); // constructor

	void Reset();
	void Menu(int32);
	int32 TryToOpenChest();
	void AskForClue();
	void LeaveTheChest();
	void ExitGame();

	int32 GetRandomKey() const;
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool IsChestLeaved() const;

private:
	// Minimum number
	int32 MinNumber;
	// Maximum number
	int32 MaxNumber;
	// The number key to open the chest, generated randomly
	int32 RandomKey;
	// Max tries in the current game
	int32 MaxTries; // TODO think why increase or decrease this number, maybe a fix value?
	// Current try of the game
	int32 CurrentTry;
	bool bIsGameWon;
	// clues for the user when decide spend a try
	std::list<FString> ListOfCalculatedClues;

	// Generates a random number key from MIN_NUMBER to MAX_NUMBER both included
	int32 GenerateRandomKey(int32 MIN_NUMBER, int32 MAX_NUMBER);
	// Check if the given number is pair or odd
	int32 IsNumberOdd(int32);
	// Sum both digits of the given number
	int32 SumDigitsKey(int32);
	// create the clues and calculate their values
	void CreateClues();
};

openTheTreasure::openTheTreasure() { Reset(); }
int32 openTheTreasure::GetRandomKey() const { return RandomKey; }
int32 openTheTreasure::GetMaxTries() const { return MaxTries; }
int32 openTheTreasure::GetCurrentTry() const { return CurrentTry; }
bool openTheTreasure::IsGameWon() const { return bIsGameWon; }

void openTheTreasure::Reset()
{
	MinNumber = 1;
	MaxNumber = 99;
	CurrentTry = 1;
	MaxTries = 8; //FIXME change this value
	bIsGameWon = false;
	ListOfCalculatedClues.clear();
	RandomKey = GenerateRandomKey(MinNumber, MaxNumber);
	CreateClues(); // calculate the clues in initialization time
}

void openTheTreasure::Menu(int32 Option)
{
	int32 KeyFromUser = 0;
	switch (Option)
	{
	case 1: // Try to open the chest!
		KeyFromUser = TryToOpenChest();
		if (!bIsGameWon)
		{
			// display a clue greater/lower than, but not in the final turn
			if (CurrentTry < MaxTries)
			{
				if (RandomKey > KeyFromUser) std::cout << "The key is greater than " << KeyFromUser;
				else std::cout << "The key is lower than " << KeyFromUser;
			}

			std::cout << std::endl << std::endl;
			// increase try number
			CurrentTry++;
		}
		break;
	case 2: // Ask for a clue
		AskForClue();
		break;
	case 3: // Exit game
		ExitGame();
		break;
	default: // Non valid option
		std::cout << "You must select a valid option between 1-3" << std::endl;
		break;
	}
}

int32 openTheTreasure::TryToOpenChest()
{
	FText message = "> Enter a number from " + std::to_string(MinNumber) + " to " + std::to_string(MaxNumber) + ": ";
	int32 KeyFromUser = Utils::CaptureIntFromUser(message);
	bIsGameWon = (KeyFromUser == RandomKey) ? true : false;
	return KeyFromUser;
}

void openTheTreasure::AskForClue()
{
	// if the list if empty, display a warning without spend a try
	if (ListOfCalculatedClues.empty())
	{
		std::cout << "No more clues are available :(" << std::endl;
	}
	else
	{
		int32 RandomClue = GenerateRandomKey(0, ListOfCalculatedClues.size());
		auto iterator = std::next(ListOfCalculatedClues.begin(), RandomClue);
		std::cout << *iterator << std::endl << std::endl;

		// remove the clue already presented
		ListOfCalculatedClues.remove(*iterator);

		// spend a try
		CurrentTry++;
	}

	//std::cout << "DEBUG - The first digit is: " + std::to_string(RandomKey / 10) << std::endl;
	//std::cout << "DEBUG - The second digit is: " + std::to_string(RandomKey % 10) << std::endl;
	return;
}

void openTheTreasure::ExitGame()
{
	std::cout << std::endl << "See you soon!" << std::endl;
	std::exit(EXIT_SUCCESS);
	return;
}

// Generates a random number key from MIN_NUMBER to MAX_NUMBER both included
int32 openTheTreasure::GenerateRandomKey(int32 MinNumber, int32 MaxNumber)
{
	// TODO display an error if min number is greather than max number
	if (MinNumber > MaxNumber) return -1;

	// Provided by C++11
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 mt(seed);
	std::uniform_int_distribution<int> dist(MinNumber, MaxNumber);

	return dist(mt);
}


// Check if the given number is even or odd
int32 openTheTreasure::IsNumberOdd(int32 Number) { return Number % 2; }

// Sum both digits of the given number
int32 openTheTreasure::SumDigitsKey(int32 Number)
{
	int32 firstDigit = Number / 10;
	int32 secondDigit = Number % 10;
	return firstDigit + secondDigit;
}

void openTheTreasure::CreateClues()
{
	int32 numberBelow = GenerateRandomKey(MinNumber, RandomKey);
	int32 numberAbove = GenerateRandomKey(RandomKey, MaxNumber);
	FString firstDigitValue = IsNumberOdd(RandomKey / 10) ? "odd" : "even";
	FString secondDigitValue = IsNumberOdd(RandomKey % 10) ? "odd" : "even";

	ListOfCalculatedClues.push_back("The first digit is " + firstDigitValue);
	ListOfCalculatedClues.push_back("The second digit is " + secondDigitValue);
	ListOfCalculatedClues.push_back("The sum of the digits is " + std::to_string(SumDigitsKey(RandomKey)));
	ListOfCalculatedClues.push_back("The number is between " + std::to_string(numberBelow) + " and " + std::to_string(numberAbove));
	return;
}

void PrintIntro();
void PlayGame();
FText PrintMenu();
void PrintGameSummary();

openTheTreasure THGame; // Game initialization

const FText WIN_MESSAGE = "";
const FText LOOSE_MESSAGE = "";

// Introduction of the game, add here rules or anything you think is nice to explain to the user
void PrintIntro()
{
	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//                                        Open the Treasure                                               //" << std::endl;
	std::cout << "//--------------------------------------------------------------------------------------------------------//" << std::endl;
	std::cout << "// - You will have a number of attempts to guess the random generated key (0-99) of the treasure chest... //" << std::endl;
	std::cout << "// - If you wish you can spend tries in order to get clues from the system                                //" << std::endl;
	std::cout << "//--------------------------------------------------------------------------------------------------------//" << std::endl;
	std::cout << "//                                      Good Luck and Have Fun!                                           //" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	//std::cout << "DEBUG - Random number generated: " << THGame.GetRandomKey() << std::endl;
	int32 UserOption = 0;
	std::cout << std::endl << std::endl;

	while (!THGame.IsGameWon() && THGame.GetCurrentTry() <= THGame.GetMaxTries())
	{
		UserOption = Utils::CaptureIntFromUser(PrintMenu()); // prints the menu and retrieves the user option
		//std::cout << "DEBUG - Option " << UserOption << " entered" << std::endl;
		THGame.Menu(UserOption); // performs the action selected by the user
	}
    PrintGameSummary();
	THGame.Reset();
	return;
}

FText PrintMenu()
{
	FText menu = "";
	menu = "==============================\n";
	menu += "|          Try: " + std::to_string(THGame.GetCurrentTry()) + "/" + std::to_string(THGame.GetMaxTries()) + "          |\n";
	menu += "==============================\n";
	menu += "| 1.- Try to open the chest! |\n";
	menu += "| 2.- Ask for a clue         |\n";
	menu += "| 3.- Exit game              |\n";
	menu += "==============================\n";
	menu += "> What do you want to do?  ";
	return menu;
}

void PrintGameSummary()
{
	if (THGame.IsGameWon()) std::cout << "CONGRATULATIONS! - You open the chest!" << std::endl;
	else std::cout << "Sorry :( - You do not open the chest. The number was: " << THGame.GetRandomKey() << std::endl;
	return;
}

#endif // OPEN_THE_TREASURE_H_INCLUDED
