#ifndef COINHANDLER_H
#define COINHANDLER_H
#include<iostream>
#include "Stock.h"

using namespace std;

class coinHandler : public Stock
{
    ///Function to out Item and Money for user and calculate and out change.
    friend ostream& operator<< (ostream& out , coinHandler item);

    public:
        coinHandler();
        ///ٍsetting number of each bill in our safe.
         void setCoin(int coin[]);
        ///function to decrement coins from safe to give user his change.
        int coin_Decrement_Increment();


    protected:
        int coin[6];

    private:
};

#endif // COINHANDLER_H
