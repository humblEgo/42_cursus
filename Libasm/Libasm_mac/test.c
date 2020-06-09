/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:50:17 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/09 13:38:37 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
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
	char	*fault;
	int		fd1;
	int		fd2;
	int		a;
	int		b;
	int		err;

	memset(dest, 0, 100);

	printf("\n\t\t\t   test1\n");
	err = 0;
	src = "read1.txt";
	fd1 = open(src, O_RDONLY);
	printf("fd1: %d\n", fd1);
	a = read(fd1, dest, 6);
	err = errno;
	printf("err: %d\n", errno);
	printf("a: %d\n", a);
	close(fd1);


	err = 0;
	fd2 = open(src, O_RDONLY);
	printf("fd2: %d\n", fd2);
	b = ft_read(fd2, dest, 6);
	printf("b: %d\n", b);
	err = errno;
	printf("err: %d\n", errno);

	close(fd2);
	assert(a == b);

	printf("\n\t\t\t   test2\n");
	err = 0;
	src = "read2.txt";
	fd1 = open(src, O_RDONLY);
	a = read(fd1, dest, 6);
	err = errno;
	printf("err: %d\n", errno);

	printf("fd1: %d\n", fd1);
	printf("a: %d\n", a);
	printf("%s\n", dest);

	err = 0;
	fd2 = open(src, O_RDONLY);
	b = ft_read(fd2, dest, 6);
	err = errno;
	printf("err: %d\n", errno);

	printf("fd2: %d\n", fd2);
	printf("b: %d\n", b);
	printf("%s\n", dest);

	close(fd1);
	close(fd2);
	assert(a == b);

	printf("\n\t\t\t   test3\n");
	err = 0;
	src = "read1.txt";
	fd1 = open(src, O_RDONLY);
	a = read(fd1, fault, 6);
	err = errno;
	printf("err: %d\n", errno);

	printf("fd1: %d\n", fd1);
	printf("a: %d\n", a);
	printf("%s\n", fault);

	err = 0;
	fd2 = open(src, O_RDONLY);
	b = ft_read(fd2, fault, 6);
	err = errno;
	printf("err: %d\n", errno);

	printf("fd2: %d\n", fd2);
	printf("b: %d\n", b);
	printf("%s\n", fault);

	close(fd1);
	close(fd2);
	assert(a == b);

}

void	test_strdup(void)
{
	char	*src;
	char	*dst1;
	char	*dst2;
	int		num;

	printf("\n\t\t\t   test1\n");
	src = "abcde";
	dst1 = strdup(src);
	dst2 = ft_strdup(src);

	printf("dst1:     %s\n", dst1);
	printf("dst2:     %s\n", dst2);
	assert(!(strcmp(dst1, dst2)));
	free(dst1);
	free(dst2);

	printf("\n\t\t\t   test2\n");
	src = "";
	dst1 = strdup(src);
	dst2 = ft_strdup(src);
	printf("dst1:     %s\n", dst1);
	printf("dst2:     %s\n", dst2);
	assert(!(strcmp(dst1, dst2)));
	free(dst1);
	free(dst2);

//	printf("\n\t\t\t   test3\n");
//	char	*src2;
//	dst1 = strdup(src2);
//	int a = errno;
//	printf("error:    %d\n", a);
//	dst2 = ft_strdup(src2);
//	int b = errno;
//	printf("error:    %d\n", a);
//	printf("dst1:     %s\n", dst1);
//	printf("dst2:     %s\n", dst2);
//	assert(!(strcmp(dst1, dst2)));
//	free(dst1);
//	free(dst2);

	printf("\n\t\t\t   test4\n");
	src = "wow mandantory part is completed!";
	dst1 = strdup(src);
	dst2 = ft_strdup(src);
	printf("dst1:     %s\n", dst1);
	printf("dst2:     %s\n", dst2);
	assert(!(strcmp(dst1, dst2)));
	free(dst1);
	free(dst2);
}

int		main(void)
{
	printf("------ft_strlen test start------\n");
	test_strlen();
	printf("------ft_strlen test success------\n\n");

	printf("\n------ft_strcpy test start------\n");
	test_strcpy();
	printf("------ft_strcpy test success------\n");

	printf("\n------ft_strcmp test start------\n");
	test_strcmp();
	printf("------ft_strcmp test success------\n");

	printf("\n------ft_write test start------\n");
	test_write();
	printf("------ft_write test success------\n");

	printf("\n------ft_read test start------\n");
	test_read();
	printf("------ft_read test success------\n");

	printf("\n------ft_strdup test start------\n");
	test_strdup();
	printf("------ft_strdup test success------\n");

	return (0);
}
