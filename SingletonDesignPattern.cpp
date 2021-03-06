// SingletonDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "SingletonDesignPattern.h"
#include "TemplatisedSingleton.h"
using namespace std;
/* To test templatised singleton class creation*/
class Logger {
public:
	Logger() {};
	~Logger() {};
	void testCode();
};
void Logger::testCode() {
	cout << "The reference address of the object is " << this << "\n";
	cout << "Called using the singleton method\n";
}
/* For a sinngleton class make sure the copy constructor and assignemnt are deleted
or made private so that we can restrict the unprotected object creation */
int main()
{
	/*Trying to find how many instances have been created to test print the
	//address if the object */
	SingletonDP *one = SingletonDP::getInstance();
	SingletonDP *two = SingletonDP::getInstance();
	cout << "Address of first object " << one << "\n";
	cout << "Address of secon object " << two << "\n";
	Logger l;
	l.testCode();
	Logger l2;
	l2.testCode();
	cout << "\n\n\nMaking the logger class singleton <<\n ========================\n";
	//Alias naming
	typedef SingletonDPTemp<Logger> onetemp;
	Logger *l3 = onetemp::getInstance();
	l3->testCode();
	Logger *l4 = onetemp::getInstance();
	l4->testCode();
	


    std::cout << "Hello World!\n"; 
}

