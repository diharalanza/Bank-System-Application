#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;
#include "Customer.h"


//Class that hold attributes for an account object
//Holds a customer object in owner attributes

class Account
{
  public:
    Account(int=0, float=0);
    int getAccNum();
    void setCust(Customer*);
    bool debit(float);
    bool credit(float);
    void print();

  private:
    int accNum;
    float accBal;
    Customer* owner;
};

#endif
