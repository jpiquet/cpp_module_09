/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:29:21 by jpiquet           #+#    #+#             */
/*   Updated: 2026/09/16 16:07:16 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <sys/time.h>

std::vector<int>	sortVec( std::vector<int> list);
std::deque<int>		sortDeque( std::deque<int> list);
void				printNumbers(std::vector<int> const& numbers);

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

		std::vector<int>	storeData( int ac, char **av );

		void	launch( std::vector<int> const& numbers );

		void	printVec( void ) const;
		void	printDeque( void ) const;


	private:
		std::vector<int>	_vec;
		std::deque<int>		_deque;
};

#endif