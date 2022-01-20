#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#define MAX_ACCOUNTS 16

//forward referencing account class
class Account;

//holds a customer that has id, name, acc number and array of account pointers
class Customer
{
  public:
    Customer(int=0, string="Unspecified");
    int getCustID();
    bool addAcct(Account*);
    void print();

  private:
    int custID;
    string custName;
    Account* accs[MAX_ACCOUNTS];
    int accCount;
};

#endif
