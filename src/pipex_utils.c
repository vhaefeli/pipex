/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:32:32 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/21 14:46:16 by vhaefeli         ###   ########.fr       */
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
	int				status;

	cmdlist.cmd_argv = argv;
	cmdlist.n_cmd = 1;
	if (pipe(fd) == -1)
		return ;
	while (argv[cmdlist.n_cmd + 3])
	{
		pid1 = fork();
		if (pid1 < 0)
			return (perror("Fork1: "));
		if (pid1 == 0)
		{
			child_process(cmdlist, paths, fd, envp);
		}
		waitpid(pid1, &status, 0);
		cmdlist.n_cmd++;
	}
	close(fd[0]);
	close(fd[1]);
}
