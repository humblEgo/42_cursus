/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:50:17 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/09 21:44:44 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include "libasm.h"


void	test_strlen(void)
{
	size_t	len;
	size_t	ft_len;
	char	*str;


	printf("\n\t\t\t   test1\n"); str = "abcde";
	len = strlen(str);
	printf("str:    %s\n", str);
	printf("len:    %lu\n", len);
	ft_len = ft_strlen(str);
	printf("ft_len: %lu\n", ft_len);
	assert(len == ft_len);

	printf("\n\t\t\t   test2\n");
	str = "";
	len = strlen(str);
	printf("str:    %s\n", str);
	printf("len:    %lu\n", len);
	ft_len = ft_strlen(str);
	printf("ft_len: %lu\n", ft_len);
	assert(len == ft_len);
}

void	test_strcpy(void)
{
	char	*src;
	char	dest[10];

	printf("\n\t\t\t   test1\n");
	src = "abcde";
	ft_strcpy(dest, src);
	printf("src:    %s\n", src);
	printf("dest:   %s\n", dest);
	assert(!(strcmp(src, dest)));

	printf("\n\t\t\t   test2\n");
	src = "";
	ft_strcpy(dest, src);
	printf("src:    %s\n", src);
	printf("dest:   %s\n", dest);
	assert(!(strcmp(src, dest)));

}

void	test_strcmp(void)
{
	char	*s1;
	char	*s2;
	int		res1;
	int		res2;

	printf("\n\t\t\t   test1\n");
	s1 = "abcde";
	s2 = "abc";
	printf("s1:     %s\n", s1);
	printf("s2:     %s\n", s2);
	res1 = strcmp(s1, s2);
	res2 = ft_strcmp(s1, s2);
	printf("res1:   %d\n", res1);
	printf("res2:   %d\n", res2);
	assert(res1 == res2);

	printf("\n\t\t\t   test2\n");
	s1 = "abcdef";
	s2 = "abcde";
	printf("s1:     %s\n", s1);
	printf("s2:     %s\n", s2);
	res1 = strcmp(s1, s2);
	res2 = ft_strcmp(s1, s2);
	printf("res1:   %d\n", res1);
	printf("res2:   %d\n", res2);
	assert(res1 == res2);

	printf("\n\t\t\t   test3\n");
	s1 = "Abc";
	s2 = "abcde";
	printf("s1:     %s\n", s1);
	printf("s2:     %s\n", s2);
	res1 = strcmp(s1, s2);
	res2 = ft_strcmp(s1, s2);
	printf("res1:   %d\n", res1);
	printf("res2:   %d\n", res2);
	assert(res1 == res2);

	printf("\n\t\t\t   test4\n");
	s1 = "";
	s2 = "abc";
	printf("s1:     %s\n", s1);
	printf("s2:     %s\n", s2);
	res1 = strcmp(s1, s2);
	res2 = ft_strcmp(s1, s2);
	printf("res1:   %d\n", res1);
	printf("res2:   %d\n", res2);
	assert(res1 == res2);

	printf("\n\t\t\t   test5\n");
	s1 = "";
	s2 = "";
	printf("s1:     %s\n", s1);
	printf("s2:     %s\n", s2);
	res1 = strcmp(s1, s2);
	res2 = ft_strcmp(s1, s2);
	printf("res1:   %d\n", res1);
	printf("res2:   %d\n", res2);
	assert(res1 == res2);

}

void	test_write(void)
{
	char	*src;
	int		a;
	int		b;

	printf("\n\t\t\t   test1\n");
	src = "abcde\n";
	a = write(1, src, 6);
	b = ft_write(1, src, 6);
	assert(a == b);

	printf("\n\t\t\t   test2\n");
	src = "";
	a = write(1, src, 5);
	b = ft_write(1, src, 5);
	assert(a == b);
	printf("\n");
}

void	test_read(void)
{
	char	*src;
	char	dest[100];
	int		fd1;
	int		fd2;
	int		a;
	int		b;

	printf("\n\t\t\t   test1\n");
	src = "read1.txt";
	fd1 = open(src, O_RDONLY);
	printf("fd1: %d\n", fd1);
	a = read(fd1, dest, 6);
	printf("a: %d\n", a);
	close(fd1);

	fd2 = open(src, O_RDONLY);
	printf("fd2: %d\n", fd2);
	b = ft_read(fd2, dest, 6);
	printf("b: %d\n", b);
	close(fd2);
	assert(a == b);

	printf("\n\t\t\t   test2\n");
	src = "read2.txt";
	fd1 = open(src, O_RDONLY);
	a = read(fd1, dest, 6);

	printf("fd1: %d\n", fd1);
	printf("a: %d\n", a);

	fd2 = open(src, O_RDONLY);
	b = ft_read(fd2, dest, 6);

	printf("fd2: %d\n", fd2);
	printf("b: %d\n", b);

	close(fd1);
	close(fd2);
	assert(a == b);

}

t_list	*ft_lstnew(void *data)
{
	t_list	*new_node;

	if (!(new_node = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (data == NULL)
		new_node->data = NULL;
	else
		new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	print_all_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->data);
		lst = lst->next;
	}
}

void	test_list_push_front(void)
{
	char	*b;
	t_list	*list;
	t_list	*node;
	t_list	test;

	b = "list start";
	list = ft_lstnew(b);

//	printf("t_list:			%ld\n", sizeof(t_list));
//	printf("t_list->next:	%ld\n", sizeof(test.next));
//	printf("t_list->data:	%ld\n", sizeof(test.data));
	b = "123";
	ft_list_push_front(&list, b);
	b = "456";
	ft_list_push_front(&list, b);
	b = "789";
	ft_list_push_front(&list, b);
	print_all_list(list);
}

int		main(void)
{
//	printf("------ft_strlen test start------\n");
//	test_strlen();
//	printf("------ft_strlen test success------\n\n");
//
//	printf("\n------ft_strcpy test start------\n");
//	test_strcpy();
//	printf("------ft_strcpy test success------\n");
//
//	printf("\n------ft_strcmp test start------\n");
//	test_strcmp();
//	printf("------ft_strcmp test success------\n");
//
//	printf("\n------ft_write test start------\n");
//	test_write();
//	printf("------ft_write test success------\n");
//
//	printf("\n------ft_read test start------\n");
//	test_read();
//	printf("------ft_read test success------\n");

	printf("\n------ft_lstadd_front test start------\n");
	test_list_push_front();
	printf("------ft_lstadd_front test success------\n");


	return (0);
}
