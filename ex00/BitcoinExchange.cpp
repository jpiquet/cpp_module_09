/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:05:56 by jpiquet           #+#    #+#             */
/*   Updated: 2026/04/28 21:13:13 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
// #include <iostream>

BitcoinExchange::BitcoinExchange( void )
{
	//std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src )
{
	(void)src;
	//std::cout << "Copy constructor called" << std::endl;
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rightSide )
{
	(void)rightSide;
	// if (this != &rightSide)
	return *this;
}

BitcoinExchange::~BitcoinExchange( void )
{
	//std::cout << "Default destructor called" << std::endl;
}

void	BitcoinExchange::parseExchangeFile( std::ifstream & exchangeFile )
{
	std::string		buffer;
	std::string		date;
	std::string		strValue;

	float			value;
	unsigned int	pos;

	while (std::getline(exchangeFile, buffer))
	{
		pos = buffer.find(',');
		date = buffer.substr(0, pos);
		strValue = buffer.substr(pos + 1, buffer.size());
		value = std::strtof(strValue.c_str(), NULL);
		// std::cout << "_dataCvs[" << date << "] = " << value << std::endl;
		_dataCsv[date] = value;
	}
}

void	BitcoinExchange::parseInputFile( std::ifstream & inputFile)
{
	std::string		buffer;
	std::string		date;
	std::string		strValue;

	float			value;
	unsigned int	pos;

	while (std::getline(inputFile, buffer))
	{
		pos = buffer.find('|');
		if (pos = buffer.npos)
		{
			
		}
		date = buffer.substr(0, pos - 1);
		strValue = buffer.substr(pos + 2, buffer.size());
		
		
		value = std::strtof(strValue.c_str(), NULL);
		std::cout << "_inputFile[" << date << "] = " << value << std::endl;
		_inputFile[date] = value;
	}
	
	/*
	- Checker si la date respecte bien le bon format.
	- Checker si la valeur est compris entre 0 et 1000.
	*/
}

// std::vector<std::string>	BitcoinExchange::split( std::string & str, char c )
// {
// 	std::vector<std::string>	strvec;
// 	size_t index = 0;
// 	size_t	pos = 0;

// 	while (index < str.size())
// 	{
// 		pos = str.find(c, index);
// 		if (pos == std::string::npos)
// 		{
// 			strvec.push_back(str.substr(index, str.size()));
// 			break;
// 		}
// 		strvec.push_back(str.substr(index, pos - index));
// 		index = pos + 1;
// 	}
// 	return strvec;
// }
