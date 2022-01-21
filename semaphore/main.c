/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <ypetruzz@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:39:23 by ypetruzz          #+#    #+#             */
/*   Updated: 2022/01/21 23:39:25 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (!check_arg(argc, argv, &data))
		return (str_error("Error arguments\n", 1));
	if (!init_sem(&data))
		return (str_error("Init semaphore failed\n", 1));
	if (!resolve(&data))
		return (str_error("Resolve failed\n", 1));
	return (0);
}
