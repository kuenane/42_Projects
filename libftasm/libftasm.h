/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:00:18 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/05 08:39:30 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_H
# define LIBFTASM_H

# include <stddef.h>

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_putchar(int c);
void	ft_putnchar(const char *s, int nb);
void	ft_putchar_fd(int c, int fd);
size_t	ft_strlen(const char *s);
int		ft_puts(const char *s);
int		ft_puts_fd(const char *s, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_cat(int fd);

/*
** ; SECTIONS :
** ; text - program code
** ; rodata - const definitions
** ; data - initialized glob
** ; bss - uninitialized glob
** ;
** ; MOV dst, src		dst = src
** ; ADD dst, src		dst += src
** ; SUB dst, src		dst -= src
** ; INC dst			dst++
** ; DEC dst			dst--
** ; JMP label			jump to the instruction
** ; PUSH src			put src at top stack
** ; POP dst			take top stack and put it in dst
** ; MOVSB				cpy rsi to rdi (rpt while rcx > 0)
** ; rep				repeat
** ; loop toto			loop ft toto while rcx != 0
** ;lea				adress
** ;
** ; JUMP:
** ; je : jump if equal
** ; jne : jump if different
** ; jg : jump if greater
** ; jge : jump if greater or equal
** ; jl : jump if lesser
** ; jle : jump if lesser or equal
** ;
** ;					ZF : ret = 0
** ; CMP v1, v2			CF : ret < 0
** ; set the flags		SF : if sign == '-'
** ;					OF : overflow
** ;
** ; 64			32			16		[8	8]
** ; rax		eax			ax		ah	al 		return value
** ; rbx		ebx			bx		bh	bl 		callee saved
** ; rdi		edi			di		  dil		arg 1
** ; rsi		esi			si		  sil		arg 2
** ; rdx		edx			dx		dh	dl 		arg 3 + return 2
** ; rcx		ecx			cx		ch	cl 		arg 4 + counter
** ; rbp		ebp			bp		  bpl		base ptr - callee saved
** ; rsp		esp			sp		  spl		stack ptr - callee saved
** ; r8			r8d			r8w		  r8b		arg 5
** ; r9			r9d			r9w		  r9b		arg 6
** ; r10		r10d		r10w	  r10b		arg 7
** ; r11		r11d		r11w	  r11b		tmp
** ; r12		r12d		r12w	  r12b		callee saved
** ; r13		r13d		r13w	  r13b		callee saved
** ; r14		r14d		r14w	  r14b		callee saved
** ; r15		r15d		r15w	  r15b		callee saved
** ; rip				instruction pointer
** ;
** ; SYSCAL 0x20000xx	syscall nbr (in b16)
** ; move le nbr dans rax and just call "syscall"
*/

#endif
