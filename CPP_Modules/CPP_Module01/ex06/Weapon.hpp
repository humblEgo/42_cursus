/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:33:45 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 21:33:46 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
    std::string type_;
public:
    Weapon();
    Weapon(std::string type_);
    ~Weapon();
    const std::string &getType(void) const;
    void setType(std::string type);
    void printAddr();
};

#endif