/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:10:30 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/22 16:52:11 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**cmd_list;

	int		i;

	i = 0;

	check_nbargv(argc);
	check_file(argv);
	cmd_list = check_cmd(argv, envp)
	pipex(argv, cmd_list, envp);
	while (cmd_list[i])
	{
		free(cmd_list[i]);
		i++;
	}
	free(cmd_list);
	return (0);
}
