/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:29:43 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/14 17:18:47 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_philo{
	int	num;
	int	left_fork;
	int	right_fork;
}	t_philo;

typedef struct s_house{
	t_philo *philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nphilos;
	int	forks;
	int	times_should_eat;
}	t_house;

#endif
