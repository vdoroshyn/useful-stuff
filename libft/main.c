/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CreOOated: 2016/11/21 13:15:45 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/11/30 17:43:38 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <fcntl.h>

void    ft_toupperstriter(char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

void    function_striteri(unsigned int index, char *s)
{
    while (s[index] != '\0')
    {
        if (s[index] == 'l')
            s[index] = 't';
        index++;
    }
}

char strmap_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

char    function_strmapi(unsigned int size, char c)
{
    if (c >= 97 && c <= 122)
    {
        c = c + size;
    }
    return (c);
}

int		main(void)
{
	char s = 't';
	int t = '1';
	char x = '/';

//putchar
	ft_putchar(s);
	ft_putchar('\n');

//strlen
	char *str = "hello mofo";
	printf("My strlen: %zu\n", ft_strlen(str));
	printf("Stnd strlen: %zu\n", strlen(str));

//putstr+putendl
	ft_putstr(str);printf("[NO SPACE]");fflush(stdout);
	ft_putendl(str);

//isalpha
	if(isalpha(s) && ft_isalpha(s))
	{
		printf("isalpha: you god damn right\n");
	}
	else
	{
		printf("isalpha: wasted\n");
	}

//isdigit
	if (isdigit('5') && ft_isdigit(x))
	{
		printf("isdigit: it is a digit\n");
	}
	else
	{
		printf("isdigit: wasted\n");
	}

//isalnum
	if (isalnum('5') && ft_isalnum(t))
	{
		ft_putstr("isalnum: it is an alnumeric character\n");
	}
	else
	{
		ft_putstr("isalnum: lmao noob\n");
	}
//isprint
	if (isprint('x') && ft_isprint(127))
	{
		ft_putstr("isprint: roger\n");
	}
	else
	{
		ft_putstr("what a fail\n");
	}
//toupper
	ft_putchar(ft_toupper('5'));
	ft_putchar(ft_toupper('g'));
	ft_putchar(toupper('8'));
	ft_putchar(toupper('G'));
	ft_putchar('\n');
//tolower
	ft_putchar(ft_tolower('F'));
	ft_putchar(ft_tolower('f'));
	ft_putchar(tolower('8'));
	ft_putchar(tolower('D'));
	ft_putchar('\n');

//isascii
	if (ft_isascii(127) && isascii(3))
	{
		printf("isascii: good good\n");
	}
	else
	{
		printf("wasted lmao\n");
	}

//strdup
	char *dest = ft_strdup(str);
	char *deststd = strdup(str);
	printf("source is %s, standard strdup is %s, my strdup is %s\n", str, deststd, dest);

//strcpy
	char strforcpy[15];
	printf("my strcpy: %s \n", ft_strcpy(strforcpy, str));
	printf("stnd strcpy: %s \n", strcpy(strforcpy,str));
	
//strncpy
	char strnforcpy[15] = "hellof";
	char strnforcpy1[15] = "hellof";
	char *ncp = "ku";
	printf("my strncpy: %s \n", ft_strncpy(strnforcpy, ncp, 4));
	printf("stnd strncpy: %s \n", strncpy(strnforcpy1, ncp, 4));
//strchr
	printf("my strchr: %s\n", ft_strchr(str, '\0'));
	printf("std strchr: %s\n", strchr(str, '\0'));
//strrchr
	printf("my strrchr: %s\n", ft_strrchr(str, '\0'));
	printf("std strrchr: %s\n", strrchr(str, '\0'));
//strcmp
	char *cmp1 = "Hello";
	char *cmp2 = "";
	int rat = ft_strcmp(cmp1, cmp2);
	if (rat < 0)
	{
		printf("my strcmp: cmp1 is less than cmp2\n");
	}
	else if (rat > 0)
	{
		printf("my strcmp: cmp2 is less than cmp1\n");
	}
	else
	{
		printf("my strcmp: cmp1 is equal to cmp2\n");
	}
//strncmp
    char *strncm1 = "Hello";
    char *strncm2 = "";
    int ret = ft_strncmp(strncm1, strncm2, 1);
    
    if (ret < 0)
    {
        printf("my strncmp: str1 is less than str2\n");
    }
    else if (ret > 0)
    {
        printf("my strncmp: str2 is less than str1\n");
    }
    else
    {
        printf("mystrncmp: str1 is equal to str2\n");
    }
    
    
    int ret1 = strncmp(strncm1, strncm2, 1);
    
    if (ret1 < 0)
    {
        printf("std strncmp: str1 is less than str2\n");
    }
    else if (ret1 > 0)
    {
        printf("std strncmp: str2 is less than str1\n");
    }
    else
    {
        printf("std strncmp: str1 is equal to str2\n");
    }

//atoi
	char *testatoi = "   	++54545hghgh";
	printf("my atoi: %d\n", ft_atoi(testatoi));
	printf("std atoi: %d\n", atoi(testatoi));
//strstr
	char *strstr1 = "hellomadafakalmao";
	char *strstr2 = "adaf";
	printf("stnd strstr: %s\n", strstr(strstr1, strstr2));
	printf("my strstr: %s\n", ft_strstr(strstr1, strstr2));
//strnstr
	char *strnstr1 = "helhebrakadabhebrura";
    char *strnstr2 = "hebru";
    printf("stnd strnstr: %s\n", strnstr(strnstr1, strnstr2, 18));
    printf("my strnstr: %s\n", ft_strnstr(strnstr1, strnstr2, 18));
//strcat
	char strcat[20] = "hello";
    char *strcat1 = "her";
    char strcat2[20] = "hello";
    char *strcat3 = "her";
    printf("my strcat: %s\n", ft_strcat(strcat, strcat1));
    printf("stnd strcat: %s\n", strcat(strcat2, strcat3));
//strncat
	char strncat[20] = "hello";
    char *strncat1 = "hunda";
    char strncat2[20] = "hello";
    char *strncat3 = "hunda";
    printf("my strncat: %s\n", ft_strncat(strncat, strncat1, 6));
    printf("stnd strncat: %s\n", strncat(strncat2, strncat3, 6));
//putnbr
	int putnbr = -2147483648;
    ft_putnbr(putnbr);
	ft_putchar('\n');
	int putnbr1 = 2147483647;
    ft_putnbr(putnbr1);
	ft_putchar('\n');
//memset
	char memset1[20] = "hello";
	char memset2[20] = "hello";
	void* memn1 = memset(memset1, 'a', 2);
    void* memn2 = ft_memset(memset2, 'a', 2);
    printf("%s\n", memn1);
    printf("%s\n", memn2);
//bzero
	char fuk[] = "hello mofo";
	char fuk1[20] = "hello mofo";
	ft_bzero(fuk, 3);
	printf("my bzero: %s\n", &fuk[3]);
	bzero(fuk1, 3);
	printf("stnd bzero: %s\n", &fuk1[3]);
	printf("my bzero: %s\n", &fuk[0]);
    printf("stnd bzero: %s\n", &fuk1[0]);
//strlcat
	char strlcatdest[50] = "hello";
    char *strlcatsrc = "hi";
    int strlcatsize = strlcat(strlcatdest, strlcatsrc, 7);
    printf("stnd strlcat: %s\n", strlcatdest);
    printf("stnd strlcat: %s\n", strlcatsrc);
    printf("stnd strlcat: %d\n", strlcatsize);

    char strlcattest[50] = "hello";
    char *strlcattest1 = "hi";
    int strlcatsize1 = ft_strlcat(strlcattest, strlcattest1, 7);
    printf("my strlcat: %s\n", strlcattest);
    printf("my strlcat: %s\n", strlcattest1);
    printf("my strlcat: %d\n", strlcatsize1);
//memcpy
	char memcpydst[50] = "hello";
    char memcpysrc[50] = "barsik";
    printf("stnd memcpy: %s\n", memcpy(&memcpydst[1], &memcpysrc[2], 2));
    char memcpydst1[50] = "hello";
    char memcpysrc1[50] = "barsik";
    printf("my memcpy: %s\n", ft_memcpy(&memcpydst1[1], &memcpysrc1[2], 2));
//memccpy
	char memccpydst[50] = "hello";
    char memccpysrc[50] = "barsik";
    printf("stnd memccpy: %s\n", memccpy(memccpydst, memccpysrc, 'r', 6));
    printf("stnd memccpy: %s\n", &memccpydst[0]);
    char memccpydst1[50] = "hello";
    char memccpysrc1[50] = "barsik";
    printf("my memccpy: %s\n", ft_memccpy(memccpydst1, memccpysrc1, 'r', 6));
    printf("stnd memccpy: %s\n", &memccpydst1[0]);
//memchr
	char *memchr1 = "hello";
    printf("stnd memchr: %s\n", memchr(memchr1, 'e', 3));
    char *memchr2 ="hello";
    printf("my memchr: %s\n", ft_memchr(memchr2, 'e', 3));
//memcmp
	char *memcmp1 = "helloh";
	char *memcmp2 ="helHof";
    printf("stnd memcmp: %d\n", memcmp(memcmp1, memcmp2, 6));
    printf("my memcmp: %d\n", ft_memcmp(memcmp1, memcmp2, 6));
//memmove
	char memmovesrc[] = "1234567890";
    char *memmovedst = memmovesrc + 5;
    printf("stnd memmove: %s\n", memmovesrc);
    printf("stnd memmove: %s\n", memmovedst);
    printf("stnd memmove: %s\n", memmove(memmovesrc, memmovedst, 4));
    printf("stnd memmove: %s\n", memmovesrc);
    char memmovesrc1[] = "1234567890";
    char *memmovedst1 = memmovesrc1 + 5;
    printf("my memmove: %s\n", memmovesrc1);
    printf("my memmove: %s\n", memmovedst1);
    printf("my memmove: %s\n", ft_memmove(memmovesrc1, memmovedst1, 4));
    printf("my memmove: %s\n", memmovesrc1);
//strnew
	char *strnew1 = ft_strnew(3);
    int i;
	printf("strnew: \n");
    if (strnew1 == NULL)
        printf("fuck NULL\n");
    else
        printf("not NULL\n");
    for (i = 0;i < 3; i++)
    {
        strnew1[i] = 'l';
    }
    printf("%s\n", strnew1);
//memalloc
	int *memalloc1= ft_memalloc(5);
	printf("memalloc: \n");
    if (memalloc1 == NULL)
        printf("fuck NULL\n");
    else
        printf("not NULL\n");

	/**memalloc1 = 5;
	   printf("%d", *memalloc1);*/    
	for (i = 0; i < 5; i++)
    {
        memalloc1[i] = i;
    }

	for (i = 0; i < 5; i++)
    {
    	printf("%d", memalloc1[i]);
	}
	printf("\n");
//strdel
	ft_strdel(&strnew1);
	if (strnew1 == NULL)
	{
		printf("strdel: %s\n", strnew1);
		printf("strdel: you cleared everything correctly\n");
	}
//memdel
	ft_memdel((void **)(&memalloc1));
    if (memalloc1 == NULL)
    {
		printf("memdel: %p\n", memalloc1);
        printf("memdel: you cleared everything correctly\n");
    }
//strclr
	char strclr1[89];
	for (i = 0; i < 10; i++)
    {
        strclr1[i] = '1';
    }
	for (i = 0; i < 10; i++)
    {
        printf("%c", strclr1[i]);
    }
	printf("\n");
	ft_strclr(strclr1);
	for (i = 0; i < 10; i++)
    {
        if (strclr1[i] == '\0')
		{
			printf("Ha");
		}
    }
	printf("\n");
//strequ
	char *strequ1 = "";
	char *strequ2 = "ggfgf";
	if (ft_strequ(strequ1, strequ2) == 1)
	{
		printf("strequ: your strings are equal\n");
	}
	else
	{
		printf("strequ: your strings are not equal");
	}
	printf("\n");
//strnequ
	char *strnequ1 = "hello";
    char *strnequ2 ="hellO";
    if (ft_strnequ(strnequ1, strnequ2, 4) == 1)
    {
        printf("strnequ: your strings are equal\n");
    }
    else
    {   
        printf("strnequ: your strings are not equal");
    }
//strjoin
	char *strjoin1 = "hello";
	char *strjoin2 = "Vasya";
	char *ptr = ft_strjoin(strjoin1, strjoin2);
	printf("ft_strjoin - 1st string: %s\n", strjoin1);
	printf("ft_strjoin - 2nd string:%s\n", strjoin2);
	printf("ft_strjoin - result: %s\n", ptr);
//strsub
	char strsub1[50] = "HelloVasya";
	ptr = ft_strsub(strsub1, 2, 5);
	printf("ft_strsub original string: %s\n", strsub1);
	printf("ft_strsub: %s\n", ptr);
//strtrim
	char *strtrim1 = "             hello Vasya lmao noob  	";
	ptr = ft_strtrim(strtrim1);
	printf("ft_strtrim original string: %s\n", strtrim1);
    printf("ft_strtrim: %s\n", ptr);
//itoa
	char *itoa1 = ft_itoa(2147483647);
    printf("itoa: %s\n", itoa1);
	char *itoa2 = ft_itoa(-2147483648);
    printf("itoa: %s\n", itoa2);
	char *itoa3 = ft_itoa(0);
    printf("itoa: %s\n", itoa3);
	char *itoa4 = ft_itoa(214);
    printf("itoa: %s\n", itoa4);
	char *itoa5 = ft_itoa(-214);
    printf("itoa: %s\n", itoa5);
//striter
	char striter1[11] = "HelloWorld";
    ft_striter(striter1, &ft_toupperstriter);
    printf("striter: %s\n", striter1);
//striteri
	char striteri1[] = "hello";
    ft_striteri(striteri1, &function_striteri);
    printf("striteri: %s\n", striteri1);
//strmap
	char strmap1[11] = "HelloWorld";
	char *ptrstrmap = ft_strmap(strmap1, &strmap_toupper);
	printf("strmap: %s\n", ptrstrmap);
	printf("strmap original: %s\n", strmap1);
//strmapi
	char strmapi1[] = "HelloWorld";
    char *ptrstrmapi = ft_strmapi(strmapi1, &function_strmapi);
    printf("strmapi: %s\n", ptrstrmapi);
	printf("strmapi original: %s\n", strmapi1);
//FILE DESCRIPTORS
	int fd1;
	int iter;

	fd1 = open("my_file.txt", O_CREAT | O_WRONLY, 0600);

    if (fd1 == -1)
    {
        printf("failed to create and open the file\n");
        return (-1);
    }

    iter = 2;
    while (iter > 0)
    {
        ft_putchar_fd('g', fd1);
        iter--;
    }
    ft_putchar_fd('\n', fd1);

    close(fd1);

    fd1 = open("my_file.txt", O_APPEND | O_WRONLY);

    if (fd1 == -1)
    {
        printf("failed to append the file\n");
        return (-1);
    }

    ft_putstr_fd("Hello Mofo", fd1);
    ft_putchar_fd('\n', fd1);

    close(fd1);

    fd1 = open("my_file.txt", O_APPEND | O_WRONLY);

    if (fd1 == -1)
    {
        printf("failed to append the file\n");
        return (-1);
    }

    ft_putendl_fd("putendl stuff here", fd1);

    ft_putnbr_fd(123, fd1);

    close(fd1);
//strsplit
	char *str_split1 = "**hi**hoi**hell***ggfdgdfg** gfgfgfg";
    char **str_split2 = ft_strsplit(str_split1, '*');
    int is1;
    for (is1 = 0; is1 < 6; is1++)
    {
        printf("strsplit:\nthe word: %d -  %s\n", is1, str_split2[is1]);
    }

	return (0);
}
