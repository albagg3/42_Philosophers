/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:29:43 by albagarc          #+#    #+#             */
/*   Updated: 2023/03/31 19:12:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_philo{
	int				num;
	int				left_fork_indx;
	int				right_fork_indx;
	long long		last_eat;
	int				times_ate;
	pthread_mutex_t	fork;
	struct s_house	*house;
}	t_philo;

typedef struct s_house{
	t_philo			*philos;
	int				nphilos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_should_eat;
	long long		start_time;
	int				is_alive;
	pthread_mutex_t print_sth;
}	t_house;

enum action
{
	FORK,
	EAT,
	THINK,
	SLEEP,
	DIE
};


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#endif
