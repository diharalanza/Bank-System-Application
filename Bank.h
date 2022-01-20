#ifndef BANK_H
#define BANK_H

#include <string>
using namespace std;
#include "CustArray.h"
#include "Account.h"

//16*64
#define MAX_BANKACCS 1024

//A class that holds a bank. contains a name, an array of all accounts as
//accounnt pointers anda custArray Object a.k.a a collection of customers.

class Bank
{
  public:
    Bank(string="Unspecified");
    ~Bank();
    bool addCust(Customer*);
    bool addAcct(int, Account*);
    bool debit(int, float);
    bool credit(int, float);
    void print();

  private:
    string name;
    CustArray banksCusts;
    Account* banksAccs[MAX_BANKACCS];
    int bankAccCount;
};

#endif
