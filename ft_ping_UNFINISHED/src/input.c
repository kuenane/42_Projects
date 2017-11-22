/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 08:28:44 by wide-aze          #+#    #+#             */
/*   Updated: 2017/02/25 09:54:33 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>

/*
* Set all default values
*/
void     init(t_env *env)
{
  ft_bzero(env, sizeof(*env));    

  TIMEOUT = DEFAULT_TIMEOUT;

  TTL = DEFAULT_TTL;
}

/*
* Check and set extracted args
*/
void     check_and_set_extracted_args(t_env *env)
{
  if (CFG_TTL)
  {
    long long int tmp_ttl = ft_atoll(CFG_TTL);
    if (ft_strlen(CFG_TTL) > 18 || tmp_ttl < -2147483647)
      tmp_ttl = 2147483648;
    else if (tmp_ttl < 0)
      tmp_ttl += 4294967296;
    else if (tmp_ttl > 2147483646)
      tmp_ttl = 2147483647;
    if (!tmp_ttl)
      ft_exit(TTL_UNDERFLOW);
    if (tmp_ttl > 255)
    {
      printf("%s%lld%s\n", TTL_OVERFLOW1, tmp_ttl, TTL_OVERFLOW2);
      ft_exit(NULL);
    }
    v_free(CFG_TTL);
  }

  if (CFG_TIMEOUT)
  {
    int tmp_timeout = ft_atoi(CFG_TIMEOUT);
    if (ft_strlen(CFG_TIMEOUT) > 4 || tmp_timeout < 0 || tmp_timeout > 2147)
      ft_exit(TIMEOUT_BAD_TIME);
    if (tmp_timeout > 2)
      TIMEOUT = (short)tmp_timeout;
    v_free(CFG_TIMEOUT);
  }

  if (CFG_DEADLINE)
  { 
    long long int tmp_deadline = ft_atoll(CFG_DEADLINE);
    if (ft_strlen(CFG_DEADLINE) > 9 || tmp_deadline == 0)
      ;
    else if (tmp_deadline < 0)
      ft_exit(DEADLINE_BAD_TIME);
    else
      DEADLINE = (unsigned long int)tmp_deadline;
    v_free(CFG_DEADLINE);
  }

  IP_ORIG = IP;
}

/*
* Parse input to set options + ip
*/
void     parse_input(t_env *env, int ac, char **av)
{
  // init
    init(env);   
  //

  // no host check
    if (ac < 2)
      ft_exit(USAGE);
  //

  for (int i = 1; i < ac; ++i)
  {
    // check for simple option
      if (ft_strlen(av[i]) > 1 && av[i][0] == '-')
      {
        int go_to_next_index = 0;

        for (int j = 1; av[i][j] && !go_to_next_index; ++j) // parse the options
        {
          switch (av[i][j])
          {
            case 'V': // version
              ft_exit(VERSION);

            case 'h': // help
              ft_exit(USAGE);

            case 'v': // verbose enabled
              OPTS |= OPT_V;
              break ;

            case 't': // set ttl

              // is just after the argument
                if (av[i][++j])
                  CFG_TTL = v_strdup(&av[i][j]);
              //

              // is in next string
                else if (++i == ac)
                {
                  printf("%s%c\n%s\n", REQUIRE_ARGUMENT, av[--i][j], USAGE);
                  ft_exit(NULL);
                }
                else
                  CFG_TTL = v_strdup(av[i]);
              //

              ++go_to_next_index;

              break;

            case 'W': // set timeout value, defaut=DEFAULT_TIMEOUT

              // is just after the argument
                if (av[i][++j])
                  CFG_TIMEOUT = v_strdup(&av[i][j]);
              //

              // is in next string
                else if (++i == ac)
                {
                  printf("%s%c\n%s\n", REQUIRE_ARGUMENT, av[--i][j], USAGE);
                  ft_exit(NULL);
                }
                else
                  CFG_TIMEOUT = v_strdup(av[i]);
              //

              ++go_to_next_index;

              break;

            case 'w': // set a deadline

              // is just after the argument
                if (av[i][++j])
                  CFG_DEADLINE = v_strdup(&av[i][j]);
              //

              // is in next string
                else if (++i == ac)
                {
                  printf("%s%c\n%s\n", REQUIRE_ARGUMENT, av[--i][j], USAGE);
                  ft_exit(NULL);
                }
                else
                  CFG_DEADLINE = v_strdup(av[i]);
              //

              ++go_to_next_index;

              break;

            default:
              printf("%s%c\n%s\n", ILLEGAL_OPTION, av[i][j], USAGE);
              ft_exit(NULL);
          }
        }
      //
    }

    // it's last elem so it's ip
      else if (i == ac - 1)
        IP = av[i];
    //

    // others ips (just to check)
      else
      {
        if (!HOPS)
          HOPS = v_strtabnew(1);
        HOPS = add_str_strtab(HOPS, av[i]);
      }
    //
  }

  // check if host is specified
    if (!IP)
      ft_exit(USAGE);
  //
  
  check_and_set_extracted_args(env);
}
