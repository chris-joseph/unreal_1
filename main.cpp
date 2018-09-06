#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
void PrintGuess(std::string &Guess);
string getGuess();
bool AskTOPlayAgain();
int main()
{
	PrintIntro();		
	PlayGame();
	bool Reply=AskTOPlayAgain();
	cout << Reply;
	getchar();
	return 0;
}
void PlayGame()
{
	//loop
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		string Guess = getGuess();									//get Guess
		PrintGuess(Guess);//repeat the guess back to user
	}
}

//repeat the guess back to user

void PrintGuess(std::string &Guess)
{
	cout << endl << "Your guess was : " << Guess;
	cout << endl;
}

//this was done by quick actions and refactoring opt in click drop menu

//print introduction

void PrintIntro()
{
	constexpr int WORLD_LENGHT = 5;
	cout << "Welcome to Bulls and Cows Game";
	cout << endl;
	cout << "Guess the hidden " << WORLD_LENGHT << " letter isogram\n";
	return;
}

//get guess from player

string getGuess()
{
	cout << endl;
	cout << "Enter a guess : ";
	string Guess;
	getline(cin, Guess);
	return Guess;
}

bool AskTOPlayAgain()
{
	cout << "Do you want to play again ?";
	string Response = "";
	getline(cin,Response);
	return (Response[0]=='y')||(Response[0] == 'Y');
}
