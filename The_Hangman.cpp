#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MAX_TRIES = 5;

int letterfill(char guess, string secretword, string &guessword){
    int i;
    int matches = 0;
    int len = secretword.length();
    for(i = 0; i < len; i++){
        if(guess == guessword[i]){
            return 0;
        }
        if(guess == secretword[i]){
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

int main() {
    
    string name;
    char letter;
    int wrong_guess = 0;
    string word;
    string words[] = {
        "Tiger",
        "Lion",
        "Giraffe",
        "Zebra",
        "Rinoceros",
        "Elephant"
    };
    
    srand(time(nullptr));
    int n = rand() % 6;
    word = words[n];
    
    string unknown(word.length(),'*');
    
    cout << endl;
    cout << "Let's play hangman, you have to guess an animal name";
	cout << endl;
    cout << "Each letter is represented by a star.";
	cout << endl;
    cout << "You have to type only one letter in one try";
	cout << endl;
    cout << "You have " << MAX_TRIES << " tries to try and guess the word.";
    cout << endl;
    
    while(wrong_guess < MAX_TRIES){
        cout << endl << unknown;
        cout << "Guess a letter: ";
        cin >> letter;
        
        if(letterfill(letter, word, unknown) == 0){
            cout << "NOT THERE.";
            wrong_guess++;
        }
        else{
            cout << endl << "YOU FOUND A LETTER!!" << endl;
        }
        
        if(word == unknown){
            cout << "You got it";
            break;
        }
    }
    
    
    return 0;
}