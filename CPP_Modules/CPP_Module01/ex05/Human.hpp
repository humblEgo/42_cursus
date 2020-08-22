/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:35:58 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 18:47:24 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
private:
    Brain   brain;
public:
    Human(/* args*/);
    ~Human();
    std::string identify(void);
    const Brain &getBrain(void) const;
};

#endif