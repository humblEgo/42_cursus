/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_ph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:18:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/06 16:18:58 by iwoo             ###   ########.fr       */
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
**  Error messages
*/

# define INIT "Failed to initialize\n"
# define CREATE_THREAD "Failed to create thread\n"
# define GET_TIME "Failed to get current time\n"
# define DINING "Error while dining\n"

/*
**  arg_type
*/

# define PH 1
# define PH_INFO 2

#endif
