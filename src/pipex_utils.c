/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:32:32 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/20 22:58:03 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		return ;
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork1: "));
	if (pid1 == 0)
	{
		first_child_process(argv, paths, fd, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork2: "));
	if (pid2 == 0)
		scd_child_process(argv, paths, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}
