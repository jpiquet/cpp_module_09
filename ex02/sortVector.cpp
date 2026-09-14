#include "PmergeMe.hpp"
#include <iostream>

std::vector<Pair> formPairs( std::vector<int> list)
{
	std::vector<Pair>	pairs;
	Pair				onePair;
	size_t				i;

	for(i = 0; i < list.size(); i += 2)
	{
		if (list[i] > list[i + 1])
		{
			onePair.winner = list[i];
			onePair.loser = list[i + 1];
		}
		else
		{
			onePair.winner = list[i + 1];
			onePair.loser = list[i];
		}
		pairs.push_back(onePair);
	}
	return pairs;
}

std::vector<Pair> reorderPairs( const std::vector<Pair>& pairs, const std::vector<int>& sortedWinners)
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

std::vector<int> sortVec( std::vector<int> list)
{
	std::vector<Pair>			pairs;
	std::vector<int>	winners;
	std::vector<int>	mainChain;
	int				straggler;
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
		std::vector<int>::iterator boundPos;
		std::vector<int>::iterator insertPos;

		int loser = pairs[pairIndex - 1].loser;
		int winner = pairs[pairIndex - 1].winner;

		boundPos = std::find(mainChain.begin(), mainChain.end(), winner);
		insertPos = std::lower_bound(mainChain.begin(), boundPos, loser);
		mainChain.insert(insertPos, loser);
	}

	if (hasStraggler)
	{
		std::vector<int>::iterator insertPos;

		insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}

	return mainChain;
}
