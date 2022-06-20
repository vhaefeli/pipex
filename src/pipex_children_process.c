/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_children_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:17:40 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/20 16:31:33 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int check_infile(char **argv, int fd[], int n_cmd)
{
    if (n_cmd = 1)
    {
        return (open(argv[1], O_RDONLY));
    }
    else return (f[0]);
}

int check_outfile(char **argv, int fd[], int n_cmd)
{
    if (argv[n_cmd + 3] == NULL)
    {
        return (open(argv[n_cmd + 2], O_O_WRONLY));
    }
    else return (f[1]);
}

void	child_pro(int n_cmd, char **argv, char **paths, int fd[], char **envp)
{
	int		infile;
    int     outfile;
	char	**flags;
	char	*cmd;

	infile = check_infile(argv, fd, n_cmd);
    outfile = check_outfile(argv, fd, n_cmd);
	if (infile < 0 || outfile < 0)
	{
		close(fd[1]);
		close(fd[0]);
		perror("Fork: ");
		exit(EXIT_FAILURE);
	}
	flags = split_flags(argv[n_cmd + 1]);
	cmd = ft_strjoin("/", flags[0]);
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	exec_cmd(paths, cmd, envp, flags);
}