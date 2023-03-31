/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:29:43 by albagarc          #+#    #+#             */
/*   Updated: 2023/03/31 14:20:47 by albagarc         ###   ########.fr       */
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

#endif
