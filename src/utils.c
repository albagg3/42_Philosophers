/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:35 by codespace         #+#    #+#             */
/*   Updated: 2023/03/31 11:44:41 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include "../inc/defines.h"

long long gettime()
{
    struct timeval  tv;
    long long milisec;
    gettimeofday(&tv, NULL);
    milisec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return milisec;
}

long long passed_time(long long current_time, long long last_time)
{
    long long result;
    
    result = current_time - last_time;
    return (result);
}

void    print_info(t_philo *philo, enum action ac)
{
    
    long long current_time;
    long long print_time;

    current_time = gettime();
    pthread_mutex_lock(&philo->house->print_sth);
    print_time = passed_time(current_time, philo->house->start_time);
    if(ac == FORK)
    {
        printf("%lld philo[%d] has taken a fork\n", print_time, philo->num);
    }
    if(ac == EAT)
    {
        printf("%lld philo[%d] is eating\n", print_time, philo->num);
    }
    if(ac == THINK)
    {
        printf("%lld philo[%d] is thinking\n", print_time, philo->num);
    }
    if(ac == SLEEP)
    {
        printf("%lld philo[%d] is sleeping\n", print_time, philo->num);
    }
    if(ac == DIE)
    {
        printf("%lld philo[%d] is dead\n", print_time, philo->num);
    }
	pthread_mutex_unlock(&philo->house->print_sth);
}
