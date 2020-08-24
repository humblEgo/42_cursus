/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:16:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:16:31 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define SLOT_SIZE 4

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria*   _inventory[SLOT_SIZE];
public:
    Character(std::string name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif