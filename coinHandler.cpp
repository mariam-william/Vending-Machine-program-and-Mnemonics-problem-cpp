#include "coinHandler.h"
#include<bits/stdc++.h>
#include<cmath>
#include<conio.h>

coinHandler::coinHandler()
{}

///ٍsetting number of each bill in our safe.
void coinHandler::setCoin(int coin[])
{

   coin[0] = 300; /**For 0.5 L.E**/
   coin[1] = 300; /**For  1 L.E**/
   coin[2] = 300; /**For  5 L.E**/
   coin[3] = 300; /**For 10 L.E**/
   coin[4] = 300; /**For 20 L.E**/
   coin[5] = 300; /**For 50 L.E**/
}

///function to add user money to our safe and decrement his change from our save.
int coinHandler::coin_Decrement_Increment()
{
    if (userMoney == 50)
    {
        coin[5]++;
    }
    else if (userMoney == 20)
    {
        coin[4]++;
    }
    else if(userMoney == 10)
    {
        coin[3]++;
    }
    else if(userMoney == 5)
    {
        coin[2]++;
    }
    else if(userMoney < 5)
    {
        if (userMoney/1.5 == 1)
        {
            coin[1]++;
            coin[0]++;
        }
        else
        {
            coin[1] += userMoney;
        }
    }
    ///Decrementing Customer change from our financial safe
    if(userMoney > price[choice-1])
    {

       float temp = userMoney - price[choice-1];
      coin[2]-= (temp-(fmod(temp , 5.0)))/5;
       while (fmod(temp , 5.0) >= 1)
       {
           coin[1]--;
           temp--;
       }
       if (temp==0.5)
       {
           coin[0]--;
       }
    }
}

///Function to out Item and Money for user and calculate and out change.
ostream& operator<< (ostream& out , coinHandler item)
{
    ///Case #1 : if Quantity of particular = 0
    if(!item.checkSufficient())
    {
        out << "Sorry Your Not Enough to buy chosen item" << endl
            <<"Here is your money  : " << item.getuserMoney();
    }
    out << endl;
    ///Case #2 : when required item is exist and user money > or = to the price.
    if(item.checkQuantity() &&(item.checkSufficient()) )
    {
        string name = item.getItem();
        out << "Here Is Your Item : " << name <<endl;
        item.item_Decrement();

    }
      out << endl;
    ///Case #3 : when user Money = price of chosen item...so NO change.
    if(item.getuserMoney() == item.price[item.getChoice()])
    {
         string name = item.getItem();
        out << "Here Is Your Item : " << name <<endl;
        item.coin_Decrement_Increment();
    }
      out << endl;
     ///Case #4 : when user Money > price of chosen item.
     ///this function calculates the change .
    if(item.getuserMoney() > item.price[item.getChoice()])
    {
        out << "Your Change = " <<endl;
///change_5 = change of 0.5 ///change1 = change of 1 ***change5 = change of 5 ///change10 = change of 10 ///change20 = change of 20
        int change_5 = 0  ,change1 = 0 , change5 = 0 , change10 = 0 , change20=0 , change50=0; ///change50 = change of 50
        item.coin_Decrement_Increment();
       float temp = item.getuserMoney() - item.price[item.getChoice()-1];
       ///InCase the change is 50 P.L
        while(temp >= 50)
       {
            change50++;
            temp-=50;
       }
        out << setw(15)<<change50 << setw(3) << "  of 50 P.L. " <<endl;

       ///InCase the change is 20 P.L
        while(temp >= 20)
       {
            change20++;
            temp-=20;
       }
        out << setw(15)<<change20 << setw(3) << "  of 20 P.L. " <<endl;

       ///InCase the change is 10 P.L
       while(temp >= 10)
       {
            change10++;
            temp-=10;
       }
       out << setw(15)<<change10 << setw(3) << "  of 10 P.L. " <<endl;

       ///InCase the change is 5 P.L.
        while(temp >= 5)
        {
            change5++;
            temp-=5;
        }
        out <<setw(15)<< change5 << setw(3) << "  of 5 P.L. " <<endl;

       ///InCase the change is 1P.L.
       while (temp >= 1)
       {
           change1++;
           temp-=1;
       }
        out << setw(15)<<change1 << setw(3) << "  of 1 P.L. " <<endl;

       ///InCase the change is 0.5 P.L.
       if (temp==0.5)
       {
           change_5++;
       }
        out <<setw(15)<< change_5 << setw(3) << "  of 0.5 P.L. " <<endl;
    }

    out<<"\n\n\n HOPPING TO SEE YOU SOOON..\n\n\n";
    return out;
}


