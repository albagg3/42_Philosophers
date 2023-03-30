/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:55:17 by albagarc          #+#    #+#             */
/*   Updated: 2023/03/30 20:27:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./defines.h"

#ifndef UTILS_H
# define UTILS_H
int	ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
long long   gettime();
void    print_info(t_philo *philo, enum action ac);
#endif
