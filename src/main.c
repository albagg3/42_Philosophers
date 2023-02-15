/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:39:28 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/15 12:55:04 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/defines.h"
#include <pthread.h>


//int mails;
void	init_house(int argc, char **argv, t_house *house)
{
	int i;
	int n;

	house->nphilos = ft_atoi(argv[1]);
	house->time_to_die = ft_atoi(argv[2]);
	house->time_to_eat = ft_atoi(argv[3]);
	house->time_to_sleep = ft_atoi(argv[4]);
	house->forks = ft_atoi(argv[1]);
	if(argc == 6)
		house->times_should_eat = ft_atoi(argv[5]);
	i = 0;
	n = 1;
	while(i < house->forks)
	{
		house->philos[i].num = n;
		house->philos[i].left_fork = n;
		if (i == house->forks - 1)
			house->philos[i].right_fork = 1;
		else
			house->philos[i].right_fork = n + 1;
		i++;
		n++;
	}

//rellenar la structura con el numero de filosofos y 
//decirle a cada filosofo cual es su tenedor, meter el resto de argumentos 
//en las variables de la estructura. 
//crear los threads 1 por filosofo y crear las routinas y las condiciones.	
}

void	*routine_pick_forks(void *arg)
{
	t_house *house = (t_house*)arg;
	int i;
	i = 0;
//	while(i<1000000)
//	{

//	mails++;
	printf("philo[%d] ha cogido un tenedor\n", house->philos->num);
//	i++;
//	}
	return(0);
}
	
/*void	*routine_eat()
{
	printf("philo[] is eating");
	return(0);
}

void	*routine_sleep()
{
	printf("philo[] is eating");
	return(0);
}

void	*routine_think()
{
	printf("philo[] is thinking");
	return(0);
}*/

int	create_threads(t_house *house)
{
	pthread_t th[house->nphilos];
	int i;

	pthread_mutex_init(&house->mutex, NULL);
	i = 0;
	while (i < house->nphilos)
	{
		if(pthread_create(&th[i], NULL, &routine_pick_forks, house) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < house->nphilos)
	{
		if(pthread_join(th[i], NULL) != 0)
			return (1);
	}
	pthread_mutex_destroy(&house->mutex);
	return(0);
}

int main(int argc, char **argv)
{
//	struct timeval t;
//	gettimeofday(&t, NULL);
//	printf("seconds : %ld\n", t.tv_sec);
	t_house	house;

//	printf("argc=%d", argc);
	if(argc == 5 || argc == 6)
	{
		error_control(argv);
		house.philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		init_house(argc, argv, &house);
		create_threads(&house);
//		printf("mails:%d\n", mails);
//		printf("variable  house: nphilos %d\n, time_to_die %d\n, time_to_eat %d\n time_to_sleep %d\n.", house.nphilos, house.time_to_die, house.time_to_eat, house.time_to_sleep);
//		printf(" philo 3:\nnumber=%d\nfork_left_%d\nfork_right_%d\n", house.philos[3].num, house.philos[3].left_fork, house.philos[3].right_fork);
	}
	else
	{
		terminate(ERR_NARG);
	}
}

