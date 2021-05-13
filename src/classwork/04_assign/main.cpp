//write includes statements
#include <iostream>
#include "loops.h"

//write using statements for cin and cout
using std::cout; using std::cin;
/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	int number;
	char again;

	do
	{
		cout << "Enter a number between 1 and 10: ";
		cin >> number;

		if (number >= 1 && number <= 10)
		{
			cout << "The factorial of " << number << " is: " << 
			factorial(number) << ".\n";
		}

		else

			cout << "The number must be between 1 and 10.\n";

		cout << "Would you like to enter another number? If yes, type Y. ";
		cin >> again;

	} while (again == 'Y' || again == 'y');
	
	return 0;
}