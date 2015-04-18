;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memalloc.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/03 21:37:24 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:47:03 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_memalloc
extern malloc
	
ft_memalloc:
	CALL malloc
	CMP rax, 00h
	JE .malloc_error
	RET
	
.malloc_error:
	RET
