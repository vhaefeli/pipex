/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   list_cmd.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vhaefeli <vhaefeli@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/24 13:22:11 by vhaefeli		  #+#	#+#			 */
/*   Updated: 2022/06/27 21:12:43 by vhaefeli		 ###   ########.fr	   */
/*																			*/
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
			free(cmd);
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

void	ft_error(t_list **list_cmds, char **path)
{
	int i;

	i = 0;

	while(*list_cmds)
	{
		lst_delonecmd(*list_cmds);
		*list_cmds = (*list_cmds)->next;
	}
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

t_list  **list_cmds(char **argv, char **envp)
{
	t_list  *new_cmd;
	t_list  **first_cmd;
	int	 i;
	char	**path;

	first_cmd = malloc(sizeof(**first_cmd));
	path = path_finder(envp);
    // ft_printf("1");
	*first_cmd = ft_lstnewcmd(path, argv[2]);
    ft_printf("2");
	(*first_cmd)->infile = argv[1];
	i = 3;
	while (argv[i + 1])
	{
        ft_printf("3");
		new_cmd = ft_lstnewcmd(path, argv[i]);
		if (new_cmd == NULL && ft_printf("commande not found : %s\n", new_cmd->cmd_with_flags[0]))
			ft_error(first_cmd, path);
		ft_lstadd_back(first_cmd, new_cmd); 
		i++;
        ft_printf("4");
	}
    free(first_cmd);
	new_cmd->outfile = argv[i];
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	return (first_cmd);
}


// char	**cmds_finder_pipex(const char **argv, char **envp)
// {
//	 char	**path;
//	 char	full_cmds[][];
//	 int	 i;

//	 path = path_finder(envp);
//	 i = 2;
//	 while (argv[i + 2])
//	 {
//		 full_cmds[i - 2] = ft_split(argv[i], ' ');
//		 i++;
//	 }
//	 i = 0;
//	 while (full_cmd[i])
//	 {
//		 full_cmd[i][0] = cmd_path(path, full_cmds[i][0]);
//		 if (full_cmd[i][0] == NULL)
//			 ft_error_cmd(&full_cmds, &path);
//		 i++;
//	 }
//	 full_cmds[i] = NULL;
//	 while (paths[i])
// 	{
// 		free(paths[i]);
// 		i++;
// 	}
//	 free(path);
// }
