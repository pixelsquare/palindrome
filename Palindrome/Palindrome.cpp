#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

string wordInput;

int main() {

	cout << "Enter a word: ";
	cin >> wordInput;

	if(wordInput == string(wordInput.rbegin(), wordInput.rend()))
		cout << "PALINDROME!";

	getch();
	return 0;
}