/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:39:28 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/03 18:23:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/utils.h"
#include "../inc/errors.h"
#include "../inc/defines.h"
#include <pthread.h>

//rellenar la structura con el numero de filosofos y 
//decirle a cada filosofo cual es su tenedor, meter el resto de argumentos 
//en las variables de la estructura. 
//crear los threads 1 por filosofo y crear las routinas y las condiciones.	

void	init_house(int argc, char **argv, t_house *house)
{
	int i;

	house->nphilos = ft_atoi(argv[1]);
	house->time_to_die = ft_atoi(argv[2]);
	house->time_to_eat = ft_atoi(argv[3]);
	house->time_to_sleep = ft_atoi(argv[4]);
	house->is_alive = 1;
	if(argc == 6)
		house->times_should_eat = ft_atoi(argv[5]);
	i = 0;
	while(i < house->nphilos)
	{
		// pthread_mutex_init(&house->philos[i].fork, NULL);
		house->philos[i].num = i + 1;
		house->philos[i].left_fork_indx = i;
		if (i == house->nphilos - 1)
			house->philos[i].right_fork_indx = 0;
		else
			house->philos[i].right_fork_indx = i + 1;
		house->philos[i].house = house;
		house->philos[i].times_ate = 0;
		
		i++;
	}
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
// while infinito de comprobacion de si han muerto los filosofos en el momento en el que uno muere cortar todos los hilos
		// is_anyone_dead(&house);
	}
	else
	{
		terminate(ERR_NARG);
	}
}

