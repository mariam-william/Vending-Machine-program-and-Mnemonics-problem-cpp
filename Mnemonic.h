#ifndef MNEMONIC_H
#define MNEMONIC_H
#include <bits/stdc++.h>

using namespace std;

class Mnemonic
{
    public:
        Mnemonic();

        /**Declaring the keypad char array**/
        const char KeypadLetters[10][5] = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

        /**List mnemonics function to get all combinations for every letter**/
        void ListMnemonics (int string[], int current_Index, char oppositeLetter[], int string_length);

        /**A Print Fn for printing mnemonics and opposite letters for given number**/
        void PrintMnemonics (int string[], int string_length);


        virtual ~Mnemonic();

    protected:

    private:
};

#endif // MNEMONIC_H
