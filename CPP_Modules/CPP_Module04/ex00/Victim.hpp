/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 00:28:26 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/23 00:28:26 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
private:
    std::string name_;
public:
    Victim(std::string name);
    Victim(const Victim& other);
    Victim& operator=(const Victim& other);
    virtual ~Victim(void);
    std::string introduce(void) const;
    std::string getName(void) const;
    virtual void getPolymorphed(void) const;
};

std::ostream& operator<<(std::ostream& out, Victim& victim);

#endif