/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:41:51 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/05 16:43:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_NARG "Error: Incorrect number of arguments"
# define ERR_ARG "Error: The arguments should be numbers and greater than 0"
# define ERR_INT "Error: The arguments should be int"
# define ERR_MEM "Error: There was an error allocating the memory"
void	terminate(char *s);
int     error_control(char **argv);

#endif
