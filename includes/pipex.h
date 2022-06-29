/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:23:04 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/29 13:50:54 by vhaefeli         ###   ########.fr       */
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

typedef struct s_list
{
	char			*path_cmd;
	char			**cmd_with_flags;
	char			*infile;
	char			*outfile;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_free_s2(char *s1, char *s2);
int		ft_printf(const char *src, ...);

void	ft_lstadd_back(t_list *alst, t_list *new);
t_list	*ft_lstnewcmd(char **path, char *cmd);
t_list	*lst_delonecmd(t_list *list_cmds);

void	check_nbargv(int argc);
void	check_file(char **argv);

void	ft_error(t_list *list_cmds, char **path);

char	**path_finder(char **envp);
char	*cmd_path(char **path, char *cmd);

char	*cmd_path(char **path, char *cmd);

t_list	*list_cmds(char **argv, char **envp);

void	child_process(t_list *list_cmds, int fd[], char **envp);

void	pipex(t_list **first_cmd, char **envp);

#endif
