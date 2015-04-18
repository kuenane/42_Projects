;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/31 16:55:42 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:47:17 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global	ft_isdigit

ft_isdigit:
	CMP rdi, '0'
	JL .false
	CMP rdi, '9'
	JG .false
	MOV rax, 1
	RET
	
.false:
	MOV rax, 0
	RET
