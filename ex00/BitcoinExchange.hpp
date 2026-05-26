/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:05:52 by jpiquet           #+#    #+#             */
/*   Updated: 2026/05/26 15:29:59 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <string>
# include <cmath>
# include <cstdlib>
# include <cfloat>
# include <algorithm>

#define	YEAR_POS 4
#define	MONTH_POS 7
#define	DAY_POS 10

class BitcoinExchange
{
	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const & src );
		BitcoinExchange & operator=( BitcoinExchange const & rightSide );
		~BitcoinExchange( void );

		void	parseExchangeFile( std::ifstream & exchangeFile );
		void	parseInputFile( std::ifstream & inputFile);
		float	getExchangeValue( std::string const& date, float value);
		void	printDataCsv();

	private:
		std::map<std::string, float>	_dataCsv;
};

#endif
