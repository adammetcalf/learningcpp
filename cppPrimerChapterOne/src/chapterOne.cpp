#include <iostream>

int main()
{
	std::cout << "test message" << std::endl;									//endl flushes the buffer. C++ primer suggest to always flush the buffer, but I have seen disagreement elsewhere

/*

	while loops

*/

	int sum{ 0 }, val{ 1 };														//init 2 variables
	while (val <= 10)															//keep executing while val <= 10
	{
		sum += val;																//sum = sum + val
		++val;                                                                  //increment val
	}
	std::cout << "the sum of 1 - 10 inclusive is: " << sum << '\n';

	std::cin.get();



}