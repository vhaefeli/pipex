/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/28 16:04:52 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list *firstcmd, t_list *new)
{
	t_list	*lastel;

	if (!new)
		return ;
	lastel = ft_lstlast(firstcmd);
	if (!lastel)
		firstcmd = new;
	else
		lastel->next = new;
}

t_list	*ft_lstnewcmd(char **path, char *cmd)
{
	t_list	*list;

	int		i = 0;
	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->cmd_with_flags = ft_split(cmd, ' ');
	while (list->cmd_with_flags[i])
		ft_printf("cmd:%s\n", list->cmd_with_flags[i++]);
	list->path_cmd = cmd_path(path, list->cmd_with_flags[0]);
	ft_printf("path:%s\n", list->path_cmd);
	if (list->path_cmd == NULL)
		return (NULL);
	list->infile = NULL;
	list->outfile = NULL;
	list->next = NULL;
	return (list);
}

t_list	*lst_delonecmd(t_list *list_cmds)
{
	int	i;
	t_list	*next_cmd;

	i = 0;
	next_cmd = list_cmds->next;
	ft_printf("\n A.cmdflag %s\n", list_cmds->cmd_with_flags[i]);
	ft_printf("\n(*list_cmds)->path_cmd: %s\n", list_cmds->path_cmd);
	free(list_cmds->path_cmd);
	list_cmds->path_cmd = NULL;
	while(list_cmds->cmd_with_flags[i])
	{
		ft_printf("free cmdflag %s\n", list_cmds->cmd_with_flags[i]);
		free(list_cmds->cmd_with_flags[i]);
		list_cmds->cmd_with_flags[i] = NULL;
		i++;
	}
	ft_printf("3\n");
	free(list_cmds->cmd_with_flags);
	list_cmds->cmd_with_flags = NULL;
	ft_printf("4\n");
	free (list_cmds);
	ft_printf("5\n");
	return (next_cmd);
}
