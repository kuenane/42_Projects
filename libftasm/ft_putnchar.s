;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putnchar.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/05 08:39:06 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:46:32 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_putnchar

ft_putnchar:
	CMP rdi, 00h
	JE .null
	MOV rdx, rsi
	MOV rsi, rdi
	MOV rdi, 1
	MOV rax, 0x2000004
	SYSCALL
	RET

.null:
	RET
