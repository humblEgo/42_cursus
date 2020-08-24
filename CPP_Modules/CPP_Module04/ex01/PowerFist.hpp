/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:15:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:15:39 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PowerFist_HPP
# define PowerFist_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist(void);
    virtual ~PowerFist(void);
    virtual void attack() const;
};

#endif