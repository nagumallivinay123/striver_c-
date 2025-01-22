#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to create the bad character heuristic table
void badCharacterTable(const string &pattern, vector<int> &badCharTable)
{
    int m = pattern.size();

    // Initialize all occurrences as -1
    badCharTable = vector<int>(256, -1);

    // Fill the actual value of the last occurrence of a character in the pattern
    for (int i = 0; i < m; i++)
    {
        badCharTable[pattern[i]] = i;
    }
}

// Function to create the good suffix heuristic table
void goodSuffixTable(const string &pattern, vector<int> &goodSuffix, vector<int> &borderPos)
{
    int m = pattern.size();
    goodSuffix = vector<int>(m + 1, 0);
    borderPos = vector<int>(m + 1, 0);

    int i = m, j = m + 1;
    borderPos[i] = j;

    // Preprocess the pattern to fill borderPos[]
    while (i > 0)
    {
        while (j <= m && pattern[i - 1] != pattern[j - 1])
        {
            if (goodSuffix[j] == 0)
            {
                goodSuffix[j] = j - i;
            }
            j = borderPos[j];
        }
        i--;
        j--;
        borderPos[i] = j;
    }

    j = borderPos[0];

    // Preprocess the good suffix array
    for (i = 0; i <= m; i++)
    {
        if (goodSuffix[i] == 0)
        {
            goodSuffix[i] = j;
        }
        if (i == j)
        {
            j = borderPos[j];
        }
    }
}

// Boyer-Moore search algorithm
void boyerMoore(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();

    vector<int> badCharTable;
    vector<int> goodSuffix;
    vector<int> borderPos;

    // Step 1: Preprocess the pattern
    badCharacterTable(pattern, badCharTable);
    goodSuffixTable(pattern, goodSuffix, borderPos);

    // Step 2: Search the pattern in the text
    int s = 0; // s is the shift of the pattern with respect to the text

    while (s <= (n - m))
    {
        int j = m - 1;

        // Decrease index j of the pattern while characters of pattern and text match
        while (j >= 0 && pattern[j] == text[s + j])
        {
            j--;
        }

        // If the pattern is found
        if (j < 0)
        {
            cout << "Pattern found at index " << s << endl;
            s += goodSuffix[0]; // Shift according to good suffix rule
        }
        else
        {
            // Shift the pattern so that the bad character in text aligns with the last occurrence in pattern
            s += max(1, max(j - badCharTable[text[s + j]], goodSuffix[j + 1]));
        }
    }
}

// Driver code
int main()
{
    string text = "HERE IS A SIMPLE EXAMPLE";
    string pattern = "EXAMPLE";

    boyerMoore(text, pattern);

    return 0;
}
