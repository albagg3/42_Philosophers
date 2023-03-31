/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:35 by codespace         #+#    #+#             */
/*   Updated: 2023/03/31 19:57:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include "../inc/defines.h"
#include <unistd.h>

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
        printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \x1b[0;33mhas taken a fork\n", print_time, philo->num);
    }
    if(ac == EAT)
    {
        printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \033[0;38;5;208mis eating\n", print_time, philo->num);
    }
    if(ac == THINK)
    {
        printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \033[0;96mis thinking\n", print_time, philo->num);
    }
    if(ac == SLEEP)
    {
        printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \033[0;38;5;225mis sleeping\n", print_time, philo->num);
    }
    if(ac == DIE)
    {
        printf("\033[1;39m%06lld\033[0;39m \033[1;30mphilo[%d] \x1b[35mdied\n", print_time, philo->num);

    }
	pthread_mutex_unlock(&philo->house->print_sth);
}
