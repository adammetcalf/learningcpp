#include <iostream>
#include <iterator>														//for obtaining the array size

/*

	When passing a normal variable to a function C++ copies that variable to the function. Copying large arrays is expensive, hoever,
	so arrays work differently. The actual array is passed to the function, so any changes to the array
	in the function progagate through. this is because an array is essentially just a pointer to a memeory space, unlike normal varaibles.

*/

void passValue(int value)												//recieves an integer
{
	value = 99;															//value is a local variable to this function
}																		//local variable destroyed, original value is unchanged

void passArray(int prime[5])											//recies the actrual array (which is a pointer to a memory address)
{
	prime[3] = 99;														//updates the actual array
}																		//end of function scope, but the actual array passed in has been updated.


int main()
{


	int value{ 2 };														//initialising an integer
	std::cout << value << '\n';											//will print "2"

	passValue(value);													//call function

	std::cout << value << '\n';											//will print "2" still, since the variable was not updated

	int prime[5]{ 2,3,5,7,11 };											//initialising a fixed array

	int arrSize = sizeof(prime) / sizeof(prime[0]);						//to get the number of elements, we must divide the size of the array (in bytes) by the size of the datatype (in bytes)
	int arrSizeAgain = std::size(prime);								//A better method, using the <iterator> library. note, std::size() cannot be called from a function.

	for (int i = 0; i < arrSize; i++) {									//for each elememnt in the array
		std::cout << prime[i] << '\n';									//print the element
	}

	passArray(prime);													//call fucntion

	for (int i = 0; i < arrSize; i++) {									//for each elememnt in the array
		std::cout << prime[i] << '\n';									//print the element
	}



	std::cin.get();
}