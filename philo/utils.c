/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:56:59 by hyunyoo           #+#    #+#             */
/*   Updated: 2021/07/09 15:57:01 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t		get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void			delay_time(int time)
{
	struct timeval	target_time;
	struct timeval	now_time;
	int				target;
	int				now;

	gettimeofday(&target_time, NULL);
	target = target_time.tv_sec * 1000 + target_time.tv_usec / 1000;
	target = target + time;
	gettimeofday(&now_time, NULL);
	now = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	while (target >= now)
	{
		usleep(100);
		gettimeofday(&now_time, NULL);
		now = now_time.tv_sec * 1000 + now_time.tv_usec / 1000;
	}
}

int				ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !(s))
		return ;
	write(fd, s, ft_strlen(s));
}

void			ft_putnbr_fd(uint64_t n, int fd)
{
	char	str[13];
	int		length;

	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], 1);
}
