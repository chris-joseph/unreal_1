
#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map
using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame()
{
		Reset();
}


int32 FBullCowGame::GetCurrentTry()const { return MyCurrentTries; }
int32 FBullCowGame::GetHiddenWordLength()const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

int32 FBullCowGame::GetMaxTries()const 
{ 
	TMap<int32, int32> WordLengthtoMaxTries{ {3,5},{4,7},{5,9},{6,15} };
	return WordLengthtoMaxTries[MyHiddenWord.length()]; 
}

void FBullCowGame::Reset()
{
	 const FString HIDDEN_WORD= "plant";
	 MyHiddenWord = HIDDEN_WORD;
	 MyCurrentTries = 1;
	 bGameIsWon = false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length()!=GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_length;
	}
	else
	{
		return EGuessStatus::OK;

	}
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTries++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 GIterator=0;GIterator<HiddenWordLength;GIterator++) 
	{
		for (int32 MHWIterator=0;MHWIterator<HiddenWordLength;MHWIterator++) 
		{
			if (Guess[GIterator]==MyHiddenWord[MHWIterator])
			{
				if (GIterator==MHWIterator) 
				{
					BullCowCount.Bulls++;
				}
				else if (GIterator!=MHWIterator)
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == GetHiddenWordLength())
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess)const
{
	if (Guess.length() <=1) { return true; }//accept 0 or 1 terrer words
	TMap<char, bool>LetterSeen;
	for (auto Letter : Guess)
	{
		Letter =tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	for (auto letter : Guess)
	{
		
		if(!islower(letter))
		{
			return false;
		}
	}
	return true;
}
