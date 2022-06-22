/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:32:32 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/22 14:03:43 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char **paths, char *first_cmd, char **envp, char **flags)
{
	int		i;
	char	*cmd;

	i = 0;
	while (paths[i])
	{
		cmd = ft_strjoin(paths[i], first_cmd);
		execve(cmd, flags, envp);
		free(cmd);
		i++;
	}
	free(first_cmd);
}

char	**split_flags(char *cmds)
{
	char	**flags;

	if (ft_strnstr(cmds, "awk", 3) == NULL)
		flags = ft_split(cmds, ' ');
	else
	{
		flags = ft_split(cmds, '\'');
		flags[0][3] = '\0';
	}
	return (flags);
}

void	pipex(char **argv, char **paths, char **envp)
{
	pid_t			pid1;
	int				fd[2];
	t_cmd_arg		cmdlist;
	int				temp_fd1;
	int				temp_fd2;

	temp_fd1 = -1;
	pid1 = -1;
	cmdlist.cmd_argv = argv;
	cmdlist.n_cmd = 1;
	// if (pipe(fd) == -1)
	// 	return (perror("pipe"));
	while (argv[cmdlist.n_cmd + 2])
	{
		// if (pid1 != -1 && pid1 != 0)
		// {
		// 	//close(fd[0]);s
		// 	temp_fd = dup(fd[1]);
		// 	close(fd[1]);
		// 	waitpid(pid1, NULL, 0);
		// 	dup2(temp_fd, fd[1]);
		// }
		//printf("Fork !\n");
		if (argv[cmdlist.n_cmd + 3] && pipe(fd) == -1)
			return (perror("pipe"));
		temp_fd2 = fd[0];
		fd[0] = temp_fd1;
		temp_fd1 = temp_fd2;
		pid1 = fork();
		if (pid1 < 0)
			return (perror("Fork1"));
		if (pid1 == 0)
		{
			child_process(cmdlist, paths, fd, envp);
		}
		close(fd[1]);
		cmdlist.n_cmd++;
		//waitpid(pid1, NULL, 0);
		//ft_printf("check1 ");
	}
		close(fd[0]);
		close(fd[1]);
		while (cmdlist.n_cmd--)
			waitpid(pid1, NULL, 0);
}
