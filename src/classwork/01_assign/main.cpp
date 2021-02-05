//Write the include statement for types.h here
#include "types.h"
#include <iostream>
//Write include for capturing input from keyboard and displaying output to screen
using std:: cout; using std:: cin;

int main() 
{
	int num;

	cout << "Enter a number.";

	cin >> num;

	int result;

	result = multiply_numbers(num);

	cout << "The result is: " << result << "\n";

	int num1 = 4;

	result = multiply_numbers(num1);

	cout << "The result is: " << result << "\n";

	return 0;
}

