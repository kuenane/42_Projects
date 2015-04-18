;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/02 10:21:56 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:44:46 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_tolower

ft_tolower:
	CMP rdi, 'A'
	JL .isnt_up
	CMP rdi, 'Z'
	JG .isnt_up
	MOV rax, rdi
	ADD rax, 32
	RET

.isnt_up:
	MOV rax, rdi
	RET
