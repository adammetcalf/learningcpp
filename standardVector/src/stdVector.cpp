#include<iostream>
#include <vector>																	//include the vector library
#include <string>

/*

A vector is a container of objects. A vector is a class template. We define what type of information a vector will hold using <>.

*/

int main()
{
	std::vector<std::string> svec;													//defualt initialisation, svec has no elements
	std::vector<int> ivec;															//default init of integer vector ivec
	std::vector<int> ivec2{1,2,3};													//list initialisation of vector
	std::vector<int> ivec2again = ivec2;											//ive2again is a copy of ivec2


	//note we can create a specified number of elements
	std::vector<int> ivec3(10);														//10 elements each initialised to 0
	std::vector<int> ivec4(10, -2);													//10 elements each initialised to -2

/*

Vectors grow efficiently, maning it is perfectly acceptable and fast (often faster than defining a vector of a specific size) to add elements at runtime.

*/
	std::vector<int> v2;
	for (int i = 0; i < 100; i++)													//run 100 times
		v2.push_back(i);															//append new value to vector v2

	for (auto i : v2)																//for each member in vector v2
		std::cout << i << '\n';														//print the element

}