/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:10:30 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/28 16:09:43 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	*cmd_list;

	check_nbargv(argc);
	check_file(argv);
	cmd_list = list_cmds(argv, envp);
	ft_printf("avant pipex");
	ft_printf("\n path cmd %s\n", cmd_list->path_cmd);
	ft_printf("\n cmd dans flag %s\n", cmd_list->cmd_with_flags[0]);
	if (cmd_list == NULL)
	{
		ft_printf("error with cmds listing");
		return (1);
	}
	pipex(&cmd_list, envp);
	ft_printf("check\n");
	free(cmd_list);
//	lst_del(cmd_list);
	return (0);
}
