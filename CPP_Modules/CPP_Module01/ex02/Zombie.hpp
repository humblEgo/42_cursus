/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:49:44 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 21:43:02 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <random>

class Zombie
{
private:
    std::string name_;
    std::string type_;
public:
    Zombie();
    Zombie(std::string name, std::string type);
    ~Zombie();
    void    announce(void);
};

#endif