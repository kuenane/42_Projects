;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/03 21:58:33 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:45:18 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_strdup
extern ft_strlen
extern ft_strnew
extern ft_memcpy

ft_strdup:
	CALL ft_strlen
	PUSH rdi
	PUSH rax
	MOV rdi, rax
	CALL ft_strnew
	CMP rax, 00h
	JE .error
	MOV rdi, rax
	POP rdx
	POP rsi
	CALL ft_memcpy
	RET

.error:
	RET
