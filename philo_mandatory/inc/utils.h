/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:55:17 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/10 13:29:36 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include"./defines.h"

int			ft_atoi(const char *str);
void		ft_putendl_fd(char *s, int fd);
long long	gettime(void);
long long	passed_time(long long current_time, long long last_time);
void		print_info(t_philo *philo, enum e_action ac);
int			create_philos(t_house *house);
void		ft_usleep(long long time);
void		ft_free_destroy(t_house *house);
void		philo_sleep(t_philo *philo);
void		philo_eat(t_philo *philo);
void		ft_usleep(long long time);

#endif
