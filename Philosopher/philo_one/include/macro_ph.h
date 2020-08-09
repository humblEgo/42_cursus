/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_ph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:18:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/09 16:12:35 by humblego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_PH_H
# define MACRO_PH_H

# define TRUE 1
# define FALSE 0

/*
**  Philosopher's state
*/

# define PICKING_FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED -1
# define MUST_EAT_REACHED -2

/*
**  Error type
*/

# define INIT_ERRNO -1
# define CREATE_MONITOR_EC_ERRNO -2
# define GET_TIME_ERRNO -10000
# define CREATE_MONITOR_PH_ERRNO -10000
# define CREATE_ROUTINE_PH_ERRNO -20000
# define NO_ERROR 0

/*
**  Error messages
*/

# define INVALID_ARG "Error: Invalid arg\n"
# define INIT "Failed to initialize\n"
# define CREATE_THREAD "Failed to create thread\n"
# define GET_TIME "Failed to get current time\n"
# define DINING "Error while dining\n"

/*
**  Arg_type
*/

# define PH 1
# define PH_INFO 2


/*
**  Ensure_unlock_m flag macro (second argument)
*/

# define FORK_M_UNLOCKED 0
# define FORK_M_LOCKED -1
# define MONITOR -2
# define MONITOR_EAT_COUNT -3

#endif
