#ifndef STOCK_H
#define STOCK_H
#include<iostream>
#include <iomanip>

using namespace std;

class Stock
{
    ///Function of Type Istream returns an istream value with Menu and conditions to check choice validation.
    friend istream& operator>> (istream& in , Stock& item);

    public:
        ///Default Constructor To set the Quantity of items to Quantity Array.
        Stock();
        ///Parameterize Constructor To set choice and userMoney.
        Stock(int ch , float um);

        ///Function to get the input to user Money.
        void getuserMoney(float money);

        ///Function to set the input to choice.
        void setChoice(int choice1);

        ///to check if user money < the price of item he chosen
        bool operator< (Stock);

        ///A Function to get item name.
        string getItem();

        ///A Function to decrement item from Stock
        int item_Decrement();

        ///function to check if chosen item exist or not.
        bool checkQuantity();

        ///Function to get choice.
        int getChoice();

        ///A Function to check if userMoney < Price of chosen Item.
        bool checkSufficient();

        ///operator to check if user money < or = price of chosen item or not
        bool operator<=(Stock ob);

        ///Getter Function to get value of user Money
        float getuserMoney();


         ///Manually Setting items names to Array.
        string itemName[10] = {"Pepsi", "Chipsy", "Bake Rolz", "Sun Bites", "Marshmellow",
                                "KitKat", "Galaxy", "Cadbury", "Lambada", "Tuc"};

         ///Manually Setting items Prices to Array.
        float price[10] = {10, 5, 3, 3, 3, 10, 10, 10, 1.5, 5};
        ///Boolean Function To Check The Stock Quantity
        bool checkStock();


    protected:
        int Quantity[10];
        int choice;
        float userMoney;

    private:
};


#endif // STOCK_H
