/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 01:57:17 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/27 14:34:11 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr<<"Error: bad arguments"<<std::endl;
        return (1);
    }
    Convert converter(argv[1]);
    converter.toCharAndPrint();
    converter.toIntAndPrint();
    converter.toFloatAndPrint();
    return (0);
}