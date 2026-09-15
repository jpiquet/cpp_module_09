/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:29:17 by jpiquet           #+#    #+#             */
/*   Updated: 2026/09/15 16:29:18 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

std::vector<int>	PmergeMe::storeData( int ac, char** av )
{
	std::vector<int>	numbers;
	char* 				endptr;
	long				n;

	for(int i = 1; i < ac; ++i)
	{
		n = std::strtol(av[i], &endptr, 10);
		if (n < 0)
			throw std::invalid_argument("Error: Can't be a negative number");
		if (*endptr != '\0')
			throw std::invalid_argument("Error: Only numbers are allowed");
		if (n > __INT_MAX__ || n < INT_MIN)
			throw std::invalid_argument("Error: Overflow");
		numbers.push_back(n);
	}

	for (size_t i = 0; i < numbers.size(); ++i)
	{
		for (size_t j = i + 1; j < numbers.size(); ++j)
		{
			if (numbers[i] == numbers[j])
				throw std::invalid_argument("Duplicate numbers are not allowed");
		}
	}
	return numbers;
}

void	printNumbers(std::vector<int> const& numbers)
{
	std::vector<int>::const_iterator it;

	for(it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	printTime( long long vector, long long deque, size_t nElements )
{
	std::cout << "Time to process a range of " << nElements << " elements with std::vector = " << vector << " us" << std::endl;
	std::cout << "Time to process a range of " << nElements << " elemets with std::deque =  " << deque << " us" << std::endl;
}

void	PmergeMe::launch( std::vector<int> const& numbers )
{
	timeval		start;
	timeval		end;

	long long	vectorTime;
	long long	dequeTime;

	std::cout << "Before: ";
	printNumbers(numbers);

	gettimeofday(&start, NULL);
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		_vec.push_back(numbers[i]);
	}
	_vec = sortVec(_vec);
	gettimeofday(&end, NULL);

	vectorTime = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);

	gettimeofday(&start, NULL);
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		_deque.push_back(numbers[i]);
	}
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
