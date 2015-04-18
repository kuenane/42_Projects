;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/02 09:14:17 by wide-aze          #+#    #+#              ;
;    Updated: 2015/02/05 08:47:38 by wide-aze         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global	ft_isalnum

ft_isalnum:
	CMP rdi, '0'
	JL .false
	CMP rdi, '9'
	JG .isnt_digit
	MOV rax, 1
	RET

.isnt_digit:
	CMP rdi, 'A'
	JL .false
	CMP rdi, 'Z'
	JG .isnt_up
	MOV rax, 1
	RET

.isnt_up:
	CMP rdi, 'a'
	JL .false
	CMP rdi, 'z'
	JG .false
	MOV rax, 1
	RET
	
.false:
	MOV rax, 0
	RET
