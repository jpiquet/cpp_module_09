#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe( void ) : _vec(), _deque() {}

PmergeMe::PmergeMe( PmergeMe const & src ) {}

PmergeMe & PmergeMe::operator=( PmergeMe const & rightSide )
{
	return *this;
}

PmergeMe::~PmergeMe( void ) {}

void	PmergeMe::storeData(int ac, char** av)
{
	char* 						endptr;
	long						n;

	for(int i = 1; i < ac - 1; ++i)
	{
		n = std::strtol(av[i], &endptr, 10);
		if (n < 0)
			throw std::invalid_argument("Error: Can't be a negative number");
		if (endptr != NULL)
			throw std::invalid_argument("Error: Only numbers are allowed");
		if (n > __INT_MAX__)
			throw std::invalid_argument("Error: Overflow");
		_vec.push_back(static_cast<unsigned int>(n));
		_deque.push_back(static_cast<unsigned int>(n));
	}
}

void	PmergeMe::sortList()
{
	
}
