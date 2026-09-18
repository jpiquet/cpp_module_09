/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocelyn <jocelyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 14:33:36 by jocelyn           #+#    #+#             */
/*   Updated: 2026/09/18 14:40:52 by jocelyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

std::deque<int>	pushWinLose(std::deque<int> winner, std::deque<int> loser)
{
	std::deque<int>	res;

	for(size_t i = 0; i < winner.size(); ++i)
	{
		res.push_back(winner[i]);
	}
	for(size_t i = 0; i < loser.size(); ++i)
	{
		res.push_back(loser[i]);
	}
	return res;
}

std::deque<std::deque<int> > formPairs( std::deque<std::deque<int> > list)
{
	std::deque<std::deque<int> > pairs;
	size_t				i;

	for(i = 0; i < list.size(); i += 2)
	{
		if (list[i][0] > list[i + 1][0])
		{
			pairs.push_back(pushWinLose(list[i], list[i + 1]));
		}
		else
		{
			pairs.push_back(pushWinLose(list[i + 1], list[i]));
		}
	}
	return pairs;
}

std::deque<size_t> jacobsthalOrderDeque(size_t nPair)
{
	std::deque<size_t> order;

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

void printPairs(std::deque<std::deque<int> > pairs)
{
	for(size_t i = 0; i < pairs.size(); ++i)
	{
		std::cout << "[ ";
		for (size_t j = 0; j < pairs[i].size(); ++j)
		{
			std::cout <<  pairs[i][j] << ", ";
		}
		std::cout << "], ";
	}
	std::cout << "\n";
}

std::deque<int>	pushLoser(std::deque<int> all)
{
	std::deque<int>	res;
	size_t				i = all.size() / 2;

	while (i < all.size())
	{
		res.push_back(all[i]);
		++i;
	}
	return res;
}

std::deque<int>	pushWin(std::deque<int> all)
{
	std::deque<int>	res;
	size_t				i = 0;

	while (i < (all.size() / 2))
	{
		res.push_back(all[i]);
		++i;
	}
	return res;
}

std::deque<std::deque<int> > sortDeque( std::deque<std::deque<int> > list)
{
	std::deque<std::deque<int> >	pairs;
	std::deque<std::deque<int> >	mainChain;
	std::deque<int>					straggler;
	bool							hasStraggler = false;

	if (list.size() <= 1)
		return list;

	if ((list.size() % 2) == 1)
	{
		straggler = list.back();
		hasStraggler = true;
		list.pop_back();
	}

	pairs = formPairs(list);
	pairs = sortDeque(pairs);

	if (!pairs.empty())
	{
		for (size_t i = 0; i < pairs.size(); ++i)
		{
			mainChain.push_back(pushWin(pairs[i]));
		}
		mainChain.insert(mainChain.begin(), pushLoser(pairs[0]));
	}

	std::deque<size_t> order = jacobsthalOrderDeque(pairs.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t pairIndex = order[i];
		std::deque<std::deque<int> >::iterator boundPos;
		std::deque<std::deque<int> >::iterator insertPos;

		std::deque<int> loser = pushLoser(pairs[pairIndex - 1]);
		std::deque<int> winner = pushWin(pairs[pairIndex - 1]);
		
		boundPos = std::find(mainChain.begin(), mainChain.end(), winner);
		insertPos = std::lower_bound(mainChain.begin(), boundPos, loser);
		mainChain.insert(insertPos, loser);
	}


	if (hasStraggler)
	{
		std::deque<std::deque<int> >::iterator	insertPos;

		insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}
	return mainChain;
}

