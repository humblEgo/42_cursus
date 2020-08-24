/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:16:12 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:16:12 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad
{
private:
    int count_;
    ISpaceMarine** units_;
public:
    Squad();
    Squad(const Squad& other);
    virtual Squad& operator=(const Squad& other);
    ~Squad();
    int getCount() const;
    ISpaceMarine* getUnit(int idx) const;
    int push(ISpaceMarine *unit);
    void deleteCurrentUnits();
    bool isAlreadyIn(ISpaceMarine *unit) const;
};

#endif