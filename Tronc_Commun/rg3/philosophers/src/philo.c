/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:02:25 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/19 14:09:29 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	free_env(t_env *env)
{
	int	index;

	index = 0;
	while (index < env->nb_philo)
	{
		pthread_mutex_destroy(&env->philo[index].stop);
		index++;
	}
	if (env->philo)
		free(env->philo);
	if (env)
		free(env);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 5 || argc == 6)
	{
		env = malloc(sizeof(t_env));
		if (!env)
			return (-1);
		if (!parsing(env, argv, argc))
			return (-1);
		if (!philo_life(env))
			return (1);
		free_env(env);
		return (1);
	}
	else
	{
		printf("Usage : ./philo nb_philo tm_die tm_eat tm_sleep [nb_must_eat]");
		return (-1);
	}
	return (0);
}
