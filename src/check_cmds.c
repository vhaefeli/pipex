/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:05:53 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/22 17:09:50 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (paths[i] == NULL)
		printf("error");
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

char	**check_cmd(char **argv, char envp, char **cmd_list)
{
	char	**paths;

	paths = path_finder(envp);

	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
}

	flags = split_flags(cmdlist.cmd_argv[cmdlist.n_cmd + 1]);
	cmd = ft_strjoin("/", flags[0]);
