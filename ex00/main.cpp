/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:04:57 by jpiquet           #+#    #+#             */
/*   Updated: 2026/09/15 16:53:17 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		if (ac < 2)
			std::cerr << "Missing input file" << std::endl;
		else
			std::cerr << "Too many arguments" << std::endl;
		return 1;
	}

	BitcoinExchange	btc;

	std::ifstream	exchangeFile("data.csv");
	if (!exchangeFile.is_open())
	{
		std::cout << "Error: " << "data.csv" << " can't be open or doesn'exist !" << std::endl;
		return 1;
	}
	try
	{
		btc.parseExchangeFile(exchangeFile);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	
	std::ifstream	inputFile(av[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Error: " << av[1] << " can't be open or doesn'exist !" << std::endl;
		return 1;
	}
	btc.parseInputFile(inputFile);
	return 0;
}
