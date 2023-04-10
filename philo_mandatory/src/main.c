/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:39:28 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/10 19:38:20 by albagarc         ###   ########.fr       */
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
int	init_philos(t_house *house)
{
	int	i;

	i = 0;
	while (i < house->nphilos)
	{
		house->philos[i].num = i + 1;
		house->philos[i].left_fork_indx = i;
		if (i == house->nphilos - 1)
			house->philos[i].right_fork_indx = 0;
		else
			house->philos[i].right_fork_indx = i + 1;
		house->philos[i].house = house;
		house->philos[i].times_ate = 0;
		if (pthread_mutex_init(&house->philos[i].fork, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_house(int argc, char **argv, t_house *house)
{
	house->nphilos = ft_atoi(argv[1]);
	house->time_to_die = ft_atoi(argv[2]);
	house->time_to_eat = ft_atoi(argv[3]);
	house->time_to_sleep = ft_atoi(argv[4]);
	house->is_alive = 1;
	house->is_full = 0;
	if (argc == 6)
		house->times_should_eat = ft_atoi(argv[5]);
	if (init_philos(house) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_house	house;

	if (argc == 5 || argc == 6)
	{
		if (error_control(argv))
			terminate(ERR_ARG);
		house.philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		if (!house.philos)
			terminate(ERR_MEM);
		if (init_house(argc, argv, &house) != 0)
		{
			terminate(ERR_MTX);
			ft_free_destroy(&house);
		}
		if (create_philos(&house) != 0)
		{
			ft_free_destroy(&house);
			terminate(ERR_TH);
		}
		ft_free_destroy(&house);
	}
	else
		terminate(ERR_NARG);
}

	// system("leaks philo");
