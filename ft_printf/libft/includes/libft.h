/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:14:50 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/19 15:27:35 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <inttypes.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl_list
{
	char			buf[33];
	int				fd_save;
	int				i;
}					t_gnl_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strtrim(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*verified_malloc(size_t size);
char				*verified_strnew(size_t size);
char				*verified_strdup(char *str);
char				*verified_strsub(char *str, unsigned int start, size_t len);
char				*verified_strjoin(char *s1, char *s2);
char				*ft_strsub_free(char *str, int start, size_t len);
char				*ft_strjoin_free(char *s1, char const *s2);
char				*ft_strjoin_free_s2(char *s1, char *s2);
int					get_next_line(int const fd, char **line);
char				*ft_itoa_ui(unsigned int n);
char				*ft_itoa_ul(unsigned long n);
char				*ft_itoa_ull(unsigned long long n);
char				*ft_itoa_l(long long n);
char				*ft_itoa_ll(long long n);
char				*ft_itoa_st(size_t n);
char				*ft_itoa_sst(ssize_t n);
char				*ft_itoa_imax(intmax_t n);
char				*ft_itoa_uimax(uintmax_t n);
char				*convert_ui_to_other(unsigned int nb, char *base);
char				*convert_us_to_other(unsigned short nb, char *base);
char				*convert_uc_to_other(unsigned char nb, char *base);
char				*convert_ul_to_other(unsigned long nb, char *base);
char				*convert_ull_to_other(unsigned long long nb, char *base);
char				*convert_st_to_other(size_t nb, char *base);
char				*convert_sst_to_other(ssize_t nb, char *base);
char				*convert_imax_to_other(intmax_t nb, char *base);
char				*convert_uimax_to_other(uintmax_t nb, char *base);
int					ft_wstrlen(wchar_t *wstr);
int					ft_wstr_to_str(char *buff, wchar_t *wstr);
int					ft_wstr_to_nstr(char *buff, wchar_t *wstr, int n);
int					ft_itoa_wchar(char *buff, wchar_t w);

#endif
