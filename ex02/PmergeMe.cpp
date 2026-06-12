#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( PmergeMe const & src ) {}

PmergeMe & PmergeMe::operator=( PmergeMe const & rightSide )
{
	if (this != &rightSide)
	return *this;
}

PmergeMe::~PmergeMe( void ) {}
