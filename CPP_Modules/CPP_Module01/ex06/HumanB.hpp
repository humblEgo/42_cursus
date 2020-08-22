/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:33:37 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 21:33:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
    const Weapon *weapon_;
    std::string name_;
public:
    HumanB(std::string const name);
    ~HumanB();
    void attack(void) const;
    void setWeapon(const Weapon& weapon);
};

#endif