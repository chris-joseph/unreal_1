#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame()
{
		Reset();
}

int32 FBullCowGame::GetMaxTries()const   {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry()const {return MyCurrentTries; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	 constexpr int32 MAX_TRIES = 8;
	 const FString HIDDEN_WORD= "planet";
	 MyHiddenWord = HIDDEN_WORD;
	 MyCurrentTries = 1;
	 MyMaxTries = MAX_TRIES;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

BullCowCount FBullCowGame::SubmitGuess(FString)
{
	MyCurrentTries++;
	BullCowCount BullCowCount;

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString)
{
	return false;
}
