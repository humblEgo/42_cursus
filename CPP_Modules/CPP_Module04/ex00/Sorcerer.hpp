/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 00:28:28 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/23 00:28:29 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
private:
    std::string name_;
    std::string title_;
public:
    Sorcerer(std::string name, std::string title);
    Sorcerer(const Sorcerer& other);
    Sorcerer& operator=(const Sorcerer& other);
    virtual ~Sorcerer(void);
    std::string getName(void) const;
    std::string getTitle(void) const;
    std::string introduce(void) const;
    void polymorph(Victim const& victim) const;
    void polymorph(std::string& something) const;
};

std::ostream& operator<<(std::ostream& out, const Sorcerer& other);

#endif