/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:51:24 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/10 15:35:07 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/utils.h"
#include <stdio.h>

void	philo_sleep(t_philo *philo)
{
	print_info(philo, SLEEP);
	ft_usleep(philo->house->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->house->philos[philo->left_fork_indx].fork);
	print_info(philo, FORK);
	pthread_mutex_lock(&philo->house->philos[philo->right_fork_indx].fork);
	print_info(philo, FORK);
	philo->last_eat = gettime();
	philo->times_ate++;
	print_info(philo, EAT);
	ft_usleep(philo->house->time_to_eat);
	pthread_mutex_unlock(&philo->house->philos[philo->left_fork_indx].fork);
	pthread_mutex_unlock(&philo->house->philos[philo->right_fork_indx].fork);
}

void	print_info(t_philo *philo, enum e_action ac)
{
	long long	current_time;
	long long	print_time;

	current_time = gettime();
	pthread_mutex_lock(&philo->house->print_sth);
	print_time = passed_time(current_time, philo->house->start_time);
	if (philo->house->is_alive && !philo->house->is_full)
	{
		if (ac == FORK)
			printf("%s%06lld %sphilo[%d] %shas taken a fork\n", W, print_time, \
				G, philo->num, Y);
		if (ac == EAT)
			printf("%s%06lld %sphilo[%d] %sis eating\n", W, print_time, \
				G, philo->num, O);
		if (ac == THINK)
			printf("%s%06lld %sphilo[%d] %sis thinking\n", W, print_time, \
				G, philo->num, B);
		if (ac == SLEEP)
			printf("%s%06lld %sphilo[%d] %sis sleeping\n", W, print_time, \
				G, philo->num, LP);
		if (ac == DIE)
			printf("%s%06lld %sphilo[%d] %sdied\n", W, print_time, \
				G, philo->num, P);
	}
	pthread_mutex_unlock(&philo->house->print_sth);
}
