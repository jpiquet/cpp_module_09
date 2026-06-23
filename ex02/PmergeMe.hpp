#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <cstdlib>

class PmergeMe
{
    public:
        PmergeMe( void );
		PmergeMe( PmergeMe const & src );
		PmergeMe & operator=( PmergeMe const & rightSide );
        ~PmergeMe( void );

		void	storeData(int ac, char** av);
		void	sortList();

	private:
		std::vector<unsigned int>	_vec;
		std::deque<unsigned int>	_deque;
};

#endif