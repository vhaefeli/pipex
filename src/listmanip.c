/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/28 09:33:00 by vhaefeli         ###   ########.fr       */
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

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lastel;

	if (!new)
		return ;
	lastel = ft_lstlast(*alst);
	if (!lastel)
		*alst = new;
	else
		lastel->next = new;
}

t_list	*ft_lstnewcmd(char **path, char *cmd)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->cmd_with_flags = ft_split(cmd, ' ');
	list->path_cmd = cmd_path(path, list->cmd_with_flags[0]);
	if (list->path_cmd == 0)
		return (NULL);
	list->infile = NULL;
	list->outfile = NULL;
	list->next = NULL;
	return (list);
}

t_list	*lst_delonecmd(t_list **list_cmds)
{
	int	i;
	t_list	*next_cmd;

	i = 0;
	ft_printf("1\n");
	free((*list_cmds)->path_cmd);
	(*list_cmds)->path_cmd = NULL;
	ft_printf("2\n");
	while((*list_cmds)->cmd_with_flags[i])
	{
		free((*list_cmds)->cmd_with_flags[i]);
		(*list_cmds)->cmd_with_flags[i] = NULL;
		i++;
	}
	ft_printf("3\n");
	free((*list_cmds)->cmd_with_flags);
	(*list_cmds)->cmd_with_flags = NULL;
	ft_printf("4\n");
	next_cmd = (*list_cmds)->next;
	free (*list_cmds);
	ft_printf("5\n");
	return (next_cmd);
}
