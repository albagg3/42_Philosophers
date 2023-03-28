/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:35 by codespace         #+#    #+#             */
/*   Updated: 2023/03/28 15:11:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

long long gettime()
{
    struct timeval  tv;
    long long milisec;
    gettimeofday(&tv, NULL);
    milisec = tv.tv_sec * 1000 + tv.tv_usec * 1000;
    return milisec;
}