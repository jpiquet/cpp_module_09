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

struct Pair
{
	unsigned int winner;
	unsigned int loser;
};

class PmergeMe
{
    public:
        PmergeMe( void );
		PmergeMe( PmergeMe const & src );
		PmergeMe & operator=( PmergeMe const & rightSide );
        ~PmergeMe( void );

		void	storeData(int ac, char** av);

		void	launch( void );

		void	printVec( void ) const;
		void	printDeque( void ) const;


	private:
		std::vector<unsigned int>	_vec;
		std::deque<unsigned int>	_deque;
};

#endif