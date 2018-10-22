/*contains game logic for better abstraction and no direct user interaction*/

#pragma once
#include <string>
//making code unreal friendly
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
	int32 MyCurrentTries;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString)const;
	bool IsLowercase(FString)const;
};

