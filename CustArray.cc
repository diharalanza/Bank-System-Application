#include <iostream>
#include <string>
using namespace std;
#include "CustArray.h"


CustArray::CustArray()
{
  //initializes constructor
  custCount=0;
}

CustArray::~CustArray()
{
  //loops thru the customers array and deletes each customer object
  for(int i=0; i<custCount; i++){
    delete customers[i];
  }
}

bool CustArray::add(Customer* c){

  //erro if customers array is  full
  if (custCount==MAX_CUSTOMERS) {
    cout << "FAIL: MAX NUMBER OF CUSTOMERS FOR THIS CUSTOMERS COLLECTION" << '\n';
    return false;
  }

  //error if this  customer is already in array
  for(int i=0; i<custCount; i++){
    if (customers[i]->getCustID() == c->getCustID()) {
      cout << "FAIL: CUSTOMER " << c->getCustID() << " ALREADY IN COLLECTION" << '\n';
      return false;
    }
  }

  //else add to array
  customers[custCount]=c;
  std::cout << "SUCCESS: ADDED CUSTOMER " << c->getCustID() << '\n';
  custCount++;
  return true;

}

void CustArray::find(int id, Customer** c){

  //loops thru customers array and find the customer with given id, and sets that c parameter to the customer just found
  for(int i=0; i<custCount; i++){
    if (customers[i]->getCustID() == id) {
      *c = customers[i];
      break;
    }
  }
}

void CustArray::print()
{
  //Loops thru customers array and prints each customers info
  for(int i=0; i<custCount; i++){
    customers[i]->print();
    cout << "-------------------------" << "\n \n";
  }
  //prints number of customers
  cout << "# of Customers in this Bank: " << custCount << "\n \n";
  return;
}
