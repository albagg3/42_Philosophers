/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:29:43 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/10 17:45:23 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>

typedef struct s_philo{
	int				num;
	long long		last_eat;
	int				times_ate;
	struct s_house	*house;
}	t_philo;

typedef struct s_house{
	t_philo			*philos;
	int				nphilos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_should_eat;
	long long		start_time;
	int				is_alive;
	int				is_full;
}	t_house;

enum e_action
{
	FORK,
	EAT,
	THINK,
	SLEEP,
	DIE
};

# define  W "\033[1;39m"
# define  G "\033[1;30m"
# define  Y "\x1b[0;33m"
# define  O "\033[0;38;5;208m"
# define  LP "\033[0;38;5;225m"
# define  B "\033[0;96m"
# define  P "\x1b[0;35m"

#endif
