#include <iostream>
#include <string>
using namespace std;

int main()
{
    string dna, rev_complement;

    cin >> dna;

    for (int i = dna.length() - 1; i >= 0; i--)
    {
        char nucleotide = dna[i];
        if (nucleotide == 'A')
        {
            rev_complement += 'T';
        }
        else if (nucleotide == 'T')
        {
            rev_complement += 'A';
        }
        else if (nucleotide == 'C')
        {
            rev_complement += 'G';
        }
        else if (nucleotide == 'G')
        {
            rev_complement += 'C';
        }
    }

    cout << rev_complement << endl;

    return 0;
}
