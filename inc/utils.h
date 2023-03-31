/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:55:17 by albagarc          #+#    #+#             */
/*   Updated: 2023/03/31 12:19:45 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./defines.h"

#ifndef UTILS_H
# define UTILS_H
int         ft_atoi(const char *str);
void        ft_putendl_fd(char *s, int fd);
long long   gettime();
long long   passed_time(long long current_time, long long last_time);
void        print_info(t_philo *philo, enum action ac);
int         create_philos(t_house *house);
#endif
