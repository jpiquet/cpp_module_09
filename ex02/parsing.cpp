/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerzone <amerzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 11:27:09 by amerzone          #+#    #+#             */
/*   Updated: 2026/06/21 12:02:10 by amerzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>

std::vector<unsigned int> parsing(int ac, char** av)
{
	char* 						endptr;
	std::vector<unsigned int>	vec;
	long						n;

	for(int i = 1; i < ac - 1; ++i)
	{
		n = std::strtol(av[i], &endptr, 10);
		if (n < 0)
			throw std::invalid_argument("Error: Can't be a negative number");
		if (endptr != NULL)
			throw std::invalid_argument("Error: Only numbers are allowed");
		if (n > __INT_MAX__)
			throw std::invalid_argument("Error: Overflow");
		vec.push_back(static_cast<unsigned int>(n));
	}
	return vec;
}
