;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/04 15:15:59 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/04 15:46:15 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_memset

ft_memset:
	PUSH rdi
	CMP rdx, 0
	JE .zero
	MOV rcx, rdx
	MOV rax, rsi
	REP stosb
	POP rax
	RET
	
.zero:
	POP rax
	RET
