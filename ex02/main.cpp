#include "PmergeMe.hpp"
#include <iostream>

std::vector<unsigned int> parsing(int ac, char** av);

int main(int ac, char** av)
{
	/*-TRIER PAR PAIR-*/
	// std::vector<int>	elements = {47, 3, 88, 21, 65, 12, 94, 37, 8, 72, 56, 19, 99, 41, 27, 83, 14, 60, 5, 76, 33, 91};

	PmergeMe	sort;
	if(ac <= 1)
	{
		std::cout << "Need at least one argument" << std::endl;
		return 1;
	}

	try
	{
		sort.storeData(ac, av);
		sort.launch();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
