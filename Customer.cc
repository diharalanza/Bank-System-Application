#include <iostream>
#include <string>
using namespace std;
#include "Customer.h"
#include "Account.h"

Customer::Customer(int id, string name)
{
  //initializes constructor
  custID =  id;
  custName = name;
  accCount = 0;

}

int Customer::getCustID(){
  return custID;
}

bool Customer::addAcct(Account* acc){

  //error if array is full
  if (accCount==MAX_ACCOUNTS) {
    std::cout << "FAIL: MAX # OF ACCOUNTS REACHED FOR CUSTOMER " << custID << '\n';
    return false;
  }

  //error if account already exists
  for(int i=0; i<accCount; i++){
    if (accs[i]->getAccNum() == acc->getAccNum()) {
      cout << "FAIL: ACCOUNT #" << acc->getAccNum() << " ALREADY EXISTS" << '\n';
      return false;
    }
  }

  accs[accCount]=acc;
  accCount++;
  std::cout << "SUCCESS: ADDED ACCOUNT #" << acc->getAccNum() <<" TO CUSTOMER " << custID << '\n';
  return true;
}

void Customer::print()
{
  //prints customer id
  cout << "Customer ID: " << custID << endl;
  //prints customer name
  cout << "Customer Name: " << custName << "\n";
  //number of  accounts
  cout << "# of Accounts: " << accCount << "\n \n";

  //loops thru customers account array and prints each accounts info
  for(int i=0; i<accCount; i++){
    cout << "Account #" << i+1 << ": " << endl;
    accs[i]->print();
  }



  return;
}
