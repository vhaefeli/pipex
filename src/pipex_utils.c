/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:32:32 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/28 15:54:26 by vhaefeli         ###   ########.fr       */
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

static void	fd_value_exchange(int fd[], int temp_fd[])
{
	temp_fd[1] = fd[0];
	fd[0] = temp_fd[0];
	temp_fd[0] = temp_fd[1];
}

void	pipex(t_list **list_cmds, char **envp)
{
	pid_t		pid1;
	int			fd[2];
	int			temp_fd[2];
	int			n_cmd;

	n_cmd = 0;
	temp_fd[0] = -1;
	pid1 = -1;
	ft_printf("debut pipex");
	ft_printf("\n cmd dans flag %s\n", (*list_cmds)->cmd_with_flags[0]);
	while (*list_cmds && ++n_cmd)
	{
		if (pipe(fd) == -1 && ft_printf("Pipe %d : ", n_cmd))
			ft_error(*list_cmds, NULL);
		fd_value_exchange(fd, temp_fd);
		ft_printf("avant fork %d", n_cmd);
		ft_printf("\n cmd dans flag %s\n", (*list_cmds)->cmd_with_flags[0]);
		pid1 = fork();
		ft_printf("apres fork %d", n_cmd);
		ft_printf("\n cmd dans flag %s\n", (*list_cmds)->cmd_with_flags[0]);
		if (pid1 < 0 && ft_printf("Fork %d : ", n_cmd))
			ft_error(*list_cmds, NULL);
		if (pid1 == 0)
		{
			ft_printf("dans child %d", n_cmd);
			ft_printf("\n cmd dans flag %s\n", (*list_cmds)->cmd_with_flags[0]);

			child_process(*list_cmds, fd, envp);
		}
		close(fd[1]);
		ft_printf("avant del %d", n_cmd);
		ft_printf("\n cmd dans flag %s\n", (*list_cmds)->cmd_with_flags[0]);
		ft_printf("\n(*list_cmds)->path_cmd: %s\n", (*list_cmds)->path_cmd);
		*list_cmds = lst_delonecmd(*list_cmds);
		ft_printf("apres del %d", n_cmd);
	}
	close(fd[0]);
	while (n_cmd--)
		waitpid(pid1, NULL, 0);
}
