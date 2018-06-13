#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

bool isPalindrome(std::string input);
std::string removeNonAlphaString(std::string const& input);
std::string trimWhitespaces(std::string const& str);

int main(int argc, char *argv[])
{
    char wordInput[500];

    std::cout << "###############################" << std::endl;
    std::cout << "Welcome to Palindrome Verifier!" << std::endl;
    std::cout << "###############################" << std::endl;
    std::cout << std::endl;

    std::cout << "Please enter a word or a phrase: ";
    std::cin.getline(wordInput, sizeof(wordInput));

    std::cout << "###############################" << std::endl;
    std::cout << "Result:" << std::endl;
    std::cout << "###############################" << std::endl;

    bool isWordPalindrome = isPalindrome(wordInput);
    std::cout << wordInput << (isWordPalindrome ? " is a PALINDROME!" : " is NOT a PALINDROME!") << std::endl;

    std::cout << "###############################" << std::endl;
    std::cout << std::endl;

    std::cout << "Thank you!";

    return 0;
}

bool isPalindrome(std::string input)
{
    input = trimWhitespaces(input);
    input = removeNonAlphaString(input);

    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    int size = input.size();
    size = (size % 2 == 0) ? size : size - 1;
        
    int counter = 0;

    for(int i = 0; i < size / 2; i++)
    {
        int x = size - i;

        if(input[i] == input[x])
        {
            counter++;
        }
    }

    return counter > 0 && counter == size / 2;
}

std::string removeNonAlphaString(std::string const& input)
{
    std::string returnValue = input;

    for(std::string::iterator i = returnValue.begin(); i != returnValue.end(); i++)
    {
        if(!isalpha(returnValue.at(i - returnValue.begin())) || isspace(returnValue.at(i - returnValue.begin())))
        {
            returnValue.erase(i);
            i--;
        }
    }

    return returnValue;
}

std::string trimWhitespaces(std::string const& str)
{
    std::string returnValue;

    if(str.size() > 0)
    {
        size_t startPos = str.find_first_not_of(" ");
        size_t endPos = str.find_last_not_of(" ");

        returnValue = returnValue.substr(startPos, endPos - startPos + 1);
    }

    return returnValue;
}