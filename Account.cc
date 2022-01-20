#include <iostream>
#include <string>
using namespace std;
#include "Account.h"

Account::Account(int aN, float aB)
{

//initializes constructor
  accNum  = aN;
  accBal  = aB;
}

int Account::getAccNum(){
  return accNum;
}

void Account::setCust(Customer* c){
  owner = c;
  return;
}

bool Account::debit(float a){

  //error if parameter is negative
  if (a<0) {
    cout << "FAIL: PLEASE ENTER A POSITIVE NUMBER (ACC #" <<accNum << ")" << '\n';
    return false;
  }
  //error if trying to deduct more than whats in account
  if(a>accBal){
    cout << "FAIL: NOT ENOUGH MONEY ($" << a << ") TO DEDUCT FROM ACCOUNT #" <<accNum << '\n';
    return false;
  }

  accBal-=a;
  cout << "SUCCESS: $" << a << " DEDUCTED FROM ACCOUNT #" << accNum << '\n';
  return true;

}

bool Account::credit(float a){
  //error if parameter is negative
  if (a<0) {
    cout << "FAIL: PLEASE ENTER A POSITIVE NUMBER (ACC #" <<accNum << ")" << '\n';
    return false;
  }
  accBal+=a;
  cout << "SUCCESS: $" << a << " ADDED TO ACCOUNT #" << accNum << '\n';
  return true;
}

void Account::print()
{
  //prints customer id
  cout << "Customer ID: " << owner->getCustID() << endl;
  //prints acc number
  cout << "Account Number: " << accNum << endl;
  //prints acc balance
  cout << "Account Balance: " << accBal << "\n\n";
  return;
}
