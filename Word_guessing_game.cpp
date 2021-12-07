#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAX_TRIES=5;
int wordreplace_letter (char, string, string&);

int main ()
{
	string name;
	char letter;
	int wrong_guess=0;
	string word;
	string vegetables[] =
	{
		"carrot",
		"potato",
		"spinach",
		"cucumber",
		"mint",
		"capsicum",
		"cabbage",
		"chilli",
		"ginger",
		"garlic"
        "brocoli",
        "eggplant",
        "lemongrass",
        "cauiliflower",
        "lemon",

	};

	//choose and copy a word from array of words randomly
	srand(time(NULL));
	int n=rand()% 15;
	word=vegetables[n];
    
	// Initialize the secret word with the # character.
	string unknown(word.length(),'#');

	// welcome the user
	cout << "\n\nWelcome to Hangman - word guessing game...Guess a vegetable Name";
	cout << "\n\nEach letter is represented by a #.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
	// Loop until the guesses are used up
	while (wrong_guess < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (wordreplace_letter(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			wrong_guess++;
		}
		else
		{
			cout << endl << "You found a letter! That's amazing!" << endl;
		}
		// Tell user how many guesses has left.
		cout << "You have " << MAX_TRIES - wrong_guess;
		cout << " guesses left." << endl;
		// Check if user guessed the word.
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if(wrong_guess == MAX_TRIES)
	{
		cout << "\nSorry, you lose..." << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int wordreplace_letter (char guess, string word1, string &guessword)
{
	int i;
	int target=0;
	int len=word1.length();
	for (i = 0; i< len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == word1[i])
		{
			guessword[i] = guess;
			target++;
		}
	}
	return target;
}