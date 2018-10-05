#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount
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
	int32 GetHiddenWordLength()const;
	void Reset();
	bool CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTries=1;
	int32 MyMaxTries=5;
	FString MyHiddenWord;
	bool IsIsogram(FString);
};

