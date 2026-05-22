/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:05:56 by jpiquet           #+#    #+#             */
/*   Updated: 2026/05/22 13:55:39 by jpiquet          ###   ########.fr       */
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

/*
	- Parse le fichier data et le stock dans la map.
	- Avec pour key la date et pour valeur la valeur de multiplication.
*/
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

/*
	-Parser le fichier d'input et checker a chaque ligne si il y a pas une erreur:
		-Si le format est pas bon.
		-Si la value est pas au dessus de 1000.
		-Si la value est pas negative.
		-Si la date existe.
	-Si la date existe checker dans le fichier d'input sa valeur la plus proche en regardant celle d'avant.
*/
void	BitcoinExchange::parseInputFile( std::ifstream & inputFile)
{
	std::string		buffer;
	std::string		date;
	std::string		strValue;

	float			value;
	unsigned int	pos;
	char			*endptr;

	while (std::getline(inputFile, buffer))
	{
		pos = buffer.find('|');
		if (pos == buffer.npos)
		{
			std::cerr << "Wrong format: " << buffer << std::endl;
		}
		date = buffer.substr(0, pos - 1);
		if (parseDate(date) == -1)
		{
			return ;
		}
		strValue = buffer.substr(pos + 2, buffer.size());
		

		value = std::strtof(strValue.c_str(), &endptr);
		if (value > 1000)
		{
			std::cerr << "Number too large" << std::endl;
		}
		if (value < 0)
		{
			std::cerr << "Can't be a negative number" << std::endl;
		}
		if (endptr[0] != '\0')
		{
			std::cerr << "Wrong format: " << buffer << std::endl;
		}
		
	}

	/*
	- Checker si la date respecte bien le bon format.
	- Checker si la valeur est compris entre 0 et 1000.
	*/
}

/*
	Checker que la size() == 10
	Checker que les nombres de mois depasse pas 12 et que les jours depassé pas 30 ou 31.
*/
int	parseDate( std::string date )
{
	if (date.size() != 10)
	{
		std::cerr << "Wrong format" << std::endl;
	}
	for ()
	{
		
	}
	size_t pos = date.find('-');
	if (pos != 4)
	{
		std::cerr << "Wrong format" << std::endl;
	}
	pos = date.find('-');
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
