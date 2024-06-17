# C++ Password Generator: Unveiling the Mechanics

## Overview
This document delves into the intricacies of the C++ code driving a robust password generation application. This software empowers users to create tailored, secure passwords, boasting adaptability in password length and character types, including uppercase and lowercase letters, numbers, and symbols.


For more details and to use the application, visit the project website: [Secure Password Generator C++](https://iamdevtrivedi.github.io/Secure-Password-Generator-cpp/).

## Features

### 1. Password Generation
At the core of the application lies the `generatePass` function, orchestrating password creation. It accepts five parameters:
- `length`: Desired password length.
- `includeUppercase`: Boolean indicating inclusion of uppercase letters (True for inclusion, False for exclusion).
- `includeLowercase`: Boolean indicating inclusion of lowercase letters.
- `includeNumbers`: Boolean indicating inclusion of numbers.
- `includeSymbols`: Boolean indicating inclusion of symbols.

The `generatePass` function constructs passwords through the following steps:
1. Initializing vectors for different character types (uppercase, lowercase, numbers, symbols).
2. Populating these vectors based on ASCII character ranges.
3. Creating a vector named `pickFrom` to hold eligible characters for password generation based on user preferences.
4. Employing the Fisher-Yates shuffle algorithm, implemented within the `shuffleArray` function, to shuffle `lengthIndices` and `pickFrom`.
5. Iterating `length` times to create the password:
   - Selecting a character from the shuffled `pickFrom` vector.
   - Appending the chosen character to the password vector.
6. Returning the generated password as a character vector.

### 2. User Interaction
The `main` function serves as the program's entry point, guiding user interactions:
- Welcoming the user with a centered title.
- Prompting for the desired password length.
- Inquiring about character type preferences.
- Validating user input to ensure at least one character type is selected.
- Calling the `generatePass` function with user input.
- Displaying the generated password.
- Calculating the total number of possible password combinations.
- Informing the user about the importance of securing the generated password.
- Bidding farewell to the user.

### 3. Shuffling Mechanism
The `shuffleArray` function implements the Fisher-Yates shuffle algorithm to shuffle elements within an array. It is overloaded to work with both character and integer vectors.

The `shuffleArray` function performs the following actions:
- Accepting a reference to the vector needing shuffling.
- Retrieving the vector's size.
- Seeding the random number generator with the current time.
- Iterating to shuffle the elements.

## Conclusion
This C++ password generator provides a valuable tool for creating secure and customizable passwords. Future enhancements could include strengthening input validation, measuring password strength, and integrating with password management tools to enhance security.


