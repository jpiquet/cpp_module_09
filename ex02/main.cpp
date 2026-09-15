/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:29:13 by jpiquet           #+#    #+#             */
/*   Updated: 2026/09/15 16:29:14 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

std::vector<unsigned int> parsing(int ac, char** av);

int main(int ac, char** av)
{
	PmergeMe	sort;
	std::vector<int> numbers;

	if(ac <= 1)
	{
		std::cout << "Need at least one argument" << std::endl;
		return 1;
	}

	try
	{
		numbers = sort.storeData(ac, av);
		sort.launch(numbers);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
