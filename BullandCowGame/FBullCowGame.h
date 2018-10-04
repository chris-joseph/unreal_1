#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};
class FBullCowGame
{
	using FString = std::string;
public:
	FBullCowGame();
	int32 GetMaxTries()const;          //getter
	int32 GetCurrentTry()const;		 //getter
	bool IsGameWon()const;			 //getter

	void Reset();
	bool CheckGuessValidity(FString);
	BullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTries=1;
	int32 MyMaxTries=5;
	FString MyHiddenWord;
	bool IsIsogram(FString);
};

