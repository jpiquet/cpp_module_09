#include "PmergeMe.hpp"
#include <iostream>

std::vector<unsigned int> sortVec( std::vector<unsigned int> list);

PmergeMe::PmergeMe( void ) : _vec(), _deque() {}

PmergeMe::PmergeMe( PmergeMe const & src ) 
{
	(void)src;
}

PmergeMe & PmergeMe::operator=( PmergeMe const & rightSide )
{
	(void)rightSide;
	return *this;
}

PmergeMe::~PmergeMe( void ) {}

void	PmergeMe::storeData(int ac, char** av)
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
		_vec.push_back(static_cast<unsigned int>(n));
		_deque.push_back(static_cast<unsigned int>(n));
	}
	// printVec();
}

void	PmergeMe::launch( void )
{
	_vec = sortVec(_vec);
	printVec();
}

// typename <template T>
void	PmergeMe::printVec( void ) const
{
	std::vector<unsigned int>::const_iterator it;

	for(it = _vec.begin(); it != _vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque( void ) const
{
	std::deque<unsigned int>::const_iterator it;

	for(it = _deque.begin(); it != _deque.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::vector<Pair> formPairs( std::vector<unsigned int> list)
{
	std::vector<Pair>	pairs;
	Pair				onePair;
	size_t				i;


	for(i = 0; i < list.size(); i += 2)
	{
		if (list[i] > list[i + 1])
		{
			std::cout << "Winner = " << list[i] << " | Loser = " << list[i + 1] << std::endl;
			onePair.winner = list[i];
			onePair.loser = list[i + 1];
		}
		else
		{
			std::cout << "Winner = " << list[i + 1] << " | Loser = " << list[i] << std::endl;
			onePair.winner = list[i + 1];
			onePair.loser = list[i];
		}
		pairs.push_back(onePair);
	}
	return pairs;
}

std::vector<Pair> reorderPairs( const std::vector<Pair>& pairs, const std::vector<unsigned int>& sortedWinners)
{
	std::vector<Pair> sortedPairs;

	for (size_t i = 0; i < sortedWinners.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (sortedWinners[i] == pairs[j].winner)
			{
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	return sortedPairs;
}

std::vector<size_t> jacobsthalOrder(size_t nPair)
{
	std::vector<size_t> order;

	if (nPair <= 1)
		return order;
	
	size_t previous = 1;
	size_t current = 3;

	while (previous < nPair)
	{
		size_t i = current;
		if (i > nPair)
			i = nPair;
		while (i > previous)
		{
			order.push_back(i);
			i--;
		}

		size_t next = current + 2 * previous;
		previous = current;
		current = next;
	}
	return order;
}

// void	placement()
std::vector<unsigned int> sortVec( std::vector<unsigned int> list)
{
	std::vector<Pair>			pairs;
	std::vector<unsigned int>	winners;
	std::vector<unsigned int>	mainChain;
	unsigned int				straggler;
	bool						hasStraggler = false;

	if (list.size() <= 1)
		return list;

	if ((list.size() % 2) == 1)
	{
		straggler = list.back();
		hasStraggler = true;
		list.pop_back();
	}

	pairs = formPairs(list);
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		winners.push_back(pairs[i].winner);
	}

	mainChain = sortVec(winners);
	pairs = reorderPairs(pairs, mainChain);

	if (!pairs.empty())
		mainChain.insert(mainChain.begin(), pairs[0].loser);

	std::vector<size_t> order = jacobsthalOrder(pairs.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t pairIndex = order[i];
		std::vector<unsigned int>::iterator boundPos;
		std::vector<unsigned int>::iterator insertPos;

		unsigned int loser = pairs[pairIndex - 1].loser;
		unsigned int winner = pairs[pairIndex - 1].winner;

		boundPos = std::find( mainChain.begin(), mainChain.end(), winner);

		insertPos = std::lower_bound(mainChain.begin(), boundPos, loser);

		mainChain.insert(insertPos, loser);
	}

	if (hasStraggler)
	{
	    std::vector<unsigned int>::iterator insertPos;

	    insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
	    mainChain.insert(insertPos, straggler);
	}

	return mainChain;
}


// size_t	binarySearch(std::vector<unsigned int> mainChain, Pair pair)
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