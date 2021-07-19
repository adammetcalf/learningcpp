/*
	
	How to sort a vector of objects by object property. This is a thing I found hard in the genetic algorithms project, so I made a SAP example to work out how to do it.
		
*/

#include <iostream>
#include <vector>
#include <algorithm>

class myClass {
private:

	int m_fitness{};

public:

	//constructor
	myClass(int fitness)
	{
		m_fitness = fitness;
	}

	//getter for the fitness
	int getFitness()
	{
		return m_fitness;
	}
};

class bigClass {

private:

	//vector to contain objects
	std::vector<myClass> m_population{};

public:

	//constructor
	bigClass()
	{

		//populate vector with 10 objects of "myClass"
		for (int i = 0; i < 10; i++)
		{
			m_population.push_back(myClass(100 - i));

		}

		//check each element in turn to see if sorted
		for (auto element : m_population) {
			std::cout << element.getFitness() << '\n';
		}

		//Call the function to sort for fitness of the objects
		sortFitness();

		//check each element in turn to see if sorted
		for (auto element : m_population) {
			std::cout << element.getFitness() << '\n';
		}

	}

	//function to sort the vecotr by the fitness of each object
	void sortFitness()
	{
		std::sort(m_population.begin(), m_population.end(), [](myClass& one, myClass& two) {return one.getFitness() < two.getFitness(); });
	}

	//function to return population
	std::vector<myClass> getPop()
	{
		return m_population;
	}
};

int main() {

	//instantiate bigClass object
	bigClass popCheck;

	//get the population vector of objects from bigClass
	std::vector<myClass> test = popCheck.getPop();

	//check each element in turn to see if sorted
	for (auto element : test) {
		std::cout << element.getFitness() << '\n';
	}



	std::cin.get();

}