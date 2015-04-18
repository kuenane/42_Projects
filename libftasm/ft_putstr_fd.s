;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putstr_fd.s                                     :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/04 08:41:18 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:46:01 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_putstr_fd
extern ft_strlen

ft_putstr_fd:
	CMP rdi, 00h
	JE .null
	PUSH rsi
	PUSH rdi
	CALL ft_strlen
	POP rdi
	MOV rdx, rax
	MOV rsi, rdi
	POP rdi
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
