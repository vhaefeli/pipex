/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:02:58 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/19 22:04:39 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**path_finder(char **envp)
{
	int		i;
	char	*path;
	char	**all_path;

	i = 0;
	while (envp[i] && (ft_strnstr(envp[i], "PATH", 5) == NULL))
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