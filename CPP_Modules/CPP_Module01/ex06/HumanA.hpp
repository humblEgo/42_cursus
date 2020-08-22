/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:33:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 21:33:32 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
    Weapon& weapon_;
    std::string name_;
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack(void);
    void printWeaponAddr(void);
};

#endif