/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checkarg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:07:23 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/22 13:32:44 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_nbargv(int argc)
{
	if (argc < 5)
	{
		ft_printf("(Error) Too few arguments\n");
		exit(EXIT_FAILURE);
	}
}

void	check_file(char **argv)
{
	if (access(argv[1], F_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}
}
