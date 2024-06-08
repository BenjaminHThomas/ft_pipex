/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:55:58 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/08 21:15:59 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	io_swap(int fdin, int fdout, t_pipe *data)
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

/*
void	debug_print(t_pipe *data, int i)
{
	int	j;

	if (i == 2)
		ft_printf("First iteration.\n");
	else if (i == (data->ac - 2))
		ft_printf("Last iteration.\n");
	else
		ft_printf("Middle iteration.\n");
	ft_printf("path: %s\n", data->cmd_paths[i - 2]);
	ft_printf("cmd: %s\n", data->av[i]);
	ft_printf("Number of commands: %d\n", data->ac - 3);
	j = 0;
	while (data->pipes[j])
		j++;
	ft_printf("Number of pipes: %d\n\n", j);
}
*/

void	child(t_pipe *data, int i)
{
	int	idx;

	idx = i - 2;
	if (i == 2)
		io_swap(data->fdinfile, data->pipes[idx + 1][1], data);
	else if (i == (data->ac - 2))
		io_swap(data->pipes[idx][0], data->fdoutfile, data);
	else
		io_swap(data->pipes[idx][0], data->pipes[idx + 1][1], data);
	execve(data->cmd_paths[idx], data->cmd_args[idx], data->envp);
	clean_exit(data, 0);
}

int	exec_cmds(t_pipe *data)
{
	pid_t	pids[data->cmd_count];
	int		i;
	int		retval;

	i = 2;
	retval = 0;
	while ((i - 2) < data->cmd_count)
	{
		close(data->pipes[i - 2][1]);
		pids[i - 2] = fork();
		if (pids[i - 2] == 0)
			child(data, i);
		i++;
	}
	close_fds(data);
	i = -1;
	while (++i < data->cmd_count)
		waitpid(pids[i], &retval, 0);
	return (retval);
}
