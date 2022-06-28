/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:22:11 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/28 16:19:45 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path_finder(char **envp)
{
	int		i;
	char	*path;
	char	**all_path;

	i = 0;
	while (envp[i] && (ft_strnstr(envp[i], "PATH=", 5) == NULL))
		i++;
	if (envp[i] == NULL)
	{
		ft_printf("(Error) PATH not found\n");
		exit(EXIT_FAILURE);
	}
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	all_path = ft_split(path, ':');
	free(path);
	return (all_path);
}

char	*cmd_path(char **path, char *cmd)
{
	char	*temp_cmd;
	int	 i;

	i = 0;
	while (path[i])
	{
		temp_cmd = ft_strjoin("/", cmd);
		temp_cmd = ft_strjoin_free_s2(path[i], temp_cmd);
		if (access(temp_cmd, F_OK) == 0)
		{
			//free(cmd);
			return(temp_cmd);
		}
		else
		{
			free(temp_cmd);
			i++;
		}
	}
	return (NULL);
}

void	ft_error(t_list *list_cmds, char **path)
{
	int i;

	i = 0;
	ft_printf("free cmdflag %s\n", (list_cmds)->cmd_with_flags[0]);
	ft_printf("error\n");
	while(list_cmds)
	{
		lst_delonecmd(list_cmds);
		list_cmds = (list_cmds)->next;
	}
	if (list_cmds)
		free(list_cmds);
	if (path)
	{
		while (path[i])
		{
			free(path[i]);
			i++;
		}
		free(path);
	}
	exit(EXIT_FAILURE);
}

t_list	*list_cmds(char **argv, char **envp)
{
	t_list	*new_cmd;
	t_list	*first_cmd;
	int	i;
	char	**path;

	path = path_finder(envp);
	first_cmd = ft_lstnewcmd(path, argv[2]);
	ft_printf("cmd1 : %s\n", (first_cmd)->cmd_with_flags[0]);
	if (first_cmd == NULL)
	{
		ft_printf("command not fount");
		ft_error(first_cmd, path);
	}
	(first_cmd)->infile = argv[1];
	i = 3;
	while (argv[i + 1])
	{
		new_cmd = ft_lstnewcmd(path, argv[i]);
		ft_printf("cmd2 : %s\n", (new_cmd)->cmd_with_flags[0]);
		if (new_cmd == NULL)
		{
			ft_printf("commande not found");
			ft_error(first_cmd, path);
		}
		ft_lstadd_back(first_cmd, new_cmd);
		i++;
	}
	ft_printf("cmd2b : %s\n", (new_cmd)->cmd_with_flags[0]);
	new_cmd->outfile = argv[i];
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	return (first_cmd);
}

// t_list	**list_cmds(char **argv, char **envp)
// {
// 	t_list	*new_cmd;
// 	t_list	**first_cmd;
// 	int	i;
// 	char	**path;

// 	first_cmd = malloc(sizeof(**first_cmd));
// 	path = path_finder(envp);
// 	*first_cmd = ft_lstnewcmd(path, argv[2]);
// 	ft_printf("commande not found : %s\n", (*first_cmd)->cmd_with_flags[0]);
// 	if (first_cmd == NULL)
// 			ft_error(first_cmd, path);
// 	(*first_cmd)->infile = argv[1];
// 	i = 3;
// 	while (argv[i + 1])
// 	{
// 		new_cmd = ft_lstnewcmd(path, argv[i]);
// 		if (new_cmd == NULL && ft_printf("commande not found"))
// 			ft_error(first_cmd, path);
// 		ft_lstadd_back(first_cmd, new_cmd);
// 		i++;
// 	}
// 	new_cmd->outfile = argv[i];
// 	i = 0;
// 	while (path[i])
// 		free(path[i++]);
// 	free(path);
// 	return (first_cmd);
// }
