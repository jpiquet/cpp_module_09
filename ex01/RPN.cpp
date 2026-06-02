/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:32:34 by jpiquet           #+#    #+#             */
/*   Updated: 2026/06/02 12:08:43 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

bool	isDigit(char c);
bool	isOp(char c);
int		doTheMath(int n1, int n2, char op);

RPN::RPN( void ) : _stack(), _res(0), _hasOp(false) {}

RPN::RPN( RPN const & src ) : _stack(src._stack), _res(src._res), _hasOp(src._hasOp) {}

RPN & RPN::operator=( RPN const & rightSide )
{
	if (this != &rightSide)
	{
		_stack = rightSide._stack;
		_res = rightSide._res;
		_hasOp = rightSide._hasOp;
	}
	return *this;
}

void	RPN::calculationInput( std::string const& arg)
{
	for (size_t i = 0; i < arg.size(); ++i)
	{
		if (isDigit(arg[i]))
		{
			_stack.push(arg[i] - '0');
		}
		else if (isOp(arg[i]) && _stack.size() >= 2)
		{
			_hasOp = true;

			int n1 = _stack.top();
			_stack.pop();

			int n2 = _stack.top();
			_stack.pop();

			_res = doTheMath(n1, n2, arg[i]);
			_stack.push(_res);
		}
		else if (arg[i] == ' ')
			continue;
		else
			throw std::invalid_argument("Bad input");
	}
}

void	RPN::printRes() const
{
	if (_stack.size() < 1 || _hasOp == false)
		throw std::invalid_argument("Bad input");
	std::cout << _res << std::endl;
}

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

int	doTheMath(int n1, int n2, char op)
{
	// std::cout << "n1 = " << n1 << " n2 = " << n2 << " operator = " << op << std::endl;
	long res = 0;
	if (op == '*')
	{
		res = static_cast<long>(n2) * static_cast<long>(n1);
	}
	else if (op == '/')
	{
		if (n1 == 0)
			throw std::invalid_argument("Cannot divide by 0");
		res = static_cast<long>(n2) / static_cast<long>(n1);
	}
	else if (op == '+')
	{
		res = static_cast<long>(n2) + static_cast<long>(n1);
	}
	else if (op == '-')
	{
		res = static_cast<long>(n2) - static_cast<long>(n1);
	}
	if (res > INT_MAX || res < INT_MIN)
	{
		throw std::overflow_error("Error overflow");
	}
	return res;
}

RPN::~RPN( void ) {}
