/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:43:30 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/01/25 07:09:52 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_fds_debug(char *joined, char **cmd, char c, int pipes)
{
	printf("\n-----------------------\n");
	if (c == '1')
		printf("entré por el principio\n");
	if (c == '2')
		printf("entré por el medio\n");
	if (c == '3')
		printf("entré por el final\n");

	print_debug_2d_array(cmd);
	printf("joined: %s\n\n", joined);
	printf("Leo          [%d][0]\n\n", pipes);
	printf("Escribo      [%d][1]\n\n", pipes);
	printf("-----------------------\n\n");
}
