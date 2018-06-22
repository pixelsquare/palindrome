#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

#if _WIN32
#include <conio.h>
#endif;

bool isPalindrome(std::string input);

int main(int argc, char *argv[])
{
    char wordInput[500];

    std::cout << "###############################" << std::endl;
    std::cout << "Welcome to Palindrome Verifier!" << std::endl;
    std::cout << "###############################" << std::endl;
    std::cout << std::endl;

    std::cout << "Please enter a word or a phrase: ";
    std::cin.getline(wordInput, sizeof(wordInput));
    std::cout << std::endl;

    std::cout << "Result:" << std::endl;

    bool isWordPalindrome = isPalindrome(wordInput);
    std::cout << wordInput << (isWordPalindrome ? " is a PALINDROME!" : " is NOT a PALINDROME!") << std::endl;

    std::cout << std::endl;

    std::cout << "Thank you!";

#if _WIN32
    _getch();
#endif;

    return 0;
}

bool isNotAlnum(char c)
{
    return std::isalnum(c) == 0;
}

bool isPalindrome(std::string input)
{
    input.erase(std::remove_if(input.begin(), input.end(), isNotAlnum), input.end());
    input.erase(std::remove_if(input.begin(), input.end(), std::isspace), input.end());

    std::transform(input.begin(), input.end(), input.begin(), std::tolower);

    int counter = 0;
    size_t size = input.size();     

    for(int i = 0; i < size / 2; i++)
    {
        size_t x = size - i - 1;

        if(input[i] == input[x])
        {
            counter++;
        }
    }

    return counter > 0 && counter == size / 2;
}