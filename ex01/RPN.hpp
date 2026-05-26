#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN
{
    public:
        RPN( void );
		RPN( RPN const & src );
		RPN & operator=( RPN const & rightSide );
        ~RPN( void );
	
	private:
		std::stack<int>	_stack;
};

#endif
