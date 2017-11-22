/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 08:28:44 by wide-aze          #+#    #+#             */
/*   Updated: 2016/12/18 13:13:45 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>

int		main(int ac, char **av)
{
    if (getuid())
       ft_exit(NEED_ROOT_PRIVILEGES);

    t_env   env;

    handle_signals(&env);
    
    parse_input(&env, ac, av);

    convert_host(&env);
    
    set_socket(&env);

    init_packet(&env);

    init_response(&env);

    prepare_packet(&env);

    ft_ping(&env);

    get_response(&env);
  
    alarm(1);

    while(42)
      ;

    return (0);
}
