/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:03:16 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 16:09:23 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <iomanip>

class Pony
{
private:
    std::string name_;
    int         age_;
    std::string color_;
public:
    Pony(std::string name);
    ~Pony();
    void    show_info(void);
    void    eat(void);
    void    run(void);
    void    sleep(void);
};

#endif