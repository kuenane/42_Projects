;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/31 19:15:55 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:47:31 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global	ft_isalpha

ft_isalpha:
	CMP rdi, 'Z'
	JG .islower
	CMP rdi, 'A'
	JL .false
	MOV rax, 1
	RET
	
.islower:
	CMP rdi, 'a'
	JL .false
	CMP rdi, 'z'
	JG .false
	MOV rax, 1
	RET

.false:
	MOV rax, 0
	RET
