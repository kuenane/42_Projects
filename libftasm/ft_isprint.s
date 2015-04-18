;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/02 10:04:41 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:47:10 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_isprint

ft_isprint:
	CMP rdi, 32
	JL .false
	CMP rdi, 126
	JG .false
	MOV rax, 1
	RET
	
.false:
	MOV rax, 0
	RET
