/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:32:32 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/22 17:09:46 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	fd_value_exchange(int fd[], int temp_fd[])
{
	temp_fd[1] = fd[0];
	fd[0] = temp_fd[0];
	temp_fd[0] = temp_fd[1];
}

void	pipex(char **argv, char **paths, char **envp)
{
	pid_t		pid1;
	int			fd[2];
	t_cmd_arg	cmdlist;
	int			temp_fd[2];

	temp_fd[0] = -1;
	pid1 = -1;
	cmdlist.cmd_argv = argv;
	cmdlist.n_cmd = 1;
	while (argv[cmdlist.n_cmd + 2])
	{
		if (argv[cmdlist.n_cmd + 3] && pipe(fd) == -1)
			return (perror("pipe"));
		fd_value_exchange(fd, temp_fd);
		pid1 = fork();
		if (pid1 < 0)
			return (perror("Fork1"));
		if (pid1 == 0)
			child_process(cmdlist, cmd_list, fd, envp);
		close(fd[1]);
		cmdlist.n_cmd++;
	}
	close(fd[0]);
	while (cmdlist.n_cmd--)
		waitpid(pid1, NULL, 0);
}
