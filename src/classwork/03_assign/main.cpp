//Write the include statement for decisions.h here
#include "decision.h"

//Write namespace using statements for cout and cin
using std::string; using std::cout; using std::cin;

int main() 
{
	int grade;
	string letter_grade_if;
	string letter_grade_switch;
	
	cout << "Enter a number grade: ";
	cin >> grade;

	if (grade >= 0 && grade <= 100) {

		letter_grade_if = get_letter_grade_using_if(grade);

		letter_grade_switch = get_letter_grade_using_switch(grade);
		
		cout << "The letter grade using if/else if is: " <<
		letter_grade_if << ".\n";

		cout << "The letter grade using switch is: " <<
		letter_grade_switch << ".\n";
	}
	else

		cout << "The number you entered in out of range.";

	return 0;
}

