#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>


PmergeMe::PmergeMe( void ) : _vec(), _deque() {}

PmergeMe::PmergeMe( PmergeMe const & src ) : _vec(src._vec), _deque(src._deque) {}

PmergeMe & PmergeMe::operator=( PmergeMe const & rightSide )
{
	if (this != &rightSide)
	{
		_vec = rightSide._vec;
		_deque = rightSide._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe( void ) {}

void	PmergeMe::storeData( int ac, char** av )
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
		if (n > __INT_MAX__ || n < INT_MIN)
			throw std::invalid_argument("Error: Overflow");
		_vec.push_back(static_cast<int>(n));
		_deque.push_back(static_cast<int>(n));
	}
}

void	printTime( long long vector, long long deque, size_t nElements )
{
	std::cout << "Time to process a range of " << nElements << " elements with std::vector = " << vector << "us" << std::endl;
	std::cout << "Time to process a range of " << nElements << " with std::deque =  " << deque << "us" << std::endl;
}

void	PmergeMe::launch( void )
{
	timeval start;
	timeval end;

	long long vectorTime;
	long long dequeTime;

	std::cout << "Before: ";
	printVec();

	gettimeofday(&start, NULL);
	_vec = sortVec(_vec);
	gettimeofday(&end, NULL);

	vectorTime = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	
	gettimeofday(&start, NULL);
	_deque = sortDeque(_deque);
	gettimeofday(&end, NULL);

	dequeTime = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);

	std::cout << "After:  ";
	printVec();

	printTime(vectorTime, dequeTime, _vec.size());
}

void	PmergeMe::printVec( void ) const
{
	std::vector<int>::const_iterator it;

	for(it = _vec.begin(); it != _vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque( void ) const
{
	std::deque<int>::const_iterator it;

	for(it = _deque.begin(); it != _deque.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// size_t	binarySearch(std::vector<int> mainChain, Pair pair)
// {
// 	size_t	bornePos;

// 	for (size_t i = 0; i < mainChain.size(); ++i)
// 	{
// 		if (pair.winner == mainChain[i])
// 		{
// 			bornePos = i;
// 		}
// 	}

// 	size_t low = 0;
// 	size_t high = bornePos;
// 	size_t mid;
	
// 	if (low == bornePos)
// 		return low;
// 	while (low < high)
// 	{
// 		mid = low + (high - low) / 2;
// 		if (mainChain[mid] > pair.loser)
// 		{
// 			high = mid;
// 		}
// 		else if (mainChain[mid] < pair.loser)
// 			low = mid + 1;
// 		else
// 			return mid;
// 	}
// }