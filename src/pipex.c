/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:10:30 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/21 13:28:19 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char		**paths;
	int			i;

	i = 0;
	paths = path_finder(envp);
	check_nbargv(argc);
	check_files(argc, argv);
	pipex(argv, paths, envp);
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	return (0);
}
