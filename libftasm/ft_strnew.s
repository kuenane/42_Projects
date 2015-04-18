;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strnew.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/03 21:50:36 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:45:24 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_strnew
extern ft_memalloc
	
ft_strnew:
	CMP rdi, 65533
	JG .error
	ADD rdi, 1
	CALL ft_memalloc
	CMP rax, 00h
	JE .error
	RET

.error:
	MOV rax, 00h
	RET
