#include "Stock.h"
#include<cstdlib >
#include<bits/stdc++.h>
#include<conio.h>

///Default Constructor To set the Quantity of items to Quantity Array.

Stock::Stock()
{
    /** to test function checkStock()
     Quantity[0] = 0;
     Quantity[1] = 0;
     Quantity[2] = 0;
     Quantity[3] = 00;
     Quantity[4] = 0;
     Quantity[5] = 0;
     Quantity[6] = 0;
     Quantity[7] = 0;
     Quantity[8] = 0;
     Quantity[9] = 0;
     Quantity[10]=0;**/


    for (int i=1; i<9; i++)
    {
        Quantity[0] = 0;
        Quantity[i] = 10;
    }
}
///Boolean Function To Check The Stock Quantity
bool Stock::checkStock()
{
    Stock it;
    if(it.Quantity[0]==0 && it.Quantity[1]==0 && it.Quantity[2]==0 && it.Quantity[3]==0 && it.Quantity[4]==0 && it.Quantity[5]==0 && it.Quantity[6]==0 && it.Quantity[7]==0 && it.Quantity[8]==0 && it.Quantity[9]==0)
    {
        return false;
    }
    else{
        return true;
    }
}
///Parameterize Constructor To set choice and userMoney.
Stock::Stock(int ch , float um)
 {
     choice = ch;
     userMoney = um;
 }

///Function to get choice.
int Stock::getChoice()
{
    return this->choice;
}

///A Function to get item name.
string Stock::getItem()
{
    return itemName[choice-1];

}
///Getter Function to get value of user Money.
float Stock::getuserMoney()
{
    return this->userMoney;

}

///Function of Type Istream returns an istream value with Menu and conditions to check choice validation.
istream& operator>> (istream& in, Stock& item)
{

    ///Menu For User...
    cout << "        Vending Machine is Saying Hi...\n"   << endl
         << "Item: "         << setw(20)  << "Price:  " << endl
         << "----------------------------------"        << endl
         << " 1- Pepsi"      << setw(15)  <<"10 L.E"    << endl
         << " 2- Chipsy"     <<setw(14)   << "5 L.E"    << endl
         << " 3- Bake Rolz"  << setw(11)  <<"3 L.E"     << endl
         << " 4- SunBites"   << setw(12)  <<"3 L.E"     << endl
         << " 5- Marshmellow"<< setw(9)   <<"3 L.E"     << endl
         << " 6- KitKat"     << setw(14)  <<"10 L.E"    << endl
         << " 7- Galaxy"     << setw(14)  <<"10 L.E"    << endl
         << " 8- Cadbury"    << setw(13)  <<"10 L.E"    << endl
         << " 9- Lambada"    << setw(13)  <<"1.5 L.E"   << endl
         << "10- Tuc"        << setw(17)  <<"5 L.E"     << endl << endl
         << "Enter the number of your favorite item: ";

    in >> item.choice;


    ///Condition to exit program when user inputs ZERO.
    if(item.choice == 0)
    {
        exit(0);
    }

    ///Checking choice validation.
    while(item.choice < 0 || item.choice > 10 )
    {
        cout << "\nInvalid Choice !!" << endl << "please enter a valid choice : ";
        in >> item.choice;
    }
    cout << "\nPlease enter your Money : ";
    in >> item.userMoney;
     if(!item.checkStock())
        {
            cout << "Opps!! Vending Machine is empty now...would you try later.."<<endl;
            exit(0);

        }


    ///To make user re-choose an other item if first chosen item doesn't exist
    if(!item.checkQuantity())
    {
        cout<< "Enter the number of your favorite item: ";
        in >> item.choice;

        ///Condition to exit program when user inputs ZERO.
        if(item.choice == 0)
        {
            cout << "\n\nHere Is Your Money : " <<item.getuserMoney() <<
                    endl << "\n\n\n\nsHOPPING TO SEE YOU SOOON..";
            exit(0);
        }
         ///Condition to exit program when All Quantity = ZERO.


        ///Checking choice validation.
        while(item.choice < 0 || item.choice > 10 )
        {
            cout << "\nInvalid Choice !!" << endl << "please enter a valid choice : ";
            in >> item.choice;
            if(item.choice == 0)
            {
                exit(0);
            }
        }
        cout << "\nPlease enter your Money : ";
        in >> item.userMoney;



    }
     return in;
}

///operator to check if user money < price of item.
bool Stock::operator< (Stock ob)
{
    if(ob.getuserMoney() < price[choice-1])
    {
        return true;
    }
    else
        return false;
}

///operator to check if user money < or = price of item.
bool Stock::operator<=(Stock ob)
{
    int number = getChoice();
    if(getuserMoney() <= price[number-1])
    {
             return true;
    }
     return false;
}

///A Function to decrement item from Stock
int Stock::item_Decrement()
{
   int n = --(this->Quantity[this->choice-1]);
  return n;

}

///function to check if chosen item exist or not.
bool Stock::checkQuantity()
{
    if(this->Quantity[choice-1] == 0)
    {
        cout << "Sorry! This item doesn't exist. \nPlease choose another item. " << endl;
        return false;

    }
    else
    {
        return true;
    }

}

///A Function to check if userMoney < Price of chosen Item.
bool Stock::checkSufficient()
{
    int number = getChoice();
    if(getuserMoney() < price[number-1])
    {
        return false;
    }
    else
    {
        return true;
    }
}
