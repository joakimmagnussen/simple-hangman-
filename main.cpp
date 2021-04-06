#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>

const int MAX_TRIES = 5;
int letterFill(char, std::string, std::string&);


int main()
{
    std::string name;
    char letter;
    int count_of_fail_gues = 0;
    std::string word;
    std::string words[] =
            {
            "apple",
            "mango",
            "banan",
            "kiwi"

            };
    srand(time(NULL));
    int n = rand()% 10;
    word = words[n];

    std::string unknown(word.length(),'*');

    std::cout << "\n\n Welcome to hangman! Guess a fruit";
    std::cout << "\n\nEach letter is represented by a star.";
    std::cout << "\n\nYou have to type only one letter in one try";
    std::cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    // Loop until the guesses are used up
    while (count_of_fail_gues < MAX_TRIES)
    {
        std::cout << "\n\n" << unknown;
        std::cout << "\n\nGuess a letter: ";
        std::cin >> letter;
        // Fill secret word with letter if the guess is correct,
        // otherwise increment the number of wrong guesses.
        if (letterFill(letter, word, unknown)==0)
        {
            std::cout << std::endl << "Whoops! That letter isn't in there!" << std::endl;
            count_of_fail_gues++;
        }
        else
        {
            std::cout << std::endl << "You found a letter! Isn't that exciting!" << std::endl;
        }
        // Tell user how many guesses has left.
        std::cout << "You have " << MAX_TRIES - count_of_fail_gues;
        std::cout << " guesses left." << std::endl;
        // Check if user guessed the word.
        if (word==unknown)
        {
            std::cout << word << std::endl;
            std::cout << "Yeah! You got it!";
            break;
        }
    }
    if(count_of_fail_gues == MAX_TRIES)
    {
        std::cout << "\nSorry, you lose...you've been hanged." << std::endl;
        std::cout << "The word was : " << word << std::endl;
    }
    std::cin.ignore();
    std::cin.get();
    return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill (char guess, std::string secretword, std::string &guessword)
{
    int i;
    int matches=0;
    int len=secretword.length();
    for (i = 0; i< len; i++)
    {
        // Did we already match this letter in a previous guess?
        if (guess == guessword[i])
            return 0;
        // Is the guess in the secret word?
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}
