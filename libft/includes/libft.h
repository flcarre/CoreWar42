/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:20:26 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/01 02:20:26 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <float.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdbool.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

int						isnan(long double nb);
int						isinf(long double nb);
int						ft_abs(intmax_t nb);
int						ft_max(intmax_t a, intmax_t b);
int						ft_min(intmax_t a, intmax_t b);
int						ft_minint(int a, int b);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isnumber(char *s);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_islower(int c);
int						ft_isupper(int c);
int						ft_isblank(int c);
int						ft_charinset(char c, const char *charset); // Peut etre modifier
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_iswhitespace(int c);
double					ft_sqrt(double nb);
double					ft_pow(double nb, int pow);
int						ft_str_is_alpha(char *str);
int						ft_str_is_lowercase(char *str);
int						ft_str_is_uppercase(char *str);
int						ft_recursive_factorial(int nb);
long long				ft_atoll(char *s);
int						ft_atoi_base(char *str, char *base);
char					*ft_lltoa_base(uintmax_t n, intmax_t base);
int						ft_sizeofint(int n);
int						ft_isint(char *s);
int						ft_strfind(char *str, char c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_strspn(const char *s, const char *charset);
int						ft_strcspn(const char *s, const char *charset);
int						ft_strchrindex(const char *str, char c);
int						ft_nbrlen(uintmax_t nb, intmax_t base);
size_t					ft_strlen(const char *s);
size_t					w_charlen(wint_t wc);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
size_t					ft_cntdigit(int n);
size_t					ft_isbase(char c, char *base);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strdup(const char *s1);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strnstr(const char *big, const char *little,
									size_t len);
char					*ft_strnew(size_t size);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
									char (*f)(unsigned int, char));
char					*ft_strsub(char const *s, unsigned int start,
									size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					*ft_itoa(int n);
char					*ft_itoa_base(int value, int base);
char					*ft_convert_base(char *nbr, char *base_from,
										char *base_to);
char					*ft_strcapitalize(char *str);
char					*get_wchar(wint_t wc);
char					*str_toupper(char *str);
char					**ft_strsplit(char const *s, char c);
void					ft_strclr(char *s);
void					ft_strdel(char **as);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putstr(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_base(int nbr, char *base);
void					ft_puthexa(unsigned int nbr);
void					ft_putwchar_fd(wchar_t wc, int fd);
void					ft_putwchar(wchar_t wc);
void					print_bits(unsigned char octet);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst,
									void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
/*
**int					ft_list_size(t_list *begin_list);
**void					ft_list_push_front(t_list **begin_list, void *data);
**void					ft_list_push_back(t_list **begin_list, void *data);
**t_list				*ft_create_elem(void *data);
*/
void					ft_bzero(void *s, size_t n);
void					ft_memdel(void **ap);
void					*ft_memalloc(size_t size);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memccpy(void *dest, const void *src, int c,
									size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					*palloc(size_t size);

int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					ft_lstdelfirst(t_list **alst);
void					ft_lstaddend(t_list **alst, t_list *new);
size_t					ft_strlen(const char *str);
size_t					ft_wstrlen(wchar_t *s);
size_t					w_charlen(wint_t wc);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					ft_bzero(void *s, size_t n);
void					ft_putstr_fd(char const *s, int fd);
char					*ft_strcpy(char *dest, const char *src);
char					*to_upper(char *str);
char					*get_wchar(wint_t wc);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_isdigit(int c);
int						find_char(char *str, char c);
int						find_conv(char *str, char c);
int						isnan(long double nb);
int						isinf(long double nb);
int						ft_abs(intmax_t nb);
int						ft_max(intmax_t a, intmax_t b);
int						ft_min(intmax_t a, intmax_t b);
intmax_t				ft_atoi(char *s);
size_t					ft_wordcount(const char *s, char c);
size_t					ft_wordlen(const char *s, char c);
int						ft_isspace(int c);
int						ft_count_word(char *str, char c);
void					ft_insertion_sort(int *arr, int n);

#endif
