/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:04:57 by jpiquet           #+#    #+#             */
/*   Updated: 2026/04/28 19:50:34 by jpiquet          ###   ########.fr       */
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
		std::cout << "Invalid arguments" << std::endl;
	}

	BitcoinExchange	btc;

	std::ifstream	exchangeFile("data.csv");
	if (!exchangeFile.is_open())
	{
		std::cout << "Error: " << "data.csv" << " can't be open or doesn'exist !" << std::endl;
		return 1;
	}
	btc.parseExchangeFile(exchangeFile);

	std::ifstream	inputFile(av[1]);
	if (!exchangeFile.is_open())
	{
		std::cout << "Error: " << av[1] << " can't be open or doesn'exist !" << std::endl;
		return 1;
	}
	btc.parseInputFile(inputFile);
}
