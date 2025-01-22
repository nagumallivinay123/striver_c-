#include <iostream>
#include <string>
using namespace std;

int main()
{
    string dna;

    
    cin >> dna;

    int countA = 0, countC = 0, countG = 0, countT = 0;

   
    for (char nucleotide : dna)
    {
        if (nucleotide == 'A')
            countA++;
        else if (nucleotide == 'C')
            countC++;
        else if (nucleotide == 'G')
            countG++;
        else if (nucleotide == 'T')
            countT++;
    }

   
    cout << countA << " " << countC << " " << countG << " " << countT << std::endl;

    return 0;
}
