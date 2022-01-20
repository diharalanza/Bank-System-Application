#include <iostream>
#include <string>
using namespace std;

#include "Bank.h"

void initBank(Bank&);
void processTransactions(Bank&);

//simulates a bank. creates a bank object. creates a handfull of accounts and
//customer objects and adds to the bank. using the initBank funnctionn. Process
//-ing of debit and credit happens using the processTransactions function.
//print bank before processing and after inorder to compare. deletes bank at end.

//author: Dihara Lanza (exccept void initBank(Bank&); and void processTransactions(Bank&);)

int main(){
  //declaring the bank object
  Bank* myBank = new Bank("my bank");
  //creating a reference for the 2 functions
  Bank& b = *myBank;

  cout << "Initializing bank..." << "\n \n";
  initBank(b);
  cout << '\n';
  //prints entire bank
  b.print();

  cout << "Processing transactions..." << "\n \n";
  processTransactions(b);
  cout << '\n';
  //prints entire bank
  b.print();

  //deletes bank
  delete myBank;
  return 0;
}


void initBank(Bank& b)
{
  b.addCust(new Customer(1001, "Bill"));
  b.addCust(new Customer(1002, "Laura"));
  b.addCust(new Customer(1003, "D'Anna"));
  b.addCust(new Customer(1004, "Kara"));
  b.addCust(new Customer(1005, "Lee"));
  b.addCust(new Customer(1006, "Six"));
  b.addCust(new Customer(1007, "Ellen"));
  b.addCust(new Customer(1008, "Sharon"));
  b.addCust(new Customer(1009, "Sam"));
  b.addCust(new Customer(1010, "Galen"));

  b.addAcct(1010, new Account(200120, 33.4f));
  b.addAcct(1001, new Account(200121, 100.34f));
  b.addAcct(1007, new Account(200122, 540.22f));
  b.addAcct(1005, new Account(200123, 2323.44f));
  b.addAcct(2001, new Account(200124, 99.99f));
  b.addAcct(1005, new Account(200125, 344.89f));
  b.addAcct(1007, new Account(200126, 74.43f));
  b.addAcct(1003, new Account(200127, 1783.55f));
  b.addAcct(1003, new Account(200128, 98.77f));
  b.addAcct(1004, new Account(200129, 5.89f));
  b.addAcct(1002, new Account(200130, 77.77f));
  b.addAcct(1008, new Account(200134, 53.21f));
  b.addAcct(1002, new Account(200131, 98.8f));
  b.addAcct(1007, new Account(200132, 234.54f));
  b.addAcct(1007, new Account(200133, 789.11f));
  b.addAcct(1008, new Account(200135, 1010.88f));
  b.addAcct(1005, new Account(200136, 831.43f));
  b.addAcct(1001, new Account(200137, 2545.76f));
  b.addAcct(1002, new Account(200138, 987.00f));
  b.addAcct(1008, new Account(200139, 11.65f));
}

void processTransactions(Bank& b)
{
  b.debit(200127, 50.00f);
  b.debit(200155, 150.00f);
  b.debit(200129, 250.00f);
  b.debit(200121, 100.00f);
  b.debit(200120, 5.00f);
  b.debit(200138, 43.88f);
  b.debit(200138, 245.98f);
  b.debit(200139, 15.00f);
  b.debit(200133, 388.23f);
  b.debit(200132, 100.00f);
  b.debit(200130, 5.00f);
  b.debit(200130, -10.00f);

  b.credit(200122, -8.99f);
  b.credit(200124, 88.79f);
  b.credit(200129, 88.79f);
  b.credit(200126, 223.12f);
  b.credit(200125, 786.09f);
  b.credit(200125, 433.12f);

}
