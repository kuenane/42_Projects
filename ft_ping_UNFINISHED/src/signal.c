/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 22:28:25 by wide-aze          #+#    #+#             */
/*   Updated: 2017/02/25 09:59:05 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>
#include <signal.h>

/*
 * printf time (given in ms)
*/
void printf_time(long time, t_bool onlySec)
{
  if (onlySec)
    printf("%ld", time/1000);
  else if (time >= 100000)
    printf("%ld", time/1000);
  else if (time >= 10000)
    printf("%ld.%01ld", time/1000, (time%1000)/100);
  else if (time >= 1000)
    printf("%ld.%02ld", time/1000, (time%1000)/10);
  else
    printf("%ld.%03ld", time/1000, time%1000);
}

/*
 * get diff between two time
*/
long get_difftime(struct timeval *start, struct timeval *end)
{
  long diff = end->tv_usec - start->tv_usec;
  
  diff += 1000000*(end->tv_sec - start->tv_sec);

  return (diff);
}

static t_env    *save_env(t_env *env)
{
  // declare the static
    static t_env *statenv = NULL;
  //

  // if static empty, set it
    if (env)
      statenv = env;
  //

  // return static var
    return (statenv);
  //
}

/*
* Signal ignored
*/
static void     signal_ignored(int signl)
{
    (void)signl;
}

/*
* Calc final stats: total time / round trips
* @param: 0=totalTime 1=roundTripMin 2=roundTripAvg 3=roundTripMax 4=roundTripStddev
*/
static void     calc_final_stats(t_env *env, long *tab)
{
  // init
    tab[0] = 0;
    tab[1] = 0;
    tab[2] = 0;
    tab[3] = 0;
    tab[4] = 0;
  //

  if (!NB_PACKET_RECEIVED || !TIMELST)
    return ;
  
  // set total end time
    gettimeofday(&TOTAL_END_TIME, NULL);
  //
  
  // totalEndTime
    tab[0] = get_difftime(&TOTAL_START_TIME, &TOTAL_END_TIME);
    tab[0] -= tab[0] % 1000000;
  //
  
  // roundTripMin + roundTripMax + roundTripAvg
    tab[1] = TIMELST->diff;
    tab[3] = TIMELST->diff;
    for (t_t *it = TIMELST; it != NULL; it = it->next)
    {
      tab[2] += it->diff;
      if (it->diff < tab[1])
        tab[1] = it->diff;
      if (it->diff > tab[3])
        tab[3] = it->diff;
    }
    tab[2] /= NB_PACKET_RECEIVED;
  //

  // roundTripStddev
    for (t_t *it = TIMELST; it != NULL; it = it->next)
    {
      if (it->diff - tab[2] > 0)
        tab[4] += (int)(it->diff - tab[2]) * (int)(it->diff - tab[2]);
      else
        tab[4] += (int)(tab[2] - it->diff) * (int)(tab[2] - it->diff);
    }
    tab[4] = ft_square_root(tab[4] / NB_PACKET_RECEIVED);
  // 
}

/*
* Signal exit
*/
static void     signal_exit(int signl)
{
    (void)signl;

    // get env
        t_env *env = save_env(NULL);
    //

    // calc final stats
      long stats[5]; // 0=totalTime 1=roundTripMin 2=roundTripAvg 3=roundTripMax 4=roundTripStddev
      calc_final_stats(env, &stats[0]);
    //

    // print stats msg
        printf("\n--- %s ping statistics ---\n", IP_ORIG);
        printf("%d packets transmitted, %d received, %.0f%% packet loss, time ", NB_PACKET_SENT, NB_PACKET_RECEIVED, ((NB_PACKET_SENT) ? ((NB_PACKET_SENT-NB_PACKET_RECEIVED)*100.0/NB_PACKET_SENT) : 0.0 ));
        printf_time(stats[0], TRUE);
        printf("ms\n");
    //

    // print optionnal stats msg (only if at least one packed received)
    if (NB_PACKET_RECEIVED)
    {
      printf("rtt min/avg/max/mdev = ");
      printf_time(stats[1], FALSE);
      printf("/");
      printf_time(stats[2], FALSE);
      printf("/");
      printf_time(stats[3], FALSE);
      printf("/");
      printf_time(stats[4], FALSE);
      printf("ms\n");
    }
    //

    // exit
        ft_exit(NULL);
    //
}

/*
* Signal alarm
*/
static void     signal_alarm(int signl)
{
  (void)signl;
  
  // get env
    t_env *env = save_env(NULL);
  //
  
  prepare_packet(env);
  ft_ping(env);
  get_response(env);
  alarm(1);
}

/*
* Handle the signals
*/
void    handle_signals(t_env *env)
{
    // we save the env to get it on signal callback
        save_env(env);
    //

    // handle each signal
        for (int i = 1; i < 32; ++i)
        {
            switch (i)
            {
                case SIGTSTP:
                case SIGCONT:
                case SIGCHLD:
                case SIGURG:
                case SIGIO:
                case SIGWINCH:
                    signal(i, &signal_ignored);
                    break;
                case SIGALRM:
                    signal(i, &signal_alarm);
                    break;
                default:
                    signal(i, &signal_exit);
                    break;
            }
        }
    //
}
