/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:04:36 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/11 23:19:20 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		is_valid_arg(char **argv)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		if (!(is_num_str(argv[i])))
			return (FALSE);
		if (i == 0 && argv[0][0] - '0' == 0)
			return (FALSE);
		if (i != 0 && ft_strlen(argv[i]) != 1 && argv[i][0] - '0' == 0)
			return (FALSE);
	}
	return (TRUE);
}

int		dining_start(t_ph_info *ph_info)
{
	pthread_t	tid;
	int			err_num;

	if (ph_info->cond->count_must_eat >= 0)
		if (!create_detached_thread(&tid, monitor_eat_count, ph_info, PH_INFO))
			return (error(CREATE_THREAD) + CREATE_MONITOR_EC_ERRNO);
	if ((err_num = make_even_ph_and_monitor(ph_info)) != TRUE)
		return (err_num);
	if ((err_num = make_odd_ph_and_monitor(ph_info)) != TRUE)
		return (err_num);
	return (TRUE);
}

void	wait_finish_dining(t_ph_info *ph_info)
{
	pthread_mutex_lock(&ph_info->finish_dining_m);
	pthread_mutex_unlock(&ph_info->finish_dining_m);
}

int		main(int argc, char *argv[])
{
	t_ph_info	ph_info;
	int			error_num;

	if (argc < 5 || argc > 6)
		return (error(INVALID_ARG));
	if (!is_valid_arg(&argv[1]))
		return (error(INVALID_ARG));
	if ((error_num = init_ph_info(&ph_info, argc, &argv[1])) != TRUE)
		return (error(INIT) + clean_all(&ph_info, error_num));
	if ((error_num = dining_start(&ph_info)) != TRUE)
		return (error(DINING) + clean_all(&ph_info, error_num));
	wait_finish_dining(&ph_info);
	clean_all(&ph_info, NO_ERROR);
	return (0);
}
