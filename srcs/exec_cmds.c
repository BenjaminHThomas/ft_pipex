/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:55:58 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/06 12:48:43 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	redirect_io(int fdin, int fdout, t_pipe *data)
{
	if (dup2(fdin, STDIN_FILENO) == -1)
	{
		perror("Error: could not redirect stdin\n");
		clean_exit(data, 1);
	}
	if (dup2(fdout, STDOUT_FILENO) == -1)
	{
		perror("Error: could not redirect stdout\n");
		clean_exit(data, 1);
	}
}

int	child(t_pipe *data, int i)
{
	int	retval;
	int	idx;

	idx = i - 2;
	ft_printf("Idx: %d\n", idx);
	retval = 0;
	data->pid = fork();
	if (data->pid < 0)
	{
		perror("Error: could not fork process.\n");
		clean_exit(data, 1);
	}
	if (data->pid == 0)
	{
		ft_printf("\ni %d, ac %d\n", i, data->ac);
		if (i == 2)
		{
			ft_printf("First iteration\n");
			redirect_io(data->fdinfile, data->pipe_arr[idx][1], data);
		}
		else if (i == (data->ac - 2))
		{
			redirect_io(data->pipe_arr[idx][0], data->fdoutfile, data);
			ft_printf("Last iteration\n");
		}
		else
		{
			redirect_io(data->pipe_arr[idx][0], data->pipe_arr[idx][1],
						data);
			ft_printf("Middle iteration\n");
		}
		close_fds(data);
		retval = execve(data->cmd_paths[idx], data->cmd_args[idx],
						data->envp);
	}
	return (retval);
}

int	exec_cmds(t_pipe *data)
{
	int	i;
	int	retval;

	i = 2;
	retval = 0;
	while (i < (data->ac - 1))
	{
		ft_printf("Iter: %d\n", i);
		retval = child(data, i);
		if (retval != 0)
			clean_exit(data, retval);
		waitpid(data->pid, NULL, 0);
		i++;
	}
	return (retval);
}
