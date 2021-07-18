/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:57:48 by hyunyoo           #+#    #+#             */
/*   Updated: 2021/07/18 15:20:16 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*get_message(int type)
{
	if (type == PHILO_EAT)
		return (" is eating\n");
	else if (type == PHILO_SLEEP)
		return (" is sleeping\n");
	else if (type == PHILO_FORK)
		return (" takes a fork\n");
	else if (type == PHILO_THINK)
		return (" is thinking\n");
	else if (type == PHILO_OVER)
		return ("least eat count reached\n");
	else
		return (" died\n");
}

void	print_message(t_philo *philo, int type)
{
	sem_wait(philo->game->write_m);
	sem_wait(philo->game->dead_write_m);
	ft_putnbr_fd(get_time() - philo->game->start, 1);
	ft_putstr_fd(" ", 1);
	if (type != PHILO_OVER)
		ft_putnbr_fd(philo->idx + 1, 1);
	write(1, get_message(type), ft_strlen(get_message(type)));
	if (!(type == PHILO_DIED || type == PHILO_OVER))
		sem_post(philo->game->dead_write_m);
	sem_post(philo->game->write_m);
}
