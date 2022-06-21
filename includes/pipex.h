/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:23:04 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/21 13:52:05 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>

typedef struct	s_cmd_arg
{
	int		n_cmd;
	char	**cmd_argv;
}	t_cmd_arg;

char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int	ft_printf(const char *src, ...);

char	**path_finder(char ** envp);

void	check_nbargv(int argc);
void	check_files(int argc, char **argv);

int	check_infile(char **argv, int fd[], int n_cmd);
int	check_outfile(char **argv, int fd[], int n_cmd);
void	child_process(t_cmd_arg cmdlist, char **paths, int fd[], char **envp);

void	exec_cmd(char **paths, char *first_cmd, char **envp, char **flags);
char	**split_flags(char *cmds);
void	pipex(char **argv, char **paths, char **envp);

#endif
