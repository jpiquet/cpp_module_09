/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:22:55 by jpiquet           #+#    #+#             */
/*   Updated: 2026/06/02 12:08:53 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "RPN.hpp"

int main(int ac, char **av)
{
	std::ifstream	infile("test.txt");
	std::string		buff;

	(void)av;
	if (ac != 2)
	{
		if (ac < 2)
			std::cerr << "Missing input" << std::endl;
		else
			std::cerr << "Too many arguments" << std::endl;
		return 1;
	}

	RPN n;
	try
	{
		while(std::getline(infile, buff, '\n'))
		{
			n.calculationInput(buff);
			n.printRes();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
