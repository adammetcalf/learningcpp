#include <iostream>

/*


	Arrays, like in all languages, allow us to store lots of the same datatype in 1 identifier

*/
int main()
{
	int testScore[30]{};												//allocate 30 (uninitiallised) integer variables in a fixed array. Each elemnt has the default init of 0
	int prime[5]{};														//allocate an array with space for 5 elements
	prime[0] = { 2 };                                                   //The 1st element has a value of 2
	prime[1] = { 3 };                                                   //The 1st element has a value of 3
	prime[2] = { 5 };                                                   //The 1st element has a value of 5
	prime[3] = { 7 };                                                   //The 1st element has a value of 7
	prime[4] = { 11 };                                                  //The 1st element has a value of 11

	int arrSize = sizeof(prime) / sizeof(prime[0]);						//to get the number of elements, we must divide the size of the array (in bytes) by the size of the datatype (in bytes)
	
	for (int i = 0; i < arrSize; i++) {									//for each elememnt in the array
		std::cout << prime[i] << '\n';									//print the element
	}

/*

	Arrays can contain any dataype, even structs! Even more arrays!!!!

*/

	struct Rectangle
	{
		int length{};
		int width{};
	};
	Rectangle rects[5]{};												//decalre an array with space for 5 rectangle structs
	rects[0].length = 6;												//updating a member of the rectangle in the first element of the array.

/*

	An array declared this this must be fixed size at compile time (ie, an array declared like this is not allowed to dynamically change, since it is allocated to the stack)

	There are ways to have dynamic heap allocated arrays.

*/

	int prime2[5]{ 2,3,5,7,11 };										//initialising a fixed array

/*

	If there are more initialisers than the array can hold, we get an error
	If there are less, the rest of the array is filled with a default of zero

*/
	int prime3[]{ 2,3,5,7,11 };											//Has the same initialisation effect as above 

/*

	Arrays can be initialised wiht enums, which have the benefit of self-documentation

*/

	enum Studentnames {
		alfie,
		terry,
		clive,
		steph,
		phil,

	};

	int scores[5]{};														//create array of 5 integers	
	scores[phil] = 76;														//allocate 76 to the 5th element of the array		

/*

	Another way is to have an extra entry in the enum, which can be used for the array size

*/


	enum Studentnames2 {
		alfie2,
		terry2,
		clive2,
		steph2,
		phil2,
		maxSize,
	};

	int scores2[maxSize]{};													//create array of 6 integers	
	scores[phil2] = 76;														//allocate 76 to the 5th element of the array		

/*

	We can't quite do the same for enum classes since they don't have implicit conversion to integer. the following code will throw an error:

	enum class students{
		a,
		b,
		c,
		studentsSize,
	};

	int scores3[students::studentsSize]{};													
	scores[students::c] = 76;

	We must perform a static cast to do this.
*/

	enum class students {
		a,
		b,
		c,
		studentsSize,
	};

	int scores3[static_cast<int>(students::studentsSize)]{};
	scores[static_cast<int>(students::c)] = 76;


	std::cin.get();
}