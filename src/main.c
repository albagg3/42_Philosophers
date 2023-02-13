/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:39:28 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/13 22:10:51 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
/*#include "../inc/utils.h"*/
#include "../inc/errors.h"
int main(int argc, char **argv)
{
//	struct timeval t;
//	gettimeofday(&t, NULL);
//	printf("seconds : %ld\n", t.tv_sec);
	printf("argc=%d", argc);
	if(argc == 5 || argc == 6)
	{
		error_control(argv);
	}
	else
	{
		terminate(ERR_NARG);
	}
}

