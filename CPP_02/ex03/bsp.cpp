/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:14:03 by moduwole          #+#    #+#             */
/*   Updated: 2023/07/12 03:14:03 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	w1;
	Fixed	w2;

	w1 = (a.getX() * (c.getX() - a.getY()) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY())) /
		((b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()));
		
	w2 = (point.getY() - a.getY() - w1 * (b.getY() - a.getY())) / (c.getY() - a.getY());

	return w1 >= Fixed(0) && w2 >= Fixed(0) && (w1 + w2 ) <= Fixed(1) && (w1 != 0 || w2 != 0)
		&& !((w1 == 1 && w2 == 0) || (w1 == 0 && w2 == 1));
}
