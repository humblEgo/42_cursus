/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 00:28:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/23 00:28:23 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
public:
    Peon(std::string name);
    Peon(const Peon& other);
    Peon& operator=(const Peon& other);
    virtual ~Peon(void);
    std::string getName(void) const;
    virtual void getPolymorphed(void) const;
};

std::ostream& operator<<(std::ostream& out, Peon& peon);

#endif