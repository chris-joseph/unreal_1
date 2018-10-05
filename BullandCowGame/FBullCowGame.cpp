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

int32 FBullCowGame::GetHiddenWordLength() const
{

	return MyHiddenWord.length();
}

void FBullCowGame::Reset()
{
	 constexpr int32 MAX_TRIES = 8;
	 const FString HIDDEN_WORD= "ant";
	 MyHiddenWord = HIDDEN_WORD;
	 MyCurrentTries = 1;
	 MyMaxTries = MAX_TRIES;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTries++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i=0;i<HiddenWordLength;i++) 
	{
		for (int32 j=0;j<HiddenWordLength;j++) 
		{
			if (Guess[i]==MyHiddenWord[j])
			{
				if (i==j) 
				{
					BullCowCount.Bulls++;
				}
				else if (i!=j)
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString)
{
	return false;
}
