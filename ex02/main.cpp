#include "PmergeMe.hpp"
#include <iostream>

std::vector<unsigned int> parsing(int ac, char** av);

int main(int ac, char** av)
{
	/*-TRIER PAR PAIR-*/
	// std::vector<int>	elements = {47, 3, 88, 21, 65, 12, 94, 37, 8, 72, 56, 19, 99, 41, 27, 83, 14, 60, 5, 76, 33, 91};

	PmergeMe	sort;
	if(ac <= 1)
		return 1;

	try
	{
		std::vector<unsigned int>	vec = parsing(ac, av);
		for(std::vector<unsigned int>::iterator it = sort.vec.begin(); it != vec.end(); ++it)
			std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

template <typename T>
std::vector<unsigned int> parsing(int ac, char** av, T & list)
{
	char* 						endptr;
	long						n;

	for(int i = 1; i < ac; ++i)
	{
		n = std::strtol(av[i], &endptr, 10);
		if (n < 0)
			throw std::invalid_argument("Error: Can't be a negative number");
		if (*endptr != '\0')
			throw std::invalid_argument("Error: Only numbers are allowed");
		if (n > __INT_MAX__)
			throw std::invalid_argument("Error: Overflow");
		list.push_back(static_cast<unsigned int>(n));
	}
}
