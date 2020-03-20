/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:36:25 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/20 23:49:49 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	printf("%c\n", key);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xffffff);
	mlx_key_hook(win_ptr, deal_key, (void *)0); //3rd parameter means that I will not globally use 3rd parameter. 
	mlx_loop(mlx_ptr);

	return (0);
}
