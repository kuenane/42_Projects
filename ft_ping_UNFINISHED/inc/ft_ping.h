/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 08:25:35 by wide-aze          #+#    #+#             */
/*   Updated: 2017/01/20 20:01:20 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

// INCLUDES
  # include <libft.h>
  # include <stdio.h>
  # include <unistd.h>
  # include <sys/time.h>
  # include <arpa/inet.h>
  # include <netinet/ip_icmp.h>
  # include <netdb.h>
//

// ACCESSORS
  # define OPTS                   env->opts 
  # define IP                     env->ip
  # define IP_ORIG                env->ipOrig
  # define HOPS                   env->hops
  # define NB_PACKET_SENT         env->nbPacketsSent
  # define NB_PACKET_RECEIVED     env->nbPacketsReceived
  # define TIMELST                env->timeLst
  # define ADDR                   env->addr
  # define SOCKET_FD              env->socket_fd
  # define TTL                    env->ttl
  # define CFG_TTL                env->cfg_ttl
  # define TIMEOUT                env->timeout
  # define CFG_TIMEOUT            env->cfg_timeout
  # define DEADLINE               env->deadline
  # define CFG_DEADLINE           env->cfg_deadline
  # define PID                    env->pid
  # define ICMP                   env->icmp
  # define MSGHDR                 env->msghdr
  # define IOV                    env->iov
  # define IOV_BUF                env->iov_buf
  # define MSGHDR_ADDR            env->msghdr_addr
  # define TOTAL_START_TIME       env->totalStartTime
  # define TOTAL_END_TIME         env->totalEndTime
//

// CONSTANTS
  # define OPT_V                  1
  # define USAGE                  "usage: ft_ping [-hvV] [-t ttl] [-w deadline] [-W timeout] host"
  # define ILLEGAL_OPTION         "ft_ping: illegal option -- "
  # define INVALID_TIMEOUT1       "ft_ping: invalid timeout: `"
  # define INVALID_TIMEOUT2       "'"
  # define NEED_ROOT_PRIVILEGES   "ft_ping: root privileges needed"
  # define REQUIRE_ARGUMENT       "ft_ping: option requires an argument -- "
  # define VERSION                "ft_ping v42"
  # define TTL_UNDERFLOW          "ft_ping: can't set unicast time-to-live: Invalid argument"
  # define TTL_OVERFLOW1          "ft_ping: ttl "
  # define TTL_OVERFLOW2          " out of range"
  # define DEADLINE_BAD_TIME      "ft_ping: bad wait time."
  # define TIMEOUT_BAD_TIME       "ft_ping: bad linger time."
  # define UNKNOWN_HOST           "ft_ping: unknown host "
  # define CANNOT_OPEN_SOCKET     "ft_ping: cannot open socket"
  # define CANNOT_SET_SOCKET      "ft_ping: cannot set socket"
  # define SENDTO_ERROR           "ft_ping: cannot send packet (sendto error)"
  # define ICMPHEADER_TYPE_REQ    8
  # define ICMPHEADER_TYPE_RESP   0
  # define DEFAULT_TTL            255
  # define DEFAULT_TIMEOUT        2
  # define PSIZE_HEADER           8
  # define PSIZE_WITHOUT_HEADER   56
  # define PSIZE_WITH_HEADER      (PSIZE_WITHOUT_HEADER+PSIZE_HEADER)
  # define PSIZE_TOTAL            (PSIZE_WITH_HEADER+(int)sizeof(struct ip))
  # define IOV_BUF_SIZE           1024
//

// TIME STRUCT
  typedef struct s_t
  {
    struct timeval    start;
    struct timeval    end;
    long              diff;
    struct s_t        *next;
  }               t_t;
//

// ENV STRUCT
    typedef struct	        s_env
    {
        int                 opts;
        char                *ip;
        char                *ipOrig;
        char                **hops;
        int                 nbPacketsSent;
        int                 nbPacketsReceived;
        t_t                 *timeLst;
        struct sockaddr_in  addr; 
        int                 socket_fd;
        ul_int              ttl;
        char                *cfg_ttl;
        short               timeout;
        char                *cfg_timeout;
        ul_int              deadline;
        char                *cfg_deadline;
        pid_t               pid;
        struct icmp         icmp;
        struct msghdr       msghdr;
        struct iovec        iov;
        char                iov_buf[IOV_BUF_SIZE];
        struct sockaddr_in  msghdr_addr;
        struct timeval      totalStartTime;
        struct timeval      totalEndTime;
    }                       t_env;
//

// FUNCTIONS
    void    printf_time(long time, t_bool onlySec);
    long    get_difftime(struct timeval *start, struct timeval *end);
    void    handle_signals(t_env *env);
    void    parse_input(t_env *env, int ac, char **av);
    void    convert_host(t_env *env);
    void    set_socket(t_env *env);
    void    init_packet(t_env *env);
    void    init_response(t_env *env);
    void    prepare_packet(t_env *env);
    void    ft_ping(t_env *env);
    void    get_response(t_env *env);
//

#endif
