;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/03 19:46:46 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/03 20:29:14 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_memcpy
	
ft_memcpy:
	PUSH rdi
	MOV rcx, rdx
	REP movsb
	POP rax
	RET
