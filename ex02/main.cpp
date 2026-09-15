#include "PmergeMe.hpp"
#include <iostream>

std::vector<unsigned int> parsing(int ac, char** av);

int main(int ac, char** av)
{
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
