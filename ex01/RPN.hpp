/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:32:44 by jpiquet           #+#    #+#             */
/*   Updated: 2026/09/16 15:47:35 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <climits>
#include <stdexcept>
#include <exception>

class RPN
{
    public:
        RPN( void );
		RPN( RPN const & src );
		RPN & operator=( RPN const & rightSide );
        ~RPN( void );

		void	calculationInput( std::string const& arg );
		void	printRes( void ) const;

	private:
		std::stack<int>	_stack;
		int				_res;
		bool			_hasOp;
};

#endif
