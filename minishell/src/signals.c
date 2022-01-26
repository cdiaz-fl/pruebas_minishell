/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:58:40 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/13 15:08:23 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	sigint_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void) sig;
	(void) info;
	(void) ucontext;
	printf("\n%sminishell 👨‍💻$ %s", BLUE, WHITE);
    // kill(0, SIGINT);
}

void	listen_signals(t_data *data)
{
	struct sigaction	s_sigaction;

	(void) data;
	// ft_memset(&s_sigaction, 0, sizeof(s_sigaction));
	s_sigaction.sa_sigaction = sigint_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &s_sigaction, NULL);
	// pause();
}
