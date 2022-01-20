#ifndef CUSTARRAY_H
#define CUSTARRAY_H

#include <string>
using namespace std;
#include "Customer.h"

#define MAX_CUSTOMERS 64

//a collection class that contains an array of customer pointers. Used by the
//bank class.

class CustArray
{
  public:
    CustArray();
    ~CustArray();
    bool add(Customer*);
    void find(int, Customer**);
    void print();


  private:
    Customer* customers[MAX_CUSTOMERS];
    int custCount;
};

#endif
