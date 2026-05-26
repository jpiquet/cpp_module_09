/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:22:55 by jpiquet           #+#    #+#             */
/*   Updated: 2026/05/26 18:17:54 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

bool	isDigit(char c)
{
	if (c > '9' || c < '0')
		return false;
	return true;
}

bool	isOp(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return true;
	return false;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac < 2)
			std::cerr << "Missing input" << std::endl;
		else
			std::cerr << "Too many arguments" << std::endl;
		return 1;
	}

	std::stack<int>	stack;

	std::string	arg(av[1]);
	for (size_t i = 0; i < arg.size(); ++i)
	{
		if (isDigit(arg[i]))
		{
			stack.push(arg[i] - '0');
		}
		else if (isOp(arg[i]) || stack.size() >= 2)
		{
			int n1 = stack.top();
			stack.pop();
			int n2 = stack.top();
		}
		else
			std::cerr << "Error" << std::endl;
	}
}
