#include <iostream>
#include "supportingFiles/add.h"																			//including the header file for the add forward declaration

/*
* 
			We use header files to provide forward declarations of files that we intend to use.

*/


int main()
{

	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';							//calling the add function, which is declared in add.cpp
	std::cin.get();
}