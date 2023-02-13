/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:41:51 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/13 22:00:56 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_NARG "Error: Incorrect number of arguments"
# define ERR_ARG "Error: The arguments should be numbers and greater than 0"

void	terminate(char *s);
void	error_control(char **argv);

#endif
