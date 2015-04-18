;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts_fd.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/04 09:34:02 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:46:21 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_puts_fd
extern ft_strlen
extern ft_putchar_fd
	
ft_puts_fd:
	PUSH rsi
	PUSH rsi
	CMP rdi, 00h
	JE .null
	PUSH rdi
	CALL ft_strlen
	POP rsi
	MOV rdx, rax
	POP rdi
	MOV rax, 0x2000004
	SYSCALL
	MOV rdi, 10
	POP rsi
	CALL ft_putchar_fd
	RET

.null:
	LEA rcx, [rel nullstr]
	MOV rsi, rcx
	MOV rdx, 6
	POP rdi
	MOV rax, 0x2000004
	SYSCALL
	MOV rdi, 10
	POP rsi
	CALL ft_putchar_fd
	RET

section .data
	nullstr: db "(null)"
