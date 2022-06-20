/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:23:04 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/06/20 14:36:45 by vhaefeli         ###   ########.fr       */
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

char	**path_finder(char ** envp);

void    check_nbargv(int argc);
int		commands_quantity(int, argc, char **argv);
void	check_files(int argc, char **argv);

// int		child_execution

#endif
