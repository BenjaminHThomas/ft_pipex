/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:05:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 14:11:49 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_mem(t_pipe *data)
{
	int	i;

	i = 0;
	if (data->cmd_paths)
		free_arr(data->cmd_paths);
	if (data->cmd_args)
	{
		while (data->cmd_args[i])
		{
			free_arr(data->cmd_args[i]);
			i++;
		}
		free(data->cmd_args);
		data->cmd_args = NULL;
	}
	if (data->pipe_arr)
	{
		i = -1;
		while (data->pipe_arr[++i])
			free(data->pipe_arr[i]);
		free(data->pipe_arr);
	}
}

void	close_fds(t_pipe *data)
{
	int	i;
	int	y;

	close(data->fdinfile);
	close(data->fdoutfile);
	i = 0;
	while (i < (data->ac - 3))
	{
		y = 0;
		while (y < 2)
		{
			close(data->pipe_arr[i][y]);
			y++;
		}
		i++;
	}
}

void	clean_exit(t_pipe *data, int exitcode)
{
	close_fds(data);
	free_mem(data);
	exit(exitcode);
}
