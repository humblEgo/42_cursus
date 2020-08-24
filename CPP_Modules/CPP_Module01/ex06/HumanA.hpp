/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:33:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 09:47:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
    std::string name_;
    Weapon& weapon_;
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack(void);
    void printWeaponAddr(void);
};

#endif
