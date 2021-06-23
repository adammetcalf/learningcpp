#include <iostream>



int main()
{
	int x{ 5 };														//declare variable x
	std::cout << x << '\n';											//print the value of x
	std::cout << &x << '\n';										//print the address of x

	/*
			The & operator allows us to obtain the memory address of an object
			The * operator allows us to get the value held at a particular memory address (this is know as dereferencing)
	*/

	std::cout << *(&x) << '\n';										//print the value at the address of x (dereference the address)


	/*
	
			With knowledge of & and * we may now talk about pointers.
			A pointer is a variable which holds a memory address as its value. They must be declared as a type, since different 
			data types reuqire different amounts of memory

	*/

	int* iPtr{};													//declaring a pointer. this is a null pointer because it is not pointing to anything
	std::cout << iPtr << '\n';										//a null pointer will print a series of 000s

	int* y{&x};														//declaring a pointer y to point towards the memory address of variable x
	std::cout << y << '\n';											//print the address of x (which is the value of y)
	std::cout << &y << '\n';										//print the address of y 

	/*

		The address of operator (&) returns a pointer, the type of which is derived from the type of the variable from which
		we are obtaining the address

	*/

	int a{ 5 };														//declare an integer
	float b{ 3.66 };												//declare a float
	std::cout << typeid(&a).name() << '\n';							//prints the type of the pointer return by &a
	std::cout << typeid(&b).name() << '\n';							//prints the type of the pointer return by &b

	/*

		Indirection through pointers: Once we have a pointer, it is common to use that pointer to obtain that data of the variable which is being pointed to

	*/

	int value{ 5 };													//create a variable named value
	std::cout << "the address of 'value': " << & value << '\n';		// prints the address of value
	std::cout << "the data of 'value': " << value << '\n';			// prints the address of value

	int* ptr{ &value };												//create a pointer to value
	std::cout << ptr << '\n';										//print address held in pointer (which is &value)
	std::cout << *ptr << '\n';										//derefecne the pointer, prints that value of 'value'

	/*

		Once assigned the pointer cannot be reassigned to another value

		Writing a value to a pointer assigns that value to the original variable

	*/

	*ptr = 7;														//derefecne the pointer, assign new value
	std::cout << "the data of 'value': " << value << '\n';		// prints the address of value, whihc should now be 7

	/*
	
	Whats the point?

	1. Arrays are implemented using pointers
	2.Pointers are the only way to dynamically allocate memory
	3. They can be used to pass a fucntion as a parameter to another function
	4. They can be used to achieve polymorphism when dealing with inheritence
	5. They can be used to have one struct/class point at another struct/class
	
	*/


	std::cin.get();
}