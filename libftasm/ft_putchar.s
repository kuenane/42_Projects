;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putchar.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/02 11:58:28 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:46:39 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_putchar

ft_putchar:
	LEA rcx, [rel buff]
	MOV [rcx], dil
	MOV rdi, 1
	MOV rsi, rcx
	MOV rdx, 1
	MOV rax, 0x2000004
	SYSCALL
	RET

section .bss
	buff resb 1
