/*
    WEEK 03 - PROGRAM 04: ARITMETIC OF POINTERS
    Write a function that determines whether a word is a palindrome. 
    A word palindrome is defined as a word that reads the same when read 
    from left to right or from right to left. 
    Use pointers and a vector of characters (char). 
    The word must have no more than 100 letters.

    Definition of variables:
        - word: vector of characters which represent the complete word
        - begin: char pointer to 1st position of vector word
        - end: char pointer to last position of vector word
*/

#include <iostream>
using namespace std;

const int n=100;

int main(){
    char word[n], *begin, *end;

    // make input
    cout<<"\nInput the word: ";
    cin>> word;

    // pointers to initial adress
    begin = word;
    end = word;

    // define adress for end position of the word
    while(*end){
        end++;
    }

    end--;

    // loop to compare the letters
    while(begin < end){
        if(*begin != *end){
            cout<< "\n This word is not palindrome"<<endl;
            return 0;
        }

        begin++;    // initial pointer move to right
        end--;      // end pointer move to left
    }

    cout<<"This word is palindrome"<<endl;

    return 0;

}