/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <ypetruzz@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:45:07 by ypetruzz          #+#    #+#             */
/*   Updated: 2022/01/21 16:45:08 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (!check_arg(argc, argv, &data))
		return (str_error("Error arguments\n", 1));
	if (!init_mutex(&data))
		return (str_error("Init mutex failed\n", 1));
	if (!resolve(&data))
		return (str_error("Resolve failed\n", 1));
	return (0);
}
