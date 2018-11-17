#include "Mnemonic.h"

Mnemonic::Mnemonic()
{
    //ctor
}

/**List mnemonics function to get all combinations for every letter**/
void Mnemonic::ListMnemonics (int string[], int current_Index, char oppositeLetter[], int string_length)
{
    if (current_Index == string_length)
    {
        cout << oppositeLetter << ", "; /**Base case and gives that For print function**/
        return;
    }
    for (int i=0; i<strlen(KeypadLetters[string[current_Index]]); i++)
    {
        oppositeLetter[current_Index] = KeypadLetters[string[current_Index]][i]; // looping on the letters of the given number
        ListMnemonics(string, current_Index+1, oppositeLetter, string_length); // Recursive Case

        if (string[current_Index] == 0 || string[current_Index] == 1) // As 0 and 1 are NULL.
        {
            return;
        }
    }
};

/**A Print Fn for printing mnemonics and opposite letters for given number**/
void Mnemonic::PrintMnemonics (int string[], int string_length)
{
    char oppositeLetter[string_length+1];
    oppositeLetter[string_length] = '\0';
    ListMnemonics(string, 0, oppositeLetter, string_length);
};

// It is a Function to separate digits of the user
// input to be used as keypad digits.
// void separatingDigits (int inputNumber)
 // {
 //    int a, b, c;
 //    c = inputNumber%10;
 //     b = (inputNumber/10)%10;
 //     a = inputNumber / 100;
 //
 //     ListMnemonics(a, b, c, 0, 0);
 // };

Mnemonic::~Mnemonic()
{
    //dtor
}
