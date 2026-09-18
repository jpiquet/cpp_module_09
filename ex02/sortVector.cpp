/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocelyn <jocelyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:29:27 by jpiquet           #+#    #+#             */
/*   Updated: 2026/09/18 14:41:04 by jocelyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

std::vector<int>	pushWinLose(std::vector<int> winner, std::vector<int> loser)
{
	std::vector<int>	res;

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

std::vector<std::vector<int> > formPairs( std::vector<std::vector<int> > list)
{
	std::vector<std::vector<int> > pairs;
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

void printPairs(std::vector<std::vector<int> > pairs)
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

std::vector<int>	pushLoser(std::vector<int> all)
{
	std::vector<int>	res;
	size_t				i = all.size() / 2;

	while (i < all.size())
	{
		res.push_back(all[i]);
		++i;
	}
	return res;
}

std::vector<int>	pushWin(std::vector<int> all)
{
	std::vector<int>	res;
	size_t				i = 0;

	while (i < (all.size() / 2))
	{
		res.push_back(all[i]);
		++i;
	}
	return res;
}

std::vector<std::vector<int> > sortVec( std::vector<std::vector<int> > list)
{
	std::vector<std::vector<int> >	pairs;
	std::vector<std::vector<int> >	mainChain;
	std::vector<int>				straggler;
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
	pairs = sortVec(pairs);

	if (!pairs.empty())
	{
		for (size_t i = 0; i < pairs.size(); ++i)
		{
			mainChain.push_back(pushWin(pairs[i]));
		}
		mainChain.insert(mainChain.begin(), pushLoser(pairs[0]));
	}

	std::vector<size_t> order = jacobsthalOrder(pairs.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t pairIndex = order[i];
		std::vector<std::vector<int> >::iterator boundPos;
		std::vector<std::vector<int> >::iterator insertPos;

		std::vector<int> loser = pushLoser(pairs[pairIndex - 1]);
		std::vector<int> winner = pushWin(pairs[pairIndex - 1]);

		boundPos = std::find(mainChain.begin(), mainChain.end(), winner);
		insertPos = std::lower_bound(mainChain.begin(), boundPos, loser);
		mainChain.insert(insertPos, loser);
	}


	if (hasStraggler)
	{
		std::vector<std::vector<int> >::iterator	insertPos;

		insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}
	return mainChain;
}
