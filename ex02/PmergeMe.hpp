#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

std::vector<int> sortVec( std::vector<int> list);
std::deque<int> sortDeque( std::deque<int> list);

struct Pair
{
	int winner;
	int loser;
};

class PmergeMe
{
    public:
        PmergeMe( void );
		PmergeMe( PmergeMe const & src );
		PmergeMe & operator=( PmergeMe const & rightSide );
        ~PmergeMe( void );

		void	storeVector(int ac, char** av);
		void	storeDeque(int ac, char** av);

		void	launch( int ac, char** av );

		void	printVec( void ) const;
		void	printDeque( void ) const;


	private:
		std::vector<int>	_vec;
		std::deque<int>		_deque;
};

#endif