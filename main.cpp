// Course:  CS213 - Programming II  - 2018
// Title:   Assignment III - Task #1
// Program: CS213 - 2018 - A3
// Purpose: Using Class in developing a vending machine in separate files.
// Author1: Fatma Ashraf Ramadan  - 20170192 - G7
// Author2: Mariam Makram William - 20170283 - G8
#include <iostream>
#include "Stock.h"
#include "coinHandler.h"
#include <conio.h>
using namespace std;


int main()
{
    while(true)
    {
        /**Object from Child Class**/
        coinHandler item;
        cin >> item;
        cout <<item <<endl;
        cout << "\nPress any key to continue... ";
        getch();
        system("cls");
    }

    return 0;
}
