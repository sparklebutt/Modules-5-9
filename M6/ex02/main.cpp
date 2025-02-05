/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:38:23 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/22 19:56:12 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "generate.hpp"
int main()
{
	Base* looky = generate();

	identify(looky);
	identify(*looky);
	return 1;
}