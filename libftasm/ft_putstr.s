;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putstr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/03 21:17:47 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:46:07 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_putstr
extern ft_strlen

ft_putstr:
	CMP rdi, 00h
	JE .null
	PUSH rdi
	CALL ft_strlen
	POP rdi
	MOV rdx, rax
	MOV rsi, rdi
	MOV rdi, 1
	MOV rax, 0x2000004
	SYSCALL
	RET

.null:
	LEA rcx, [rel nullstr]
	MOV rdi, 1
	MOV rsi, rcx
	MOV rdx, 6
	MOV rax, 0x2000004
	SYSCALL
	RET

section .data
	nullstr: db "(null)"
