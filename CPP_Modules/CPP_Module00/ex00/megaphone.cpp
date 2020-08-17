/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:39:36 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/15 17:17:20 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cwctype>
#include <cstring>

int     trim_left_idx(char *str)
{
    int i;

    i = 0;
    while (str[i] && iswspace(str[i]))
        i++;
    return (i);
}

int     trim_right_idx(char *str)
{
    int i;

    i = strlen(str) - 1 < 0 ? 0 : strlen(str) - 1;
    while (str[i] && iswspace(str[i]))
        i--;
    return (i);
}

int     main(int argc, char *argv[])
{
    int str_start;
    int str_end;

    if (argc == 1)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            for (int j = 0; argv[i][j]; j++)
            {
                str_start = trim_left_idx(argv[i]);
                if (j >= str_start)
                {
                    std::cout<<(char)toupper(argv[i][j]);
                    str_end = trim_right_idx(argv[i]);
                    if (j == str_end)
                        break;
                }
            }
            if (argv[i + 1])
                std::cout<<' ';
        }
        std::cout<<std::endl;
    }
    return (0);
}