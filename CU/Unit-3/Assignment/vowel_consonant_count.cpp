#include <iostream>
using namespace std;

bool isVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int vowels = 0;
    int consonants = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            if (isVowel(str[i]))
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    cout << "Number of vowels: " << vowels << endl;
    cout << "Number of consonants: " << consonants << endl;

    return 0;
}
