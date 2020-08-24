/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:14:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:14:57 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
private:
    /* data */
public:
    SuperTrap(std::string name);
    SuperTrap(const SuperTrap& copy);
    SuperTrap& operator=(const SuperTrap& assign);
    virtual ~SuperTrap(void);

    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
};

#endif