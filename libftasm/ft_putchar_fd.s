;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putchar_fd.s                                    :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/03 21:05:49 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:46:45 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_putchar_fd

ft_putchar_fd:
	LEA rcx, [rel buff]
	MOV [rcx], dil

	MOV rdi, rsi
	MOV rsi, rcx
	MOV rdx, 1
	MOV rax, 0x2000004
	SYSCALL
	RET

section .bss
	buff resb 1
