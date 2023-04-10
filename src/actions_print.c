/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:51:24 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/10 12:59:19 by albagarc         ###   ########.fr       */
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

void    print_info(t_philo *philo, enum action ac)
{

    long long   current_time;
    long long   print_time;

    current_time = gettime();
    pthread_mutex_lock(&philo->house->print_sth);
    print_time = passed_time(current_time, philo->house->start_time);
    if (philo->house->is_alive && !philo->house->is_full )
    {
        if (ac == FORK)
        {
            printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \x1b[0;33mhas taken a fork\n", print_time, philo->num);
        }
        if (ac == EAT)
        {
            printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \033[0;38;5;208mis eating\n", print_time, philo->num);
        }
        if (ac == THINK)
        {
            printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \033[0;96mis thinking\n", print_time, philo->num);
        }
        if (ac == SLEEP)
        {
            printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \033[0;38;5;225mis sleeping\n", print_time, philo->num);
        }
        if (ac == DIE)
        {
            printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \x1b[35mdied\n", print_time, philo->num);
        }
    }
	pthread_mutex_unlock(&philo->house->print_sth);
}
