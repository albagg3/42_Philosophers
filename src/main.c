/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:39:28 by albagarc          #+#    #+#             */
/*   Updated: 2023/03/31 18:32:10 by codespace        ###   ########.fr       */
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

void	is_anyone_dead(t_house *house)
{
	long long current;
	int i;

	i = 0;
	while(1)
	{
		while( i < house->nphilos)
		{
			current = gettime();
			if(passed_time(current, house->philos[i].last_eat) > passed_time(current, house->time_to_die))
			{
				house->is_alive = 0;
				break;
			}
			i++;
		}
		if(!house->is_alive)
			break;
	}
}

void	already_finish_eating(t_house *house)
{
	int i;

	i = 0;
	while (i < house->nphilos)
	{
		if (house->times_should_eat == house->philos[i].times_ate)
		{
			i++;
			if (i == house->nphilos - 1)
				break;
		}
		else
			i = 0;
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
		is_anyone_dead(&house);
		if(argc == 6)
			already_finish_eating(&house);
	}
	else
	{
		terminate(ERR_NARG);
	}
}

