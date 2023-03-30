/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:39:28 by albagarc          #+#    #+#             */
/*   Updated: 2023/03/30 20:28:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/defines.h"
#include <pthread.h>


void	init_house(int argc, char **argv, t_house *house)
{
	int i;

	house->nphilos = ft_atoi(argv[1]);
	house->time_to_die = ft_atoi(argv[2]);
	house->time_to_eat = ft_atoi(argv[3]);
	house->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		house->times_should_eat = ft_atoi(argv[5]);
	i = 0;
	while(i < house->nphilos)
	{
		house->philos[i].num = i + 1;
		house->philos[i].left_fork_indx = i;
		if (i == house->nphilos - 1)
			house->philos[i].right_fork_indx = 0;
		else
			house->philos[i].right_fork_indx = i + 1;
		house->philos[i].house = house;
		i++;
	}
	
	
//rellenar la structura con el numero de filosofos y 
//decirle a cada filosofo cual es su tenedor, meter el resto de argumentos 
//en las variables de la estructura. 
//crear los threads 1 por filosofo y crear las routinas y las condiciones.	
}

void	*start_living(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo*)arg;
	// (void)philo;
	if(philo->num % 2 != 0)
		usleep(1500);
	
	
	// pthread_mutex_lock(&house->print_sth);
	// printf("philo[%d] ha cogido un tenedor\n", philo->num);
	// pthread_mutex_unlock(&house->print_sth);
	print_info(philo, FORK);
	
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

int main(int argc, char **argv)
{

	t_house	house;

	if(argc == 5 || argc == 6)
	{
		error_control(argv);
		house.philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		init_house(argc, argv, &house);
		create_philos(&house);
//		printf("variable  house: nphilos %d\n, time_to_die %d\n, time_to_eat %d\n time_to_sleep %d\n.", house.nphilos, house.time_to_die, house.time_to_eat, house.time_to_sleep);
//		printf(" philo 3:\nnumber=%d\nfork_left_%d\nfork_right_%d\n", house.philos[3].num, house.philos[3].left_fork, house.philos[3].right_fork);
	}
	else
	{
		terminate(ERR_NARG);
	}
}

