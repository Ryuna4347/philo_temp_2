/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:57:21 by hyunyoo           #+#    #+#             */
/*   Updated: 2021/07/09 15:57:22 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->game->fork_m);
	print_message(philo, PHILO_FORK);
	sem_wait(philo->game->fork_m);
	print_message(philo, PHILO_FORK);
}

void	put_down_forks(t_philo *philo)
{
	print_message(philo, PHILO_SLEEP);
	sem_post(philo->game->fork_m);
	sem_post(philo->game->fork_m);
	delay_time(philo->game->tts);
}
