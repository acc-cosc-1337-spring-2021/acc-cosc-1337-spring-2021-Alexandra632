#include "dna.h"
using std::string;
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string& dna)
{
    double dna_length = dna.length();
    int gc_total = 0;
    
    for (int i = 0; i < dna_length; i++)
    {
        if (dna[i] == 'G' || dna[i] == 'C')
        { 
            gc_total += 1;
        }
    }
    return ((gc_total / dna_length) * 100);
    
}


/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string reverse_string(string dna)
{
    std::string reversed_dna;

    int dna_length = dna.length();

    for (int i = 0; i < dna_length; i++)
    {
        reversed_dna[i] = dna[(dna_length - 1) - i];   
    }
    
    return reversed_dna;
}


/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string
*/
std::string get_dna_complement(std::string dna)
{
    std::string reversed_dna = reverse_string(dna);

    int reversed_dna_length = reversed_dna.length();
    
    for (int i = 0; i < reversed_dna_length; i++)
    {
        if(reversed_dna[i] == 'A')
            reversed_dna[i] = 'T';

        else if(reversed_dna[i] == 'T')
            reversed_dna[i] = 'A';
        
        else if(reversed_dna[i] == 'C')
            reversed_dna[i] = 'G';

        else 
            reversed_dna[i] = 'C';
    }

    return reversed_dna;

}
