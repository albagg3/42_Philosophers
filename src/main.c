/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:39:28 by albagarc          #+#    #+#             */
/*   Updated: 2023/03/28 13:45:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/defines.h"
#include <pthread.h>


void	init_house(int argc, char **argv, t_house *house)
{
	int i;
	int n;

	house->nphilos = ft_atoi(argv[1]);
	house->time_to_die = ft_atoi(argv[2]);
	house->time_to_eat = ft_atoi(argv[3]);
	house->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		house->times_should_eat = ft_atoi(argv[5]);
	i = 0;
	n = 1;
	while(i < house->nphilos)
	{
		house->philos[i].num = n;
		house->philos[i].left_fork = n;
		if (i == house->nphilos - 1)
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

void	*start_living(void *arg)
{
	int i = *(int*)arg;
	
	printf("philo[%d] ha cogido un tenedor\n", i + 1);
	return(0);
}

int	create_threads(t_house *house)
{
	pthread_t *th;
	int i;

	th = malloc(sizeof(t_philo) * house->nphilos);
	if(!th)
		return(1);
	// pthread_mutex_init(&house->mutex, NULL);
	i = 1;
	while (i <= house->nphilos)
	{
		if(pthread_create(&th[i], NULL, &start_living, &house->philos[i]) != 0)
			return (1);
		i++;
	}
	i = 1;
	while (i <= house->nphilos)
	{
		if(pthread_join(th[i], NULL) != 0)
			return (1);
	}
	// pthread_mutex_destroy(&house->mutex);
	return(0);
}

int main(int argc, char **argv)
{
//	struct timeval t;
//	gettimeofday(&t, NULL);
//	printf("seconds : %ld\n", t.tv_sec);
	t_house	house;

	if(argc == 5 || argc == 6)
	{
		error_control(argv);
		house.philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		init_house(argc, argv, &house);
		create_threads(&house);
//		printf("variable  house: nphilos %d\n, time_to_die %d\n, time_to_eat %d\n time_to_sleep %d\n.", house.nphilos, house.time_to_die, house.time_to_eat, house.time_to_sleep);
//		printf(" philo 3:\nnumber=%d\nfork_left_%d\nfork_right_%d\n", house.philos[3].num, house.philos[3].left_fork, house.philos[3].right_fork);
	}
	else
	{
		terminate(ERR_NARG);
	}
}

