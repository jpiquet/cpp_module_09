/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:05:56 by jpiquet           #+#    #+#             */
/*   Updated: 2026/05/26 18:24:13 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
// #include "tools.hpp"
// #include <iostream>

void	parseDate( std::string date );
void	parseValue( float value );
bool 	isNumber(std::string str);


BitcoinExchange::BitcoinExchange( void ) : _dataCsv() {}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) : _dataCsv(src._dataCsv) {}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rightSide )
{
	if (this != &rightSide)
		_dataCsv = rightSide._dataCsv;
	return *this;
}

BitcoinExchange::~BitcoinExchange( void ) {}

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
		if (pos == buffer.npos)
		{
			throw std::invalid_argument("Wrong format");
		}
		date = buffer.substr(0, pos);
		strValue = buffer.substr(pos + 1, buffer.size());
		try
		{
			parseDate(date);
			value = std::strtof(strValue.c_str(), NULL);
			if (value < 0)
				return ;
			// parseValue(value);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << buffer << '\n';
			return ;
		}
		_dataCsv[date] = value;
	}
}

void	BitcoinExchange::parseInputFile( std::ifstream & inputFile )
{
	std::string		buffer;
	std::string		date;
	std::string		strValue;

	float			value;
	float			exchangeValue;
	unsigned int	pos;
	char			*endptr;

	while (std::getline(inputFile, buffer))
	{
		if (buffer == "date | value")
		{
			std::cout << buffer << std::endl;
			continue ;
		}
		pos = buffer.find('|');
		if (pos == buffer.npos)
		{
			std::cerr << "Wrong format: " << buffer << std::endl;
			continue ;
		}

		date = buffer.substr(0, pos - 1);
		try
		{
			parseDate(date);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << buffer << '\n';
			continue ;
		}

		strValue = buffer.substr(pos + 2, buffer.size());
		value = std::strtof(strValue.c_str(), &endptr);
		if (endptr == strValue.c_str() || *endptr != '\0')
		{
			std::cerr << "Wrong value: " << buffer << std::endl;
			continue;
		}

		try
		{
			parseValue(value);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Wrong value: " << value << '\n';
			continue;
		}

		exchangeValue = getExchangeValue(date, value);
		std::cout << date << " | " << exchangeValue << std::endl;
	}
}

float	BitcoinExchange::getExchangeValue( std::string const& date, float value)
{
	std::map<std::string, float>::iterator it = _dataCsv.lower_bound(date);
	
	
	if (it == _dataCsv.begin())
	{
		return 0;
	}
	if (it == _dataCsv.end() || it->first != date)
	{
		it--;
	}
	return value * it->second;
}


void	parseValue( float value )
{
	if (value > 1000)
		throw std::invalid_argument("Number to large: ");
	if (value < 0)
		throw std::invalid_argument("Can't be a negative number: ");
}

void	parseDate( std::string date )
{
	if (date.size() != 10 || date[YEAR_POS] != '-' || date[MONTH_POS] != '-')
		throw std::invalid_argument("Wrong format: ");
	
	if (!isNumber(date.substr(0, 4).c_str()) || !isNumber(date.substr(5, 2).c_str()) || !isNumber(date.substr(8, 2).c_str()))
		throw std::invalid_argument("Wrong format: ");

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if ( month < 1 || month > 12)
		throw std::invalid_argument("Wrong month format: ");

	if (day > 31 || day < 1)
		throw std::invalid_argument("Wrong day format: ");

	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (day > 29)
				throw std::invalid_argument("Wrong day format: ");
		}
		else
		{
			if (day > 28)
			throw std::invalid_argument("Wrong day format: ");
		}
	}

	if (month >= 1 && month <= 7)
		if (month % 2 == 0 && day > 30)
			throw std::invalid_argument("Wrong day format: ");

	if (month >= 8 && month <= 12)
		if (month % 2 == 1 && day > 30)
			throw std::invalid_argument("Wrong day format: ");
}

bool isNumber(std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if(str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

void	BitcoinExchange::printDataCsv()
{
	for (std::map<std::string, float>::iterator it = _dataCsv.begin(); it != _dataCsv.end(); it++)
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}
}
