/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_live.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:53:53 by albagarc          #+#    #+#             */
/*   Updated: 2023/03/31 14:54:13 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <pthread.h>
#include <stdio.h>
#include "../inc/utils.h"
#include <unistd.h>
#include <stdlib.h>

void    philo_sleep(t_philo *philo)
{
    print_info(philo,THINK);
    usleep(philo->house->time_to_sleep);
}

void    philo_eat(t_philo *philo)
{
    pthread_mutex_init(&philo->fork, NULL);
    pthread_mutex_lock(&philo->house->philos[philo->left_fork_indx].fork);
    print_info(philo, FORK);
    pthread_mutex_lock(&philo->house->philos[philo->right_fork_indx].fork);
    print_info(philo, FORK);
    print_info(philo, EAT);
    usleep(philo->house->time_to_eat);
    pthread_mutex_unlock(&philo->house->philos[philo->left_fork_indx].fork);
    pthread_mutex_unlock(&philo->house->philos[philo->right_fork_indx].fork);
    pthread_mutex_destroy(&philo->fork);
    philo->times_ate++;
}
void	*start_living(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo*)arg;
	if(philo->num % 2 != 0)
		usleep(1500);
	while(philo->house->is_alive)
    {
        philo_eat(philo);
        philo_sleep(philo);
	
    }
	return(0);
}

int	create_philos(t_house *house)
{
	pthread_t *th;
	int i;

	th = malloc(sizeof(t_philo) * house->nphilos);
	if(!th)
		return(1);
	house->start_time = gettime();
	i = 0;
	pthread_mutex_init(&house->print_sth, NULL);
	while (i < house->nphilos)
	{
		if(pthread_create(&th[i], NULL, start_living, &house->philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < house->nphilos)
	{
		if(pthread_join(th[i], NULL) != 0)
			return (1);
	}
	
	pthread_mutex_destroy(&house->print_sth);
	return(0);
}