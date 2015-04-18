;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/02 09:55:29 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:47:24 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_isascii

ft_isascii:
	CMP rdi, 0
	JL .false
	CMP rdi, 127
	JG .false
	MOV rax, 1
	RET
	
.false:
	MOV rax, 0
	RET
