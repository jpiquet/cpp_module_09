#include "RPN.hpp"
#include <iostream>

RPN::RPN( void ) : _stack()
{
	//std::cout << "Default constructor called" << std::endl;
}

RPN::RPN( RPN const & src ) : _stack(src._stack) {}

RPN & RPN::operator=( RPN const & rightSide )
{
	if (this != &rightSide)
		_stack = rightSide._stack;
	return *this;
}

RPN::~RPN( void ) {}
