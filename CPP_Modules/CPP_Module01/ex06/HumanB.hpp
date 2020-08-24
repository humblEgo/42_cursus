/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:33:37 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 09:47:47 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
    std::string name_;
    const Weapon *weapon_;
public:
    HumanB(std::string const name);
    ~HumanB();
    void attack(void) const;
    void setWeapon(const Weapon& weapon);
};

#endif
