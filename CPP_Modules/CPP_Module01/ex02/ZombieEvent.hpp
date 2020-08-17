/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:52:24 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 18:26:10 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class ZombieEvent
{
private:
    std::string type_;
public:
    ZombieEvent();
    ~ZombieEvent();
    void    setZombieType(std::string type);
    Zombie* newZombie(std::string name);
    Zombie* randomChump(void);
};

#endif