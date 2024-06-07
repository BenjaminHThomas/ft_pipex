/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:49:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 19:30:36 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	data;
	int		retval;

	if (ac < 5)
		return (1);
	if (init(&data, ac, av, envp))
	{
		free_mem(&data);
		close_fds(&data);
		return (1);
	}
	retval = exec_cmds(&data);
	close_fds(&data);
	free_mem(&data);
	return (retval);
}
