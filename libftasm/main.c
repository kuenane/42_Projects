/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 16:52:39 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/05 09:40:41 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm.h"
#include <stdio.h>

int		main(void)
{
	printf("ft_isdigit:\n");
	printf("1) 0 => %d\n", ft_isdigit('0' - 1));
	printf("2) 1 => %d\n", ft_isdigit('0'));
	printf("3) 1 => %d\n", ft_isdigit('9'));
	printf("4) 0 => %d\n", ft_isdigit('9' + 1));

	printf("\nft_isalpha:\n");
	printf("1) 1 => %d\n", ft_isalpha('A'));
	printf("2) 1 => %d\n", ft_isalpha('Z'));
	printf("3) 0 => %d\n", ft_isalpha('A' - 1));
	printf("4) 0 => %d\n", ft_isalpha('Z' + 1));
	printf("5) 1 => %d\n", ft_isalpha('a'));
	printf("6) 1 => %d\n", ft_isalpha('z'));
	printf("7) 0 => %d\n", ft_isalpha('a' - 1));
	printf("8) 0 => %d\n", ft_isalpha('z' + 1));

	printf("\nft_isalnum:\n");
	printf("1) 0 => %d\n", ft_isalnum('0' - 1));
	printf("2) 1 => %d\n", ft_isalnum('0'));
	printf("3) 1 => %d\n", ft_isalnum('9'));
	printf("4) 0 => %d\n", ft_isalnum('9' + 1));
	printf("5) 0 => %d\n", ft_isalnum('A' - 1));
	printf("6) 1 => %d\n", ft_isalnum('A'));
	printf("7) 1 => %d\n", ft_isalnum('Z'));
	printf("8) 0 => %d\n", ft_isalnum('Z' + 1));
	printf("9) 0 => %d\n", ft_isalnum('a' - 1));
	printf("10) 1 => %d\n", ft_isalnum('a'));
	printf("11) 1 => %d\n", ft_isalnum('z'));
	printf("12) 0 => %d\n", ft_isalnum('z' + 1));

	printf("\nft_isascii:\n");
	printf("1) 0 => %d\n", ft_isascii(-1));
	printf("2) 1 => %d\n", ft_isascii(0));
	printf("3) 1 => %d\n", ft_isascii(127));
	printf("4) 0 => %d\n", ft_isascii(128));

	printf("\nft_isprint:\n");
	printf("1) 0 => %d\n", ft_isprint(31));
	printf("2) 1 => %d\n", ft_isprint(32));
	printf("3) 1 => %d\n", ft_isprint(126));
	printf("4) 0 => %d\n", ft_isprint(127));

	printf("\nft_toupper:\n");
	printf("1) ` => %c\n", ft_toupper('`'));
	printf("2) A => %c\n", ft_toupper('a'));
	printf("3) Z => %c\n", ft_toupper('z'));
	printf("4) { => %c\n", ft_toupper('{'));

	printf("\nft_tolower:\n");
	printf("1) @ => %c\n", ft_tolower('@'));
	printf("2) a => %c\n", ft_tolower('A'));
	printf("3) z => %c\n", ft_tolower('Z'));
	printf("4) [ => %c\n", ft_tolower('['));

	printf("\nft_putchar:\n");
	ft_putchar('a');
	printf(" => a\n");
	ft_putchar('0');
	printf(" => 0\n");
	ft_putchar('@');
	printf(" => @\n");

	printf("\nft_putnchar:\n");
	ft_putnchar("a", 1);
	printf(" => a\n");
	ft_putnchar("allo", 4);
	printf(" => allo\n");

	printf("\nft_putchar_fd:\n");
	ft_putchar_fd('a', 1);
	printf(" => a\n");
	ft_putchar_fd('0', 1);
	printf(" => 0\n");
	ft_putchar_fd('@', 1);
	printf(" => @\n");

	printf("\nft_strlen:\n");
	printf("1) 0 => %d\n", ft_strlen(""));
	printf("2) 1 => %d\n", ft_strlen("a"));
	printf("3) 5 => %d\n", ft_strlen("aaaaa"));
	printf("4) 10 => %d\n", ft_strlen("aaaaaaaaaa"));

	printf("\nft_puts:\n");
	puts("a");
	ft_puts("a");
	puts(NULL);
	ft_puts(NULL);
	puts("$#@#',./,~!@~=+");
	ft_puts("$#@#',./,~!@~=+");

	printf("\nft_puts_fd:\n");
	puts("a");
	ft_puts_fd("a", 1);
	puts(NULL);
	ft_puts_fd(NULL, 1);
	puts("$#@#',./,~!@~=+");
	ft_puts_fd("$#@#',./,~!@~=+", 1);

	printf("\nft_putstr:\n");
	ft_putstr("a");
	puts(" => a");
	ft_putstr(NULL);
	ft_putstr(" => ");
	puts(NULL);
	ft_putstr("$#@#',./,~!@~=+");
	puts(" => $#@#',./,~!@~=+");

	printf("\nft_putstr_fd:\n");
	ft_putstr_fd("a", 1);
	puts(" => a");
	ft_putstr_fd(NULL, 1);
	ft_putstr_fd(" => ", 1);
	puts(NULL);
	ft_putstr_fd("$#@#',./,~!@~=+", 1);
	puts(" => $#@#',./,~!@~=+");

	printf("\nft_bzero:\n");
	char s1[] = "aallo";
	ft_bzero((void*)&s1[0], 0);
	printf("aallo => %c%c%c%c%c\n", s1[0], s1[1], s1[2], s1[3], s1[4]);
	ft_bzero((void*)&s1[0], 1);
	printf("allo => %c%c%c%c%c\n", s1[0], s1[1], s1[2], s1[3], s1[4]);
	ft_bzero((void*)&s1[0], 4);
	printf("o => %c%c%c%c%c\n", s1[0], s1[1], s1[2], s1[3], s1[4]);

	printf("\nft_memcpy:\n");
	char memcpy1[2];
	char memcpy2[5];
	memcpy1[1] = '\0';
	memcpy2[4] = '\0';
	ft_memcpy((void*)memcpy1, (void*)"a", 1);
	ft_memcpy((void*)memcpy2, (void*)"allo", 4);
	printf("a => %s\n", memcpy1);
	printf("allo => %s\n", memcpy2);

	printf("\nft_memalloc:\n");
	char *memal1;
	char *memal2;
	memal1 = ft_memalloc(2);
	memal1[0] = 'a';
	memal1[1] = '\0';
	printf("a => %s\n", memal1);

	printf("\nft_strnew:\n");
	char *strnew1;
	strnew1 = ft_strnew(1);
	strnew1[0] = 'a';
	strnew1[1] = '\0';
	printf("a => %s\n", strnew1);

	printf("\nft_strdup:\n");
	char *new;
	char dup1[] = "a";
	char dup2[] = "allo";
	char dup3[] = "";
	new = ft_strdup(dup1);
	printf("a => %s\n", new);
	new = ft_strdup(dup2);
	printf("%s => %s\n", dup2, new);
	new = ft_strdup(dup3);
	printf(" => %s\n", new);

	printf("\nft_strcat:\n");
	char str1[5];
	str1[0] = '\0';
	printf(" => %s\n", ft_strcat(str1, ""));
	printf("a => %s\n", ft_strcat(str1, "a"));
	printf("allo => %s\n", ft_strcat(str1, "llo"));
	printf("allo => %s\n", ft_strcat(str1, ""));

	printf("\nft_memset:\n");
	printf("Abcd => %s\n", ft_memset(ft_strdup("abcd"), 'A', 1));

/*	#include <fcntl.h>
	int fd = open("42", O_RDONLY);
	ft_cat(fd);
	close(fd);*/
}
