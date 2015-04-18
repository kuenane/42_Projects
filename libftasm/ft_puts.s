;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/03 09:26:24 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:46:16 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_puts
extern ft_strlen
extern ft_putchar

ft_puts:
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
	MOV rdi, 10
	CALL ft_putchar
	MOV rax, 1
	RET

.null:
	LEA rcx, [rel nullstr]
	MOV rdi, 1
	MOV rsi, rcx
	MOV rdx, 6
	MOV rax, 0x2000004
	SYSCALL
	MOV rdi, 10
	CALL ft_putchar
	MOV rax, 1
	RET

section .data
	nullstr: db "(null)"
