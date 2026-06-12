#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
    public:
        PmergeMe( void );
		PmergeMe( PmergeMe const & src );
		PmergeMe & operator=( PmergeMe const & rightSide );
        ~PmergeMe( void );

	private:
};

#endif