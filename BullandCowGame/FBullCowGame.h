#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,Not_Isogram,Wrong_length,Not_Lowercase,Invalid
};

class FBullCowGame
{
	using FString = std::string;
public:
	FBullCowGame();
	int32 GetMaxTries()const;             //getter
	int32 GetCurrentTry()const;		      //getter
	bool IsGameWon()const;			      //getter
	int32 GetHiddenWordLength()const;     //getter
	void Reset();
	EGuessStatus CheckGuessValidity(FString)const;
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTries=1;
	int32 MyMaxTries=5;
	FString MyHiddenWord;
	bool IsIsogram(FString);
};

