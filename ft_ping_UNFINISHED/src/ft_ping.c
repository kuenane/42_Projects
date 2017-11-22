/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 08:28:44 by wide-aze          #+#    #+#             */
/*   Updated: 2017/02/25 10:38:16 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ping.h>

/*
 * convert host
 */
void    convert_host(t_env *env)
{
  // reset addr struct
    ft_bzero(&ADDR, sizeof(struct sockaddr_in));
  //

  // set to ipv4
    ADDR.sin_family = AF_INET;
  //

  // direct IPv4
    if (inet_pton(AF_INET, IP, &ADDR.sin_addr) != 1)
      return ;
  //

  // not direct, build linked list infos to host
    struct addrinfo hints;
    struct addrinfo *result;
    ft_bzero(&hints, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; // (only ipv4)
    hints.ai_socktype = SOCK_DGRAM; // datagram socket (no tcp, udp only)
    hints.ai_flags = AI_CANONNAME; // get offcial host name
    if (getaddrinfo(IP, NULL, &hints, &result))
    {
      printf("%s%s\n", UNKNOWN_HOST, IP);
      ft_exit(NULL);
    }
  //
    
  // search host ip in result linked list
    char tmp[INET_ADDRSTRLEN];
    while (result && result->ai_family != AF_INET)
      result = result->ai_next;
    if (result)
    {
      IP = ft_strdup(inet_ntop(AF_INET, &((struct sockaddr_in*)result->ai_addr)->sin_addr, &tmp[0], INET_ADDRSTRLEN));
      inet_pton(AF_INET, IP, &ADDR.sin_addr);
    }
   //
} 

/*
 * set socket
 */
void    set_socket(t_env *env)
{
  // open socket
    if ((SOCKET_FD = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
      ft_exit(CANNOT_OPEN_SOCKET);
  //

  // set TTL
    if (setsockopt(SOCKET_FD, SOL_IP, IP_TTL, (void*)&TTL, sizeof(TTL)))
      ft_exit(CANNOT_SET_SOCKET);
  //
  
  // print start msg
    printf("PING %s (%s) %d(%d) bytes of data.\n", IP_ORIG, IP, PSIZE_WITHOUT_HEADER, PSIZE_TOTAL);
  //

}

        static unsigned short	cksum(unsigned short *addr, int len)
        {
          int		nleft;
          int		sum;
          unsigned short	*w;
          unsigned short	answer;

          w = addr;
          answer = 0;
          nleft = len;
          sum = 0;
          while (nleft > 1) 
          {
            sum += *w++;
            nleft -= 2;
          }
          if (nleft == 1)
          {
            *(unsigned char *)(&answer) = *(unsigned char *)w;
            sum += answer;
          }
          sum = (sum >> 16) + (sum & 0xffff);
          sum += (sum >> 16);
          answer = ~sum;	
          return (answer);
        }

/*
 * init packet to send
 */
void    init_packet(t_env *env)
{
  // save pid
    PID = getpid();
  //

  // set struct icmp
    ICMP.icmp_type = ICMP_ECHO; // echo request
    ICMP.icmp_id = PID; // set to pid to recognize it
  //
    
  // set total start time
    gettimeofday(&TOTAL_START_TIME, NULL);
  //
}

/*
 * init response vars
 */
void    init_response(t_env *env)
{
  // set iovec struct
    IOV.iov_base = &IOV_BUF; // buffer to receive datas
    IOV.iov_len = IOV_BUF_SIZE; // buffer len
  //

  // set msghdr struct
    MSGHDR.msg_name = &MSGHDR_ADDR;
    MSGHDR.msg_namelen = sizeof(struct sockaddr_in);
    MSGHDR.msg_iov = &IOV;
    MSGHDR.msg_iovlen = 1;
  //
}

/*
 * prepare packet to send
 */
void    prepare_packet(t_env *env)
{
  // set struct icmp
    ICMP.icmp_seq = ++NB_PACKET_SENT; // sequence number
  //

  // set icmp checksum
    ICMP.icmp_cksum = 0;
    ICMP.icmp_cksum = cksum((unsigned short *)&ICMP,PSIZE_TOTAL);
  // 
}

/*
 * now we ping
 */
void    ft_ping(t_env *env)
{
  // add new list elem + set start time
    t_t *newLst = v_malloc(sizeof(t_t));
    newLst->next = ((TIMELST) ? TIMELST : NULL);
    newLst->diff = -1;
    TIMELST = newLst;
    gettimeofday(&TIMELST->start, NULL);
  //
    
  // send packet
    if (sendto(SOCKET_FD, &ICMP, PSIZE_TOTAL, 0, (void*)&ADDR, sizeof(struct sockaddr_in)) == -1)
      ft_exit(SENDTO_ERROR);
  //
}

/*
 * analyse received packet
 */
static int    analyse_received_packet(t_env *env, struct msghdr *msg, int ret)
{
  // check response validity
    if (ret < (int)(sizeof(struct ip) + sizeof(struct icmp)))
      return (-1);
  //

  // get ip struct (first part of buffer)
    struct ip *ip = (struct ip*)msg->msg_iov->iov_base;
  //

  // get icmp struct (second part of buffer)
    struct icmp *icmp = (struct icmp*)(msg->msg_iov->iov_base + sizeof(struct ip));
  //

  // check if its a response to a ping and its for us
    if (icmp->icmp_id != PID || icmp->icmp_type != ICMP_ECHOREPLY)
      return (-1);
  // 
  
  // set end time + diff
    gettimeofday(&TIMELST->end, NULL);
    TIMELST->diff = get_difftime(&TIMELST->start, &TIMELST->end);
  //

  // packet is considered received
    ++NB_PACKET_RECEIVED;
  //

  // print stats
    if (ft_strcmp(IP, IP_ORIG))
      printf("%d bytes from %s (%s): icmp_seq=%d ttl=%hhu time=", PSIZE_WITH_HEADER, IP_ORIG, IP, icmp->icmp_seq, ip->ip_ttl);
    else
      printf("%d bytes from %s: icmp_seq=%d ttl=%hhu time=", PSIZE_WITH_HEADER, IP_ORIG, icmp->icmp_seq, ip->ip_ttl);
    printf_time(TIMELST->diff, FALSE);
    printf(" ms\n");
    fflush(NULL);
  //
  
  return (0);
}

/*
 * get ping responses
 */
void    get_response(t_env *env)
{
  // read and analyze msg
    int ret = recvmsg(SOCKET_FD, &MSGHDR, 0);
    if (analyse_received_packet(env, &MSGHDR, ret))
      get_response(env);
  //
}
