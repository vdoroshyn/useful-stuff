/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullthing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:43:08 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/27 18:01:00 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char *g_map;

int     second_layer(char *buf);
int     enter_check(char *buf);
int     first_layer(char *buf);
char    *cut_horizontal(char *buf);
char    *cut_vertical(char *buf);
int     ft_tocut(char c);
void    final_cut(char *dest, char *buf, char letter);
void    list_pushback(t_fill **head, char *buf, char letter);
int     height_count(char *buf);
int     width_count(char *buf);
t_fill      *new_node(char *buf, char letter);
void	to_list(t_fill  **head);
char	*ft_realloc(int size);
int     fillerino(int height, t_fill *lst);
void    inserterino(t_fill *lst, int *ptr);
void    deleterino(t_fill *lst);
int     *searcherino(int height, int index, t_fill *lst, int *ptr);
int     limits(int height, int index, t_fill *lst);
int		ft_isalpha(int c);
void	ft_putendl(char const *s);
void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}


t_fill      *new_node(char *buf, char letter)
{
    t_fill * ptr;

    ptr = (t_fill *)malloc(sizeof(t_fill));
    if (ptr == NULL)
    {
        return (NULL);
    }
    cut_horizontal(buf);
    cut_vertical(buf);
    final_cut(ptr->figure, buf, letter);
    ptr->letter = letter;
    ptr->width = width_count(ptr->figure);
    ptr->height = height_count(ptr->figure);
    ptr->next = NULL;

    return (ptr);
}

void    list_pushback(t_fill **head, char *buf, char letter)
{
    t_fill *temp;


    if (*head == NULL)
    {
        *head = new_node(buf, letter);
        return ;
    }
    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node(buf, letter);
}

char    *cut_horizontal(char *buf)
{
    int i;
    int j;
    int counter;

    i = 0;
    while (i < 20)
    {
        counter = 0;
        j = i;
        while (buf[i] != '\n')
        {
            if (buf[i] == '.')
            {
                counter++;
            }
            i++;
        }
        if (counter == 4)
        {
            while (buf[j] != '\n')
            {
                buf[j] = '*';
                j++;
            }
            buf[j] = '*';
        }
        i++;
    }
    return (buf);
}

char    *cut_vertical(char *buf)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (ft_tocut(buf[i]) && ft_tocut(buf[i + 5])
			&& ft_tocut(buf[i + 10]) && ft_tocut(buf[i + 15]))
        {
            buf[i] = '*';
            buf[i + 5] = '*';
            buf[i + 10] = '*';
            buf[i + 15] = '*';
        }
        i++;
    }
    return (buf);
}

int     ft_tocut(char c)
{
    if (c == '.' || c == '*')
    {
        return (1);
    }
    return (0);
}

void    final_cut(char *dest, char *buf, char letter)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (buf[i] != '\0')
    {
        if (buf[i] != '*')
        {
            if (buf[i] == '#')
            {
                dest[j] = letter;
                j++;
            }
            else
            {
                dest[j] = buf[i];
                j++;
            }
        }
        i++;
    }
    dest[j] = '\0';
}

int     height_count(char *buf)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (buf[i] != '\0')
    {
        if (buf[i] == '\n')
        {
            res++;
        }
        i++;
    }
    return (res);
}

int     width_count(char *buf)
{
    int i;

    i = 0;
    while (buf[i] != '\n')
    {
        i++;
    }
    return (i);
}


int     enter_check(char *buf)
{
    int i;
    int counter;

    counter = 0;
    i = 4;
    while (i < 20)
    {
        if (buf[i] == '\n')
        {
            counter++;
        }
        i = i + 5;
    }
    if (counter == 4)
    {
        return (1);
    }
    return (0);
}

int     first_layer(char *buf)
{
    int enter;
    int dot;
    int hash;
    int i;

    enter = 0;
    dot = 0;
    hash = 0;
    i = 0;
    if (enter_check(buf) == 0)
    {
        printf("The enters are not in their positions\n");
        return (0);
    }
    while (buf[i] != '\0')
    {
        if (buf[i] == '#')
        {
            hash++;
        }
        if (buf[i] == '.')
        {
            dot++;
        }
        i++;
    }
    if (hash == 4 && dot == 12)
    {
        if ((second_layer(buf) == 0))
        {
            printf("Your blocks are not well connected and are invalid\n");
            return (0);
        }
        else
        {
            return (1);
        }
    }
    printf("The number of dots and hashes is not correct\n");
    return (0);
}

int     second_layer(char *buf)
{
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (buf[i] != '\0')
    {
        if (buf[i] == '#')
        {
            if ((i + 1) < 20 && buf[i + 1] == '#')
            {
                counter++;
            }
            if ((i - 1) >= 0 && buf[i - 1] == '#')
            {
                counter++;
            }
            if ((i + 5) < 20 && buf[i + 5] == '#')
            {
                counter++;
            }
            if ((i - 5) >= 0 && buf[i - 5] == '#')
            {
                counter++;
            }
        }
        i++;
    }
    if (counter == 6 || counter == 8)
    {
        return (1);
    }
    return (0);
}

int		isvalid(void)
{
    int fd;
    char buf[22];
    ssize_t scanned;

    fd = open("palka.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("the file did not open\n");
        exit (1);
    }
    scanned = read(fd, buf, 21);
    while (scanned != 0)
    {
        if (scanned == 21)
        {
            buf[21] = '\0';
            if ((first_layer(buf) == 0))
            {
                return (0);
            }
        }
        else if (scanned == 20)
        {
            buf[20] = '\0';
            if ((first_layer(buf) == 0))
            {
                return (0);
            }
        }
        else
        {
            printf("One of your Tetriminos is not valid\n");
            return (0);
        }
        scanned = read(fd, buf, 21);
    }
    close(fd);

    return (1);
}

void	to_list(t_fill  **head)
{
    char buf[22];
    char letter;
    int fd;

    fd = open("palka.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("the file did not open\n");
        exit (1);
    }
    letter = 'A';
    while (read(fd, buf, 21) != 0)
    {
        buf[20] = '\0';
        list_pushback(head, buf, letter);
        letter++;
    }
    close (fd);
}

int     limits(int height, int index, t_fill *lst)
{
    if (index % (height + 1) + lst->width <= height)
    {
        if (index / (height + 1) + lst->height <= height)
        {
            return (1);
        }
    }
    return (0);
}

int     *searcherino(int height, int index, t_fill *lst, int *ptr)
{
    int i;
    int j;
    char *figure;
    int mem;

    if (limits(height, index, lst) == 0)
    {
        return (NULL);
    }
    figure = lst->figure;
    i = 0;
    j = 0;
    mem = index;
    while (figure[i] != '\0')
    {
        if (ft_isalpha(figure[i]) && g_map[index] != '.')
        {
            return (NULL);
        }
        if (figure[i] == '\n')
        {
            index = mem + height + 1;
            mem = index;
            i++;
        }
        else
        {
            if (figure[i] != '.')
            {
                ptr[j] = index;
                j++;
            }
            index++;
            i++;
        }
    }
    return (ptr);
}

int     fillerino(int height, t_fill *lst)
{
    int i;
    int *ptr;
	//int ptr[4];

    i = 0;
    if (lst == NULL)
    {
        return (1);
    }
    ptr = (int *)malloc(sizeof(int) * 4);
    if (ptr == NULL)
    {
        return (0);
    }
    while (g_map[i] != '\0')
    {
        if (ptr != NULL && searcherino(height, i, lst, ptr) != NULL)
        {
            /*for (int k = 0; k < 4; k++) //TODO
            {
                printf("%d\n", ptr[k]);
				}*/
            inserterino(lst, ptr);
			free(ptr);
			//printf("%s", map);
//TODO
			//printf("before\n");
			/*for (int k = 0; k < 4; k++)
			{
				printf("BEFORE %d", ptr[k]);
			}
			printf("\n");*/
			
/*for (int k = 0; k < 4; k++)
{
	printf("%d", ptr[k]);
}
printf("\n");*/

			//printf("after\n");
            if (fillerino(height, lst->next) == 1)
            {
                return (1);
            }
            deleterino(lst);
        }
        i++;
    }
    return (0);
}

void    inserterino(t_fill *lst, int *ptr)
{
    int i;

    i = 0;
    while (i < 4)
    {
        g_map[ptr[i]] = lst->letter;
        i++;
    }
}

void    deleterino(t_fill *lst)
{
    int i;

    i = 0;
    while (g_map[i] != '\0')
    {
        if (g_map[i] == lst->letter)
        {
            g_map[i] = '.';
        }
        i++;
    }
}

char	*ft_realloc(int size)
{
    int i;
    int len;
	char *ptr;

    if (g_map != NULL)
    {
	    free (g_map);
    }
    len = (size + 1) * size;
    ptr = (char *)malloc(sizeof(char) * (len + 1));
    if (ptr == NULL)
    {
        return (NULL);
    }
    i = 0;
    while (i < len)
    {
        ptr[i] = '.';
        i++;
    }
    ptr[i] = '\0';
    i = 0;
    while (i < len)
    {
        ptr[size + i] = '\n';
        i = i + size + 1;
    }
	return (ptr);
}


int		main(void)
{
	t_fill *head;
	t_fill *tmp; //TODO
	int size;
	int figure_count;

	head = NULL;
	figure_count = 0;
	if (isvalid())
	{
		to_list(&head);
		tmp = head;
		while (tmp != NULL) //TODO
		{
			/*printf("%s", tmp->figure);
			printf("width is %d\n", tmp->width);
			printf("height is %d\n", tmp->height);
			printf("letter is %c\n", tmp->letter);
			}*/
			figure_count++;
			printf("%d\n", figure_count);
			tmp = tmp->next;
		}
	}
	else
	{
		ft_putendl("error");
		return (1);
	}
	size = 2;
	/*while (figure_count * 4 > size * size)
	{
		size++;
		}*/
	g_map = NULL;
	g_map = ft_realloc(size);
	while (!fillerino(size, head))
	{
		size++;
		g_map = ft_realloc(size);
	}
	printf("%s", g_map);
	return (0);
}
