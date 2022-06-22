/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:10:30 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/22 14:12:09 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	paths = path_finder(envp);
	check_nbargv(argc);
	check_file(argv);
	pipex(argv, paths, envp);
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	return (0);
}
