;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/02 15:27:27 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:45:40 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_strlen

ft_strlen:
	PUSH rdi
	MOV rax, 0
	MOV rcx, -1
	REPNZ scasb
	NOT rcx
	DEC rcx
	MOV rax, rcx
	POP rdi
	RET
