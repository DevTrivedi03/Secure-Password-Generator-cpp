#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function to shuffle the elements of a character array
void shuffleArray(vector<char> &arr)
{
    int n = arr.size();
    srand(time(0)); // Seed the random number generator with the current time

    // Fisher-Yates shuffle algorithm
    for (int i = n - 1; i > 0; --i)
    {
        int j = rand() % (i + 1); // Generate a random index between 0 and i (inclusive)
        swap(arr[i], arr[j]);     // Swap the elements at indices i and j
    }
}

// Overloaded function to shuffle the elements of an integer array
void shuffleArray(vector<int> &arr)
{
    int n = arr.size();
    srand(time(0)); // Seed the random number generator with the current time

    // Fisher-Yates shuffle algorithm
    for (int i = n - 1; i > 0; --i)
    {
        int j = rand() % (i + 1); // Generate a random index between 0 and i (inclusive)
        swap(arr[i], arr[j]);     // Swap the elements at indices i and j
    }
}

// Function to generate a random password based on specified criteria
vector<char> generatePass(int length, bool includeUppercase, bool includeLowercase, bool includeNumbers, bool includeSymbols)
{
    // Arrays to store characters of different types
    vector<char> uppercaseChars; 
    vector<char> lowercaseChars; 
    vector<char> numberChars;
    vector<char> symbolChars;

    // Populate arrays with respective characters
    for (int i = 0; i < 26; ++i)
    {
        uppercaseChars.push_back('A' + i); // Uppercase letters (ASCII range: 65-90)
    }

    for (int i = 0; i < 26; ++i)
    {
        lowercaseChars.push_back('a' + i); // Lowercase letters (ASCII range: 97-122)
    }

    for (int i = 0; i < 10; ++i)
    {
        numberChars.push_back('0' + i); // Numbers (ASCII range: 48-57)
    }

    // Populate array with symbols excluding whitespace characters
    for (int i = 0; i < 128; ++i)
    {
        if (isprint(i) and !(i >= 'A' and i <= 'Z') and !(i >= 'a' and i <= 'z') and !(i >= '0' and i <= '9') and !isspace(i))
        {
            symbolChars.push_back(i);
        }
    }

    // Vector to store characters to be picked from
    vector<char> pickFrom;

    // Add characters based on specified criteria
    if (includeUppercase)
    {
        for (int i = 0; i < uppercaseChars.size(); ++i)
        {
            pickFrom.push_back(uppercaseChars[i]);
        }
    }

    if (includeLowercase)
    {
        for (int i = 0; i < lowercaseChars.size(); ++i)
        {
            pickFrom.push_back(lowercaseChars[i]);
        }
    }

    if (includeNumbers)
    {
        for (int i = 0; i < numberChars.size(); ++i)
        {
            pickFrom.push_back(numberChars[i]);
        }
    }

    if (includeSymbols)
    {
        for (int i = 0; i < symbolChars.size(); ++i)
        {
            pickFrom.push_back(symbolChars[i]);
        }
    }

    // Vector to store indices representing the length of the password
    vector<int> lengthIndices;
    for (int i = 0; i < length; ++i)
    {
        lengthIndices.push_back(i);
    }

    // Vector to store the generated password
    vector<char> password;

    // Generate password by randomly picking characters from pickFrom
    while (length--)
    {
        shuffleArray(lengthIndices); // Shuffle the indices
        shuffleArray(pickFrom);      // Shuffle the characters to pick from

        password.push_back(pickFrom[lengthIndices[0]]); // Add a randomly picked character to the password
    }

    return password; // Return the generated password
}

int main()
{
    cout << setw(72) << "FORGE CUSTOMIZED STRONG PASSWORDS FOR MAXIMUM SECURITY" << endl
         << endl;

    int length;
    cout << "Enter the length of the password you want: ";
    cin >> length;

    bool includeUppercase, includeLowercase, includeNumbers, includeSymbols;

    cout << "Include uppercase characters (e.g., ABC...)? [1/0]: ";
    cin >> includeUppercase;

    cout << "Include lowercase characters (e.g., abc...)? [1/0]: ";
    cin >> includeLowercase;

    cout << "Include numbers (e.g., 123...)? [1/0]: ";
    cin >> includeNumbers;

    cout << "Include symbols (e.g., !$%...)? [1/0]: ";
    cin >> includeSymbols;

    // Check if at least one character type is selected
    if (!includeLowercase && !includeUppercase && !includeNumbers && !includeSymbols)
    {
        cout << "No character type is selected. Unable to generate the password." << endl;
        exit(1);
    }

    // Generate password based on user input
    vector<char> password = generatePass(length, includeUppercase, includeLowercase, includeNumbers, includeSymbols);

    cout << "\n\nThe random password generated is: ";
    for (int i = 0; i < length; ++i)
    {
        cout << password[i]; // Output the generated password
    }

    int count = 0;
    if (includeUppercase)
        count += 26;

    if (includeLowercase)
        count += 26;

    if (includeNumbers)
        count += 10;

    if (includeSymbols)
        count += 32;

    // Output the total number of possible passwords
    cout << "\n\nMake sure to save the password securely because it is 1 out of " << pow(count, length) << endl
         << endl;
    cout << setw(60) << "Thank you for using the Password Generator" << endl
         << endl;

    return 0;
}
