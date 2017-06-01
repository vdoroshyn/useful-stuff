#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define UNSTR() printf(ANSI_COLOR_RED "! This test is unstrict.\n" ANSI_COLOR_RESET);
#define ISEQUAL(x) (x != 0) ? 0 : 1
#define STPRINT(x) printf(ANSI_COLOR_BLUE "\n---" ANSI_COLOR_RESET "%s" ANSI_COLOR_BLUE "---\n" ANSI_COLOR_RESET, x)

void	ENPRINT(char *str)
{
    int		i;
    char	*fin;
    
    i = strlen(str);
    fin = malloc(i);
    fin = (char *)memset((void*)fin, '-', i);
    printf(ANSI_COLOR_BLUE "\n---%s---\n" ANSI_COLOR_RESET, fin);
}

void	ft_memalloc_test(void)
{
    STPRINT("ft_memalloc");
    
    char	*s;
    
    s = (char *)ft_memalloc(6);
    for	(int c = 0; c < 5; c++)
    {
        s[c] = '0';
    }
    if (s[4] == '0' && s[5] == 0)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n-----------------\n" ANSI_COLOR_RESET);
}

void	ft_memcmp_test(void)
{
    STPRINT("ft_memcmp");
    char	*str = "0921\200";
    char	*str2 = "0921\0";
    
    printf(ANSI_COLOR_YELLOW "Expected: %i\n" ANSI_COLOR_CYAN "Program:  %i" ANSI_COLOR_RESET, memcmp((void*)str, (void*)str2, 5), ft_memcmp((void*)str, (void*)str2, 5));
    printf(ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET);
}

void	ft_memset_test(void)
{
    STPRINT("ft_memset");
    char	*str;
    char	*str2;
    
    str = malloc(10);
    str2 = malloc(10);
    str[9] = 0;
    str2[9] = 0;
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_CYAN "Program:  %s" ANSI_COLOR_RESET, (char*)memset((void*)str, 48, 9), (char*)ft_memset((void*)str2, 48, 9));
    printf(ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET);
}

void	ft_bzero_test(void)
{
    char	*str;
    int		i;
    
    STPRINT("ft_bzero");
    str = malloc(6);
    for (int c = 0; c < 5; c++)
        str[c] = '1';
    i = 0;
    ft_bzero(str, 5);
    while (i < 5)
    {
        if (str[i] == 0)
        {
            i++;
            continue ;
        }
        printf(ANSI_COLOR_RED "Oops...\n%c is pretended to be 0, but... Aborting test.\n" ANSI_COLOR_RESET, str[i]);
        break ;
    }
    if (i == 5)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n--------------\n" ANSI_COLOR_RESET);
}

void	ft_isalnum_test(void)
{
    int		i;
    
    STPRINT("ft_isalnum");
    i = -200;
    while (i < 500)
    {
        if (isalnum(i) != ft_isalnum(i))
        {
            printf(ANSI_COLOR_RED "Ops...\n" ANSI_COLOR_RESET);
            break ;
        }
        i++;
    }
    if (i == 500)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n----------------\n" ANSI_COLOR_RESET);
}

void	ft_isalpha_test(void)
{
    int		i;
    
    STPRINT("ft_isalpha");
    i = -200;
    while (i < 500)
    {
        if (isalpha(i) != ft_isalpha(i))
        {
            printf(ANSI_COLOR_RED "Ops...\n" ANSI_COLOR_RESET);
            break ;
        }
        i++;
    }
    if (i == 500)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n----------------\n" ANSI_COLOR_RESET);
}

void	ft_isascii_test(void)
{
    int		i;
    
    STPRINT("ft_isascii");
    i = -200;
    while (i < 500)
    {
        if (isascii(i) != ft_isascii(i))
        {
            printf(ANSI_COLOR_RED "Ops...\n" ANSI_COLOR_RESET);
            break ;
        }
        i++;
    }
    if (i == 500)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n----------------\n" ANSI_COLOR_RESET);
    
}

void	ft_isdigit_test(void)
{
    int		i;
    
    STPRINT("ft_isdigit");
    i = -200;
    while (i < 500)
    {
        if (isdigit(i) != ft_isdigit(i))
        {
            printf(ANSI_COLOR_RED "Ops...\n" ANSI_COLOR_RESET);
            break ;
        }
        i++;
    }
    if (i == 500)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n----------------\n" ANSI_COLOR_RESET);
}

void	ft_isprint_test(void)
{
    int		i;
    
    STPRINT("ft_isprint");
    i = -200;
    while (i < 500)
    {
        if (isprint(i) != ft_isprint(i))
        {
            printf(ANSI_COLOR_RED "Ops...\n" ANSI_COLOR_RESET);
            break ;
        }
        i++;
    }
    if (i == 500)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n----------------\n" ANSI_COLOR_RESET);
}

void	ft_toupper_test(void)
{
    STPRINT("ft_toupper");
    int		i;
    
    i = -200;
    
    while (i < 500)
    {
        if (ft_toupper(i) != toupper(i))
        {
            printf(ANSI_COLOR_RED "\nFAIL on %i\n" ANSI_COLOR_RESET, i);
            break ;
        }
        i++;
    }
    if (i == 500)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n----------------\n" ANSI_COLOR_RESET);
}

void	ft_tolower_test(void)
{
    STPRINT("ft_tolower");
    int		i;
    
    i = -200;
    
    while (i < 500)
    {
        if (ft_tolower(i) != tolower(i))
        {
            printf(ANSI_COLOR_RED "\nFAIL on %i\n" ANSI_COLOR_RESET, i);
            break ;
        }
        i++;
    }
    if (i == 500)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n----------------\n" ANSI_COLOR_RESET);
}

void	ft_putnbr_test(int nb)
{
    STPRINT("ft_putnbr");
    printf(ANSI_COLOR_YELLOW "Expected: %i\n" ANSI_COLOR_RESET ANSI_COLOR_CYAN "Program:  ", nb);
    fflush(stdout);
    ft_putnbr(nb);
    printf(ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET);
}

void	ft_putendl_test(char *str)
{
    STPRINT("ft_putendl");
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_RESET ANSI_COLOR_CYAN "Program:  ", str);
    fflush(stdout);
    ft_putendl(str);
    printf(ANSI_COLOR_BLUE "----------------\n" ANSI_COLOR_RESET);
}

void	ft_strcpy_test(const char *src)
{
    char	*dst;
    char	*desttest;
    
    dst = malloc(1);
    desttest = malloc(1);
    strcpy(desttest, src);
    ft_strcpy(dst, src);
    STPRINT("ft_strcpy");
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_RESET ANSI_COLOR_CYAN "Program:  %s" ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET, desttest, dst);
}

void	ft_strncpy_test(const char *src, int len)
{
    char	*dst;
    char	*desttest;
    int		i;
    
    dst = malloc(10);
    desttest = malloc(10);
    strncpy(dst, src, len);
    ft_strncpy(desttest, src, len);
    STPRINT("ft_strncpy");
    fflush(stdout);
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_RESET ANSI_COLOR_CYAN "Program:  %s\n", dst, desttest);
    fflush(stdout);
    if ((unsigned long)len > strlen(src))
    {
        i = strlen(src);
        while (i < len)
        {
            if (dst[i] == '\0' && desttest[i] != '\0')
            {
                printf(ANSI_COLOR_RED "\n#!Terminator failure\n" ANSI_COLOR_RESET);
                fflush(stdout);
            }
            i++;
        }
    }
    printf(ANSI_COLOR_BLUE "----------------\n" ANSI_COLOR_RESET);
    fflush(stdout);
    
}

void	ft_strdup_test(void)
{
    STPRINT("ft_strdup");
    char const	*stest = "\200123qwe";
    
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_CYAN "Program:  %s", strdup(stest), ft_strdup(stest));
    printf(ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET);
}

void	ft_memcpy_test(size_t len)
{
    void	*ptr;
    void	*ptr2;
    int		i;
    
    i = 511;
    ptr = malloc(10);
    ptr2 = malloc(10);
    ft_memcpy(ptr, (void*)&i, len);
    memcpy(ptr2, (void*)&i, len);
    STPRINT("ft_memcpy");
    printf(ANSI_COLOR_YELLOW "Expected: %i\n" ANSI_COLOR_RESET ANSI_COLOR_CYAN "Program:  %i" ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET, *((int*)ptr2), *((int*)ptr));
}

void	ft_strlen_test()
{
    STPRINT("ft_strlen");
    char	*str = "123\200";
    
    printf(ANSI_COLOR_YELLOW "Expected: %lu\n" ANSI_COLOR_CYAN "Program:  %lu", strlen(str), ft_strlen(str));
    printf(ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET);
}

void	ft_memccpy_test(int c)
{
    void	*ptr;
    void	*ptr2;
    char	*str;
    void	*tst;
    void	*tst2;
    int		i;
    int		j;
    
    str = malloc(29);
    str	= "abcdefghijklmnopqrstuvwxyz";
    ptr = (void *)malloc(29);
    ptr2 = (void *)malloc(29);
    i = 122;
    j = 0;
    while (i != 96)
    {
        ((char *)ptr)[j] = (char)i;
        ((char *)ptr2)[j] = (char)i;
        i--;
        j++;
    }
    STPRINT("ft_memccpy");
    tst = malloc(30);
    tst2 = malloc(30);
    tst = memccpy(ptr, str, c, 30);
    tst2 = ft_memccpy(ptr2, str, c, 30);
    printf(ANSI_COLOR_YELLOW "Expected: %s\n          %s\n" ANSI_COLOR_RESET, ptr, (char *)tst);
    fflush(stdout);
    printf(ANSI_COLOR_CYAN "Program:  %s\n          %s\n" ANSI_COLOR_RESET, ptr2, (char *)tst2);
    fflush(stdout);
    printf(ANSI_COLOR_BLUE "----------------\n" ANSI_COLOR_RESET);
}

void	ft_memmove_test(void)
{
    STPRINT("ft_memmove");
    char	*s1;
    char	*s2;
    int		i;
    
    s1 = (char*)malloc(20);
    s2 = (char*)malloc(20);
    i = 0;
    while (i < 10)
    {
        s1[i] = i + 48;
        s2[i] = i + 48;
        i++;
    }
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_CYAN "Program:  %s", (char*)memmove((void*)s1, (void*)(s1 + 3), 3), (char*)ft_memmove((void*)s2, (void*)(s2 + 3), 3));
    printf(ANSI_COLOR_BLUE "\n----------------\n");
}

void	ft_memchr_test(void)
{
    STPRINT("ft_memchr");
    char	*s1 = "1234567890";
    char	*s2 = "1234567890";
    
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_CYAN "Program:  %s\n" ANSI_COLOR_RESET, (char *)memchr(s1, (int)'5', 10), (char *)ft_memchr(s2, (int)'5', 10));
    printf(ANSI_COLOR_BLUE "\n--------------\n" ANSI_COLOR_RESET);
}


void	ft_strcat_test(const char *s2)
{
    char	*s1;
    char	*s1test;
    int		i;
    
    i = 0;
    s1 = malloc(10);
    s1test = malloc(10);
    while (i < 3)
    {
        s1[i] = '-';
        s1test[i] = '-';
        i++;
    }
    STPRINT("ft_strcat");
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_RESET ANSI_COLOR_CYAN "Program:  %s" ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET, strcat(s1, s2), ft_strcat(s1test, s2));
}

void	ft_strncat_test(const char *s2, size_t n)
{
    char	*s1;
    char	*s1test;
    int		i;
    
    i = 0;
    s1 = malloc(10);
    s1test = malloc(10);
    while (i < 3)
    {
        s1[i] = '-';
        s1test[i] = '-';
        i++;
    }
    STPRINT("ft_strncat");
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_CYAN "Program:  %s\n" ANSI_COLOR_BLUE "-------------\n" ANSI_COLOR_RESET, strncat(s1, s2, n), ft_strncat(s1, s2, n));
}

void	ft_strlcat_test(void)
{
    char	s1[10] = "vi";
    char	*s2 = "1234567890";
    char	s3[10] = "vi";
    char	*s4 = "1234567890";
    
    STPRINT("ft_strlcat");
    printf(ANSI_COLOR_YELLOW "Expected length: %lu\nExpected strings: %s\n                  %s\n\n" ANSI_COLOR_CYAN "Program length:  %lu\nProgram strings:  %s\n                  %s\n", strlcat(s3, s4, 8), s3, s4, ft_strlcat(s1, s2, 8), s1, s2);
    fflush(stdout);
    printf(ANSI_COLOR_BLUE "----------------\n" ANSI_COLOR_RESET);
    fflush(stdout);
}

void	ft_strchr_test(int c)
{
    STPRINT("ft_strchr");
    char	s1[28] = "abcdeffghijklmnopqrstuvwxyz";
    char	s2[28] = "abcdeffghijklmnopqrstuvwxyz";
    printf(ANSI_COLOR_YELLOW "Expected: %s\n", strchr(s1, c));
    fflush(stdout);
    printf(ANSI_COLOR_CYAN "Program:  %s\n" ANSI_COLOR_RESET, ft_strchr(s2, c));
    fflush(stdout);
    printf(ANSI_COLOR_BLUE "---------------\n" ANSI_COLOR_RESET);
}

void	ft_strrchr_test(int c)
{
    STPRINT("ft_strrchr");
    char	s1[28] = "abcdeffghijklmnopqrstuvwxyz";
    char	s2[28] = "abcdeffghijklmnopqrstuvwxyz";
    printf(ANSI_COLOR_YELLOW "Expected: %s\n", strrchr(s1, c));
    fflush(stdout);
    printf(ANSI_COLOR_CYAN "Program:  %s\n" ANSI_COLOR_RESET, ft_strrchr(s2, c));
    fflush(stdout);
    printf(ANSI_COLOR_BLUE "----------------\n" ANSI_COLOR_RESET);
}

void	ft_strstr_test(void)
{
    char	i[10] = "123456789";
    char	j[3] = "45";
    
    STPRINT("ft_strstr");
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_CYAN "Program:  %s\n", strstr(i, j), ft_strstr(i, j));
    fflush(stdout);
    printf(ANSI_COLOR_BLUE "---------------\n" ANSI_COLOR_RESET);
}

void	ft_strnstr_test(void)
{
    char	s1[10] = "123456789";
    char	s2[3] = "45";
    
    STPRINT("ft_strnstr");
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_CYAN "Program:  %s\n", strnstr(s1, s2, 4), ft_strnstr(s1, s2, 4));
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_CYAN "Program:  %s\n", strnstr(s1, s2, 6), ft_strnstr(s1, s2, 6));
    fflush(stdout);
    printf(ANSI_COLOR_BLUE "----------------\n" ANSI_COLOR_RESET);
}

void	ft_strcmp_test(void)
{
    char	s1[10] = "111sAd";
    char	s2[10] = "111sad";
    
    STPRINT("ft_strcmp");
    printf(ANSI_COLOR_YELLOW "Expected: %i\n" ANSI_COLOR_CYAN "Program:  %i\n", strcmp(s1, s2), ft_strcmp(s1, s2));
    fflush(stdout);
    printf(ANSI_COLOR_BLUE "---------------\n" ANSI_COLOR_RESET);
}

void	ft_strncmp_test(void)
{
    char	s1[10] = "111sAd";
    char	s2[10] = "111sad";
    
    STPRINT("ft_strncmp");
    printf(ANSI_COLOR_YELLOW "Expected: %i\n" ANSI_COLOR_CYAN "Program:  %i\n", strncmp(s1, s2, 4), ft_strncmp(s1, s2, 4));
    fflush(stdout);
    printf(ANSI_COLOR_BLUE "----------------\n" ANSI_COLOR_RESET);
}

void	ft_atoi_test(void)
{
    char	*s2 = strdup("   25");
    
    s2[1] = (char)28;
    STPRINT("ft_atoi");
    printf(ANSI_COLOR_YELLOW "Expected: \n");
    printf("1:%d\n", atoi("\n\r \t 23"));
    printf("2:%d\n", atoi("\n     23"));
    printf("3:%d\n", atoi("   we 13"));
    printf("4:%d\n", atoi("*13"));
    printf("5:%d\n", atoi("     \n -13"));
    printf("6:%d\n", atoi("+13"));
    printf("7:%d\n", atoi("/13"));
    printf("8:%d\n", atoi("\n\r \r     +13"));
    printf("9:%d\n", atoi("987"));
    printf("10:%d\n", atoi("456"));
    printf("11:%d\n", atoi(s2));
    printf(ANSI_COLOR_CYAN "Program: \n");
    printf("1:%d\n", ft_atoi("\n\r \t 23"));
    printf("2:%d\n", ft_atoi("\n     23"));
    printf("3:%d\n", ft_atoi("   we 13"));
    printf("4:%d\n", ft_atoi("*13"));
    printf("5:%d\n", ft_atoi("     \n -13"));
    printf("6:%d\n", ft_atoi("+13"));
    printf("7:%d\n", ft_atoi("/13"));
    printf("8:%d\n", ft_atoi("\n\r \r     +13"));
    printf("9:%d\n", ft_atoi("987"));
    printf("10:%d\n", ft_atoi("456"));
    printf("11:%d\n", ft_atoi(s2));
    printf(ANSI_COLOR_BLUE "-------------\n" ANSI_COLOR_RESET);
}

void	ft_strequ_test(char const *s1, char const *s2)
{
    STPRINT("ft_strequ");
    printf(ANSI_COLOR_YELLOW "Expected: %i\n", ISEQUAL(strcmp(s1, s2)));
    printf(ANSI_COLOR_CYAN "Program:  %i\n", ft_strequ(s1, s2));
    printf(ANSI_COLOR_BLUE "---------------\n" ANSI_COLOR_RESET);
}

void	ft_strnequ_test(char const *s1, char const *s2, size_t n)
{
    STPRINT("ft_strnequ");
    printf(ANSI_COLOR_YELLOW "Expected: %i\n", ISEQUAL(strncmp(s1, s2, n)));
    printf(ANSI_COLOR_CYAN "Program:  %i\n", ft_strnequ(s1, s2, n));
    printf(ANSI_COLOR_BLUE "----------------\n" ANSI_COLOR_RESET);
}

void	ft_memdel_test(void)
{
    STPRINT("ft_memdel");
    void	*ptr;
    UNSTR();
    ptr = malloc(20);
    ft_memdel(&ptr);
    if (ptr == NULL)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    else
        printf(ANSI_COLOR_RED "\nFAIL\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET);
}

void	ft_strnew_test(void)
{
    STPRINT("ft_strnew");
    char	*ptr;
    int		i;
    
    ptr = ft_strnew(20);
    i = 0;
    while (i < 20)
    {
        if (ptr[i] == 0)
        {
            i++;
            continue;
        }
        else
        {
            printf(ANSI_COLOR_RED "\nFAIL\n" ANSI_COLOR_RESET);
            break ;
        }
    }
    if (i == 20)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n---------------\n" ANSI_COLOR_RESET);
}

void	ft_strdel_test(void)
{
    STPRINT("ft_strdel");
    UNSTR();
    char	*str;
    
    str = malloc(10);
    ft_strdel(&str);
    if (str == NULL)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    else
        printf(ANSI_COLOR_RED "\nFAIL\n" ANSI_COLOR_RESET);
    ENPRINT("ft_strdel");
}

void	ft_strclr_test(void)
{
    STPRINT("ft_strclr");
    char	*str;
    int		i;
    
    i = -1;
    str = malloc(10);
    while (++i < 10)
        str[i] = '1';
    ft_strclr(str);
    i = -1;
    while (++i < 11)
    {
        if (str[i] == 0)
            continue ;
        printf(ANSI_COLOR_RED "\nFAIL\n" ANSI_COLOR_RESET);
        break ;
    }
    if (i == 11)
        printf(ANSI_COLOR_GREEN "\nOK\n" ANSI_COLOR_RESET);
    ENPRINT("ft_strclr");
}

void	func_for_striter(char *s)
{
    *s += 1;
}

void	ft_striter_test(void)
{
    STPRINT("ft_striter");
    char	*str;
    int		i;
    
    str = malloc(10);
    str[9] = 0;
    i = -1;
    while (++i < 9)
        str[i] = '0';
    ft_striter(str, &func_for_striter);
    printf(ANSI_COLOR_YELLOW "Expected: 111111111\n" ANSI_COLOR_CYAN "Program:  %s", str);
    ENPRINT("ft_striter");
}

void	func_for_striteri(unsigned int i, char *s)
{
    *s += i;
}

void	ft_striteri_test(void)
{
    STPRINT("ft_striteri");
    char			*str;
    unsigned int	i;
    
    str = malloc(10);
    str[9] = 0;
    i = -1;
    while (++i < 9)
        str[i] = '0';
    ft_striteri(str, &func_for_striteri);
    printf(ANSI_COLOR_YELLOW "Expected: 012345678\n" ANSI_COLOR_CYAN "Program:  %s", str);
    ENPRINT("ft_striteri");
}

char	func_for_strmap(char s)
{
    return (s + 1);
}

void	ft_strmap_test(void)
{
    STPRINT("ft_strmap");
    char	*str;
    
    str = ft_strmap("000000000", &func_for_strmap);
    printf(ANSI_COLOR_YELLOW "Expected: 111111111\n" ANSI_COLOR_CYAN "Program:  %s", str);
    ENPRINT("ft_strmap");
}

char	func_for_strmapi(unsigned int i, char s)
{
    return (s + i);
}

void	ft_strmapi_test(void)
{
    STPRINT("ft_strmapi");
    char	*str;
    
    str = ft_strmapi("000000000", &func_for_strmapi);
    printf(ANSI_COLOR_YELLOW "Expected: 012345678\n" ANSI_COLOR_CYAN "Program:  %s", str);
    ENPRINT("ft_strmapi");
}

void	ft_strsub_test(void)
{
    STPRINT("ft_strsub");
    char	*str = "nyan cat";
    
    printf(ANSI_COLOR_YELLOW "Expected: cat\n" ANSI_COLOR_CYAN "Program:  %s", ft_strsub(str, 5, 9));
    ENPRINT("ft_strsub");
}

void	ft_strjoin_test(char *s, char *c)
{
    STPRINT("ft_strjoin");
    printf(ANSI_COLOR_YELLOW "Expected: %s%s\n" ANSI_COLOR_CYAN "Program:  %s", s, c, ft_strjoin(s, c));
    ENPRINT("ft_strjoin");
}

void	ft_strtrim_test(void)
{
    STPRINT("ft_strtrim");
    char	*str = "cat \n   \t";
    
    printf(ANSI_COLOR_YELLOW "Expected: cat\n" ANSI_COLOR_CYAN "Program:  %s", ft_strtrim(str));
    ENPRINT("ft_strtrim");
}

void	ft_strsplit_test(void)
{
    STPRINT("ft_strsplit");
    char	**str;
    
    str = ft_strsplit("it\200\200works\200well\200", '\200');
    printf(ANSI_COLOR_YELLOW "Expected: it\n\t  works\n\t  well\n" ANSI_COLOR_CYAN);
    printf("Program:  %s\n\t  %s\n\t  %s", str[0], str[1], str[2]);
    ENPRINT("ft_strsplit");
}

void	ft_itoa_test(int nb)
{
    STPRINT("ft_itoa");
    printf(ANSI_COLOR_YELLOW "Expected: %i\nProgram:  %s", nb, ft_itoa(nb));
    ENPRINT("ft_itoa");
}

void	ft_putchar_test(char c)
{
    STPRINT("ft_putchar");
    printf(ANSI_COLOR_RED "This makes no sense...\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "Expected: %c\n", c);
    fflush(stdout);
    printf(ANSI_COLOR_CYAN "Program:  ");
    fflush(stdout);
    ft_putchar(c);
    ENPRINT("ft_putchar");
}

void	ft_putstr_test(char *str)
{
    STPRINT("ft_putstr");
    printf(ANSI_COLOR_RED "This also makes no sense...\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "Expected: %s\n" ANSI_COLOR_CYAN "Program:  ", str);
    fflush(stdout);
    ft_putstr(str);
    ENPRINT("ft_putstr");
}

void	first_part_test(void)
{
    printf(ANSI_COLOR_GREEN "=================================\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "===== FIRST PART UNIT TESTS =====\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "=================================\n" ANSI_COLOR_RESET);
    ft_memset_test();
    ft_bzero_test();
    ft_memcpy_test(2);
    ft_memcpy_test(1);
    ft_memccpy_test((int)'a');
    ft_memmove_test();
    ft_memchr_test();
    ft_memcmp_test();
    ft_strlen_test();
    ft_strdup_test();
    ft_strcpy_test("loa");
    ft_strncpy_test("hhhhh", 8);
    ft_strcat_test("huh");
    ft_strncat_test("huhuh", 5);
    ft_strlcat_test();
    ft_strchr_test((int)'f');
    ft_strrchr_test((int)'f');
    ft_strstr_test();
    ft_strnstr_test();
    ft_strcmp_test();
    ft_strncmp_test();
    ft_atoi_test();
    ft_isalpha_test();
    ft_isdigit_test();
    ft_isalnum_test();
    ft_isascii_test();
    ft_isprint_test();
    ft_toupper_test();
    ft_tolower_test();
    printf(ANSI_COLOR_GREEN "=================================\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "======= END OF FIRST PART =======\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "=================================\n\n" ANSI_COLOR_RESET);
}

void	second_part_test(void)
{
    printf(ANSI_COLOR_MAGENTA "=================================\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "========== SECOND PART ==========\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "=================================\n" ANSI_COLOR_RESET);
    ft_memalloc_test();
    ft_memdel_test();
    ft_strnew_test();
    ft_strdel_test();
    ft_strclr_test();
    ft_striter_test();
    ft_striteri_test();
    ft_strmap_test();
    ft_strmapi_test();
    ft_strequ_test("hello", "hello");
    ft_strnequ_test("hello", "hellO", 5);
    ft_strsub_test();
    ft_strjoin_test("str1+", "str2");
    ft_strtrim_test();
    ft_strsplit_test();
    ft_itoa_test(-2147483648);
    ft_putchar_test('o');
    ft_putstr_test("123abc");
    ft_putendl_test("ieieieie");
    ft_putnbr_test(-2147483648);
    printf(ANSI_COLOR_RED "\n===For FD functions, write your own tests===\n============= I was too tired. =============\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "=================================\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "========= END OF PART 2 =========\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "=================================\n" ANSI_COLOR_RESET);
}

int		main(void)
{
    first_part_test();
    second_part_test();
    return (0);
}
