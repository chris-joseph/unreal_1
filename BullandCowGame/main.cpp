#include <iostream>
#include <string>
#include"FBullCowGame.cpp"
//using namespace std; preferably not used as confutions may arise
using FText = std::string;
using int32 = int;

void Printintro();
void PlayGame();
void PrintGuess(FText &Guess);
FText getValidGuess();
bool AskTOPlayAgain();

FBullCowGame  BCGame;
int main()
{ 
	bool bWantsToPlay=false;
	do {
		Printintro();
		PlayGame();
	    bWantsToPlay = AskTOPlayAgain();
		std::cout << bWantsToPlay;
		getchar();
	} while (bWantsToPlay);
	return 0;
}
void PlayGame()
{
	//loop
	
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = getValidGuess();									//get Guess

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls ->" << BullCowCount.Bulls;
		std::cout << "Cows ->" << BullCowCount.Cows << std::endl;
		PrintGuess(Guess);//repeat the guess back to user
	}
}

//repeat the guess back to user

void PrintGuess(FText &Guess)
{
	std::cout << std::endl << "Your guess was : " << Guess;
	std::cout << std::endl;
}

//this was done by quick actions and refactoring opt in click drop menu

//print introduction

void Printintro()
{
	
	std::cout << "Welcome to Bulls and Cows Game";
	std::cout << std::endl;
	std::cout << "Guess the hidden " <<BCGame.GetHiddenWordLength()<< " letter isogram\n";
	return;
}

//get guess from player

FText getValidGuess()
{
	EGuessStatus Status= EGuessStatus::Invalid;
	do
	{
	int32 CurrentTry=BCGame.GetCurrentTry();
	std::cout << std::endl;
	std::cout <<"Try :"<<CurrentTry<< ". Enter a guess : ";
	FText Guess;
	std::getline(std::cin, Guess);
	Status = BCGame.CheckGuessValidity(Guess);
	switch (Status)
	{
		case EGuessStatus::Wrong_length :
		{
			std::cout << "Enter a "<< BCGame.GetHiddenWordLength()<<" letter word";
			break;
		}
		case EGuessStatus::Not_Isogram:
		{
			std::cout << "Enter an Isogram";
			break;
		}
		case EGuessStatus::Not_Lowercase:
		{
			std::cout << "Enter lowercase word ";
			break;
		}
		default:
		{	
			return Guess;
		}
	}
	std::cout << std::endl;
}while (Status!= EGuessStatus::OK);
}

bool AskTOPlayAgain()
{
	std::cout << "Do you want to play again (y/n) ?";
	FText Response = "";
	std::getline(std::cin,Response);
	return (Response[0]=='y')||(Response[0] == 'Y');
}
