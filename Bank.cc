#include <iostream>
#include <string>
using namespace std;
#include "Bank.h"

Bank::Bank(string n)
{
  //inits constructor
  name = n;
  bankAccCount = 0;
}

Bank::~Bank()
{
  //loops thru all accs in bank and deletes each
  for(int i=0; i<bankAccCount; i++){
    delete banksAccs[i];
  }
}

bool Bank::addCust(Customer* c){
  //calls the custArray classes add function with given parameter c and uses same return value
  return banksCusts.add(c);
}

bool Bank::addAcct(int custId, Account* acct){

  //checks if banks account array is full and return false if so
  if (bankAccCount==MAX_BANKACCS) {
    cout << "FAIL: MAX NUMBER OF ACCOUNTS IN THIS BANK" << '\n';
    //deletes here since wont be added to banks acc array and deleted with destructor
    delete acct;
    return false;
  }

  //if the  account already exists in the banks account array return false
  for(int i=0; i<bankAccCount; i++){
    if (banksAccs[i]->getAccNum() == acct->getAccNum()) {
      cout << "FAIL: ACCOUNT #" << acct->getAccNum() << " ALREADY EXISTS" << '\n';
      //deletes here since wont be added to banks acc array and deleted with destructor

      delete acct;
      return false;
    }
  }

  //temporary customer pointer
  Customer* tempCust = NULL;

  //if find is successful, tempCust will point to the customer with the given id, else return false meaning customer does not exist
  banksCusts.find(custId, &tempCust);
  if (tempCust == NULL) {
    cout << "FAIL: CUSTOMER " << custId << " DOES NOT EXIST!" << '\n';
    //deletes here since wont be added to banks acc array and deleted with destructor
    delete acct;
    return false;
  }

  //at this point means no errors, ready to add.

  //first add the account to banks account array
  banksAccs[bankAccCount]=acct;
  bankAccCount++;

  //add the account to the customers account array
  tempCust->addAcct(acct);

  //set this accounts customer to the customer with given id
  acct->setCust(tempCust);

  return true;

}

bool Bank::debit(int accNum, float amount){

  //loops thru banks account array and looks for acc with given accNum. if the acc is found, calls debit function on it and returns its value
  for(int i=0; i<bankAccCount; i++){
      if (banksAccs[i]->getAccNum() == accNum) {
        return banksAccs[i]->debit(amount);
      }
  }
  //if could not find the account
  cout << "COULD NOT FIND ACCOUNT #" << accNum << '\n';
  return false;
}

bool Bank::credit(int accNum, float amount){

  //  //loops thru banks account array and looks for acc with given accNum. if the acc is found, calls credit function on it and returns its value
  for(int i=0; i<bankAccCount; i++){
      if (banksAccs[i]->getAccNum() == accNum) {
        return banksAccs[i]->credit(amount);
      }
  }
  //if could not find the account
  cout << "COULD NOT FIND ACCOUNT #" << accNum << '\n';
  return false;
}

void Bank::print(){

  cout << "LIST OF CUSTOMERS:" << '\n';
  cout << "------------------" << "\n";
  cout << "------------------" << "\n \n";
  //print all customers
  banksCusts.print();
  cout << '\n';

  cout << "LIST OF ACCOUNTS:" << '\n';
  cout << "-----------------" << "\n";
  cout << "-----------------" << "\n \n";
  //loops thru accounts array and prints each account
  for(int i=0; i<bankAccCount; i++){
    banksAccs[i]->print();
    cout << "-------------------------" << "\n \n";
  }

  //prints number of accounts
  cout << "# of Accounts in this bank: " << bankAccCount << "\n \n";
}
