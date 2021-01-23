/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifesycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:30:45 by gdougal           #+#    #+#             */
/*   Updated: 2021/01/21 23:30:46 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <signal.h>

void	lifecycle(t_philo *phd)
{
	sem_post(phd->info->start);
	init_philo(phd);
	pthread_create(&phd->th, NULL, (void *)life_check, phd);
	if (phd->info->amdead)
	{
		pthread_join(phd->th, 0);
		return ;
	}
	while (phd->must_eat)
		every_day_the_same(phd);
	sem_wait(phd->info->must_eat);
	sem_post(phd->info->detah);
	sem_wait(phd->info->write);
}