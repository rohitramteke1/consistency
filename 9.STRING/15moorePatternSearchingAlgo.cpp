#include <iostream>
#include <string>

using namespace std;

// Function to create a table that maps each character in the alphabet to the maximum number of positions that the character can be shifted to the right in the pattern string without causing a mismatch.
int *create_table(string pattern)
{
    int *table = new int[256];
    for (int i = 0; i < 256; i++)
    {
        table[i] = pattern.size();
    }
    for (int i = 0; i < pattern.size() - 1; i++)
    {
        table[pattern[i]] = pattern.size() - 1 - i;
    }
    return table;
}

// Function to search for the pattern string in the text string.
bool boyer_moore(string text, string pattern)
{
    int *table = create_table(pattern);
    int i = text.size() - 1;
    int j = pattern.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (text[i] == pattern[j])
        {
            i--;
            j--;
        }
        else
        {
            i -= table[text[i]];
        }
    }
    if (j == -1)
    {
        cout << i << endl;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string text = "This is a test string.";
    string pattern = "test";
    if (boyer_moore(text, pattern))
    {
        cout << "The pattern was found!" << endl;
    }
    else
    {
        cout << "The pattern was not found!" << endl;
    }
    return 0;
}
