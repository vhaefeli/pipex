/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:10:30 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/19 22:11:06 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	paths = find_paths(envp);
	check_nbargv(argc);
	check_files(argv);
	pipex(argv, paths, envp);
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	return (0);
}
