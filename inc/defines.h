/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:29:43 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/17 12:12:34 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_philo{
	int	num;
	int	left_fork;
	int	right_fork;
	long long last_eat;
	int times_eat;
}	t_philo;

typedef struct s_house{
	t_philo *philos;
	int	nphilos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_should_eat;
	pthread_mutex_t food;
	pthread_mutex_t print_sth;
}	t_house;

#endif
