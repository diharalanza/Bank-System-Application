OPT = -Wall

a1:	main.o Bank.o CustArray.o Customer.o Account.o
	g++ $(OPT) -o a1 main.o Bank.o CustArray.o Customer.o Account.o

main.o:	main.cc CustArray.h Customer.h Account.h
	g++ $(OPT) -c main.cc

Bank.o:	Bank.cc Bank.h CustArray.h Customer.h Account.h
	g++ $(OPT) -c Bank.cc

CustArray.o:	CustArray.cc CustArray.h Customer.h Account.h
	g++ $(OPT) -c CustArray.cc

Customer.o:	Customer.cc Customer.h Account.h
	g++ $(OPT) -c Customer.cc

Account.o:	Account.cc Account.h Customer.h
	g++ $(OPT) -c Account.cc

clean:
	rm -f *.o a1
