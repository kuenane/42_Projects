;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/03 14:33:17 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:44:06 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global ft_bzero

ft_bzero:
	CMP rsi, 0
	JG .not_zero
	RET

.not_zero:
	MOV rcx, rsi
	MOV rax, 0
	REP stosb
	RET
	