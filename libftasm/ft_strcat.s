;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/03 15:33:35 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:45:51 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_strcat
extern ft_strlen
extern ft_strdup
	
ft_strcat:
	PUSH rdi
	MOV rax, 0
	MOV rcx, -1
	REPNZ scasb
	DEC rdi
	PUSH rdi
	MOV rdi, rsi
	CALL ft_strlen
	CMP rax, 0
	JE .s2null
	MOV rcx, rax
	INC rcx
	POP rdi
	REPNZ movsb
	POP rax
	RET

.s2null:
	POP rdi
	POP rax
	RET
