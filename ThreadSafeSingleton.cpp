// ThreadSafeSingleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <future>
#include <mutex>
#include "ThreadSafeSingleton.h"
using namespace std;

/* For more ways to make thread safe while using the singleton design pattern
--> https://www.modernescpp.com/index.php/thread-safe-initialization-of-a-singleton 
*/


void functionWithThreads() {
	for (int i = 0; i < 10; i++) {
		SingletonThreads &one = SingletonThreads::getInstance();
		cout << "The new object created is " << &one << "\n";
	}
}
void _fThreadSafeLocks() {
	for (int i = 0; i < 10; i++) {
		SingletonLockMechanism *one = SingletonLockMechanism::getIntace();
		cout << "The new object created is using locks  " << one << "\n";
	}
}
int main()
{
	auto fut1 = std::async(std::launch::async, functionWithThreads);
	auto fut2 = std::async(std::launch::async, functionWithThreads);
	auto fut3 = std::async(std::launch::async, functionWithThreads);
	auto fut4 = std::async(std::launch::async, functionWithThreads);

	auto fut5 = std::async(std::launch::async, _fThreadSafeLocks);
	auto fut6 = std::async(std::launch::async, _fThreadSafeLocks);
	auto fut7 = std::async(std::launch::async, _fThreadSafeLocks);
	auto fut8 = std::async(std::launch::async, _fThreadSafeLocks);
	
	

    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
