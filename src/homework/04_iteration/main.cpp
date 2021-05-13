//write include statements
#include "dna.h"


//write using statements
using std::cout; using std::cin; using std::string;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/

int main() 
{
	int entry;
	char again;
	string dna;

	do
	{
		cout << "Enter 1 to get the GC content or 2 to get the DNA complement: ";
		cin >> entry;

		if (entry == 1)
		{
			cout << "Please enter the DNA sequence: ";
			cin >> dna;
			cout << "The GC content is " << get_gc_content(dna) << "%.\n";
		}
		else
		{
			cout << "Please enter the DNA sequence: ";
			cin >> dna;
			cout << "The DNA complement is " << get_dna_complement(dna) << ".\n";
		}

		cout << "Would you like to run this program again? If yes, enter Y." ;
		cin >> again;

	} while (again == 'Y' || again == 'y');
	
	return 0;
}