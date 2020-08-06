#ifndef MACRO_PH_H
# define MACRO_PH_H


# define TRUE 1
# define FALSE 0

/*
**  Philosopher's state 
*/

# define PICKING_FORK "has taken a fork\n"
# define EATING "is eating\n"
# define SLEEPING "is sleeping\n"
# define THINKING "is thinking\n"
# define DIED "died\n"

/*
**  Error messages
*/

# define INIT "Failed to initialize\n"
# define CREATE_THREAD "Failed to create thread\n"
# define DINING "Error while dining\n"

/*
**  arg_type
*/

# define PH -1
# define PH_INFO -2

#endif