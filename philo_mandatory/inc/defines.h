/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:29:43 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/10 15:36:53 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>

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
	int				is_full;
	pthread_mutex_t	print_sth;
	pthread_mutex_t	block_is_alive;
}	t_house;

enum e_action
{
	FORK,
	EAT,
	THINK,
	SLEEP,
	DIE
};

# define  W "\033[1;39m"
# define  G "\033[1;30m"
# define  Y "\x1b[0;33m"
# define  O "\033[0;38;5;208m"
# define  LP "\033[0;38;5;225m"
# define  B "\033[0;96m"
# define  P "\x1b[0;35m"

#endif
