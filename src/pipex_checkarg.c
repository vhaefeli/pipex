/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checkarg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:07:23 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/21 13:50:57 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_nbargv(int argc)
{
    if (argc < 5)
	{
		ft_printf("(Error) Too few arguments\n");
		exit(EXIT_FAILURE);
	}
}

void	check_files(int argc, char **argv)
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
	if (access(argv[argc - 1], F_OK) != 0)
		open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (access(argv[argc - 1], W_OK) != 0)
	{
		ft_printf("(Error) %s : %s \n", strerror(errno), argv[argc -1]);
		exit(EXIT_FAILURE);
	}
}
