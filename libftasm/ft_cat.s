;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/05 08:25:14 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 09:52:00 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_cat
extern ft_putnchar

ft_cat:
	CMP rdi, -1
	JE .exit
	LEA rsi, [rel buff]
	MOV rdx, 10
	MOV rax, 0x2000003
	SYSCALL
	JC .exit
	CMP rax, 1
	JL .exit
	PUSH rsi
	PUSH rdi
	MOV rdi, rsi
	MOV rsi, rax
	CALL ft_putnchar
	MOV rsi, rdi
	POP rdi
	POP rsi
	JMP ft_cat

.exit:
	RET

section .bss
	buff resb 10