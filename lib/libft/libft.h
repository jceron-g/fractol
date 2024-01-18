/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:33:20 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/16 09:48:23 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief The atoi() function converts the initial portion of the string 
 * pointed to by str to int representation.
 * 
 * @param str 
 * @return int 
 */
int		ft_atoi(const char *str);
/**
 * @brief The bzero() function writes n zeroed bytes to the string s.
 * If n is zero, bzero() does nothing.
 * 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief The calloc() function contiguously allocates 
 * enough space for count objects that are size bytes 
 * of memory each and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero.
 * 
 * @param count 
 * @param size 
 * @return return a pointer to allocated memory
 */
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
/**
 * @brief Using malloc(3), creates a string that represent the integer
 * value received as argument. Negative numbers must be taken in 
 * consideration
 * 
 * @param n 
 * @return The representing string of the number or NULL if 
 * memory reservation fails. 
 */
char	*ft_itoa(int n);
/**
 * @brief The memset() function writes len bytes of value c 
 * (converted to an unsigned char) to the string b.
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return it first argument
 */
void	*ft_memset(void *b, int c, size_t len);
/**
 * @brief The memcpy() function copies n bytes from memory 
 * area src to memory area dst. If dst and src overlap, 
 * behavior is undefined. Applications in which dst and 
 * src might overlap should usememmove(3) instead.
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return original value of dst
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return The original value of dst 
 */
void	*ft_memmove(void *dst, const void *src, size_t len);
/**
 * @brief The memchr() function locates the first occurrence of c 
 * (converted to an unsigned char) in string s.
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return Returns a pointer to the byte located, 
 * or NULL if no such byte exists within n bytes
 */
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief The memcmp() function compares byte string s1 against byte string s2. 
 * Both strings are assumed to be n bytes long.
 * @param s1 
 * @param s2 
 * @param n 
 * @return The memcmp() function returns zero if the two strings are identical, 
 * otherwise returns the difference between the first two differing bytes 
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief Send the character 'c' to the specified file descriptor
 * 
 * @param c 
 * @param fd 
 */
void	ft_putchar_fd(char c, int fd);
/**
 * @brief  Send the string 's' to the given file descriptor
 * followed by a line break.
 * @param s 
 * @param fd 
 */
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief Send the number 'n' to the given file descriptor
 * 
 * @param n 
 * @param fd 
 */
void	ft_putnbr_fd(int n, int fd);
/**
 * @brief Send the string 's' to the specified file descriptor.
 * 
 * @param s 
 * @param fd 
 */
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
/**
 * @brief The strdup() function allocates sufficient memory
 * for a copy of the string s1, does the copy, and
 * returns a pointer to it.  The pointer may subsequently 
 * be used as an argument to the function free(3).
 * 
 * @param s1 
 * @return Returns a pointer to the
 * duplicated string. It returns NULL 
 * if insufficient memory was available. 
 */
char	*ft_strdup(const char *s1);
/**
 * @brief @brief The strchr() function locates the first occurrence of c 
 * (converted to a char) in the string pointed to by s. The terminating 
 * null character is considered to be part of the string; therefore if c 
 * is '\0', the functions locate the terminating '\0'.
 * 
 * @param s 
 * @param c 
 * @return Return a pointer to the located character, or NULL
 * if the character does not appear in the string. 
 */
char	*ft_strchr(const char *s, int c);
/**
 * @brief The strlcat() function appends string src 
 * to the end of dst.It will append at most 
 * dstsize - strlen(dst) - 1 characters.
 * It will then NUL-terminate, unless dstsize is 0 
 * or the original dst string was longer than dstsize.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return Returns the initial length of dst 
 * plus the length of src. 
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/**
 * @brief  The strlcpy() function copies up to 
 * dstsize - 1 characters from the string src to dst, 
 * NUL-terminating the result if dstsize is not 0.
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return Returns the lenght of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/**
 * @brief A cada carácter de la string 's', aplica la función
 * 'f' dando como parámetros el índice de cada
 * carácter dentro de 's' y la dirección del propio
 * carácter, que podrá modificarse si es necesario.
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief A cada carácter de la string ’s’, aplica la función 'f' dando como 
 * parámetros el índice de cada carácter dentro de ’s’ y el propio carácter. 
 * Genera una nueva string con el resultado del uso sucesivo de 'f'
 * 
 * 
 * @param s 
 * @param f 
 * @return The created string after the correct use of 'f'
 * on each character. Char *.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief Reserve (with malloc(3)) and returns a new string
 * made by the concatenation of 's1' and 's2'
 * @param s1 
 * @param s2 
 * @return Returns the new string or NULL if memory reservation
 * fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief The strlen() function computes the length of the
 * string s.  The strnlen() function attempts to compute 
 * the length of s, but never scans beyond the first maxlen bytes of s.
 * 
 * @param str 
 * @return returns the number of characters that 
 * precede the terminating NUL character.
 */
size_t	ft_strlen(const char *str);
/**
 * @brief The strncmp() function compares not more than n
 * characters.  Because strncmp() is designed for
 * comparing strings rather than binary data, characters 
 * that appear after a `\0' character are not compared.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return The strcmp() and strncmp() functions return an
 * integer greater than, equal to, or less than 0,
 * according as the string s1 is greater than, equal
 * to, or less than the string s2. 
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief The strnstr() function locates the first occurrence 
 * of the null-terminated string needle in the string haystack, 
 * where not more than len characters are searched. Characters 
 * that appear after a '\0' character are not searched.
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return If needle is an empty string, haystack is returned; 
 * if needle occurs nowhere in haystack, NULL is returned; 
 * otherwise a pointer to the first character of the first 
 * occurrence of needle is returned. 
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/**
 * @brief The strrchr() function locates the last occurrence
 * of c (converted to a char) in the string pointed
 * to by s. The terminating null character is considered 
 * to be part of the string; therefore if c is '\0', 
 * the functions locate the terminating'\0'.
 * 
 * @param s 
 * @param c 
 * @return Returns a pointer to the located character,
 * or NULL if the character does not appear in the string. 
 */
char	*ft_strrchr(const char *s, int c);
/**
 * @brief Delete all characters from string 'set' from the 
 * begining until the end of 's1', until finding a character that
 * doesn't belong to 'set'.
 * 
 * @param s1 
 * @param set 
 * @return The string trimmed or NULL if memory reservation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);
/**
 * @brief Reserve (with malloc(3)) and returns a substring of
 * main string 's'. The substring begins from index 'start' and
 * has a max lenght of 'len'.
 * @param s 
 * @param start 
 * @param len 
 * @return Returns the final substring or NULL if
 * memory reservation fails. 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
/**
 * @brief Creates a new node using malloc(3).
 * 
 * @param content 
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content);
/**
 * @brief Counts the number of nodes in a list.
 * 
 * @param lst 
 * @return int 
 */
int		ft_lstsize(t_list *lst);
/**
 * @brief Adds the node 'new' at the beggining of the list 'lst'
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Adds the node 'new' at the end of the list 'lst'
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Returns the last node of the list
 * 
 * @param lst 
 * @return t_list* 
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief Take as a parameter a node 'lst' and frees the content
 * using the function 'del' given as a parameter.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief Deletes and frees the node 'lst' given and all 
 * the consecutives of that node, using 'del' function and free.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));
/**
 * @brief Iterates list 'lst' and applies the function 'f'
 * in the content of each node.
 * 
 * @param lst 
 * @param f 
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Iterates the list 'lst' and applies the function
 * 'f' to the content of each node. Creates a list resulting
 * of the correct and successive application of the function 'f'
 * on each node. The function 'del' is used to remove the contents
 * of a node if necessary.
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *aux_line);
char	*ft_get_line(char *aux_line);
char	*ft_clean_line(char *aux_line);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *aux_line, char *buffer, int read_bytes);
int		ft_strlen_gnl(char *str);
void	*ft_calloc_gnl(size_t count, size_t size);
int		ft_putchar(char c);
int		ft_putstr(char *string);
int		ft_printf(const char *format, ...);
int		ft_putdec(int number);
int		ft_puthex(unsigned long i, char c);
int		ft_printuint(unsigned int number);

#endif