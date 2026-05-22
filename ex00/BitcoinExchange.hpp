/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:05:52 by jpiquet           #+#    #+#             */
/*   Updated: 2026/05/21 14:25:51 by jpiquet          ###   ########.fr       */
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

class BitcoinExchange
{
	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const & src );
		BitcoinExchange & operator=( BitcoinExchange const & rightSide );
		~BitcoinExchange( void );

		void	parseExchangeFile( std::ifstream & exchangeFile );
		void	parseInputFile( std::ifstream & inputFile);
		// std::vector<std::string>	split( std::string & str, char c );

	private:
		std::map<std::string, float>	_dataCsv;
		std::map<std::string, float>	_inputFile;
};

#endif
