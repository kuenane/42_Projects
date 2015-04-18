;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/02 10:09:58 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:44:38 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_toupper

ft_toupper:
	CMP rdi, 'a'
	JL .isnt_low
	CMP rdi, 'z'
	JG .isnt_low
	MOV rax, rdi
	SUB rax, 32
	RET

.isnt_low:
	MOV rax, rdi
	RET
