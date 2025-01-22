#include <iostream>
#include <string>
using namespace std;

int main()
{
   string dna, rna;

   
    cin >> dna;

    // Transcribe DNA to RNA by replacing 'T' with 'U'
    for (char nucleotide : dna)
    {
        if (nucleotide == 'T')
        {
            rna += 'U';
        }
        else
        {
            rna += nucleotide;
        }
    }

 
 cout << rna << endl;

    return 0;
}
