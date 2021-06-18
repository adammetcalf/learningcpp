#include <iostream>


int main()
{

	int a = 8;														//declare integer, with name 'a', with value 8. Creates a 4 byte space in memory.
	int b;															//Not actually required to initialise the variable, but this can lead to undefined behaviour
	int c{ 6 };														//another method for initialising - list initialising
	int d(3);														//Yet another way of initialising variables. I don't like this because it looks like a function now.

	/*
	
	List initialising is good because it disallows narrowing conversions, meaning the compiler will throw an error. Narrowing conversion is where precision is lost:

	double d = 5.4;
	int x = d;														//x will only hold the value 5 due to narrowing conversion
	
	*/



	std::cin.get();

}