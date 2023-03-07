/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 01:26:03 by syamashi          #+#    #+#             */
/*   Updated: 2023/03/07 13:26:10 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm_bonus.h"

void	print_list(t_list *list)
{
	int n = 0;

	while (list != NULL)
	{
		printf("	size:%d, data:%s\n", n, list->data);
		list = list->next;
		n++;
	}
}

void	test_ft_atoi_base()
{
	int 	n;

	printf("##############################################\n");
	n = ft_atoi_base("123", "0123456789");
	printf("ft_atoi_base[123/0123456789]:%d\n", n);
	n = ft_atoi_base("2147483646", "0123456789");
	printf("ft_atoi_base[2147483646/0123456789]:%d\n", n);
	n = ft_atoi_base("2147483647", "0123456789");
	printf("ft_atoi_base[2147483647/0123456789]:%d\n", n);
	n = ft_atoi_base("2147483648", "0123456789");
	printf("ft_atoi_base[2147483648/0123456789]:%d\n", n);
	n = ft_atoi_base("-2147483647", "0123456789");
	printf("ft_atoi_base[-2147483647/0123456789]:%d\n", n);
	n = ft_atoi_base("-2147483648", "0123456789");
	printf("ft_atoi_base[-2147483648/0123456789]:%d\n", n);
	n = ft_atoi_base("-2147483649", "0123456789");
	printf("ft_atoi_base[-2147483649/0123456789]:%d\n", n);
	n = ft_atoi_base("   +++-100", "0123456789");
	printf("ft_atoi_base[   +++-100/0123456789]:%d\n", n);
	n = ft_atoi_base("   ------100", "0123456789");
	printf("ft_atoi_base[   ------100/0123456789]:%d\n", n);
	n = ft_atoi_base(NULL, "0123456789");
	printf("ft_atoi_base[NULL/0123456789]:%d\n", n);
	n = ft_atoi_base("100", NULL);
	printf("ft_atoi_base[100/NULL]:%d\n", n);
	n = ft_atoi_base("000", "0");
	printf("ft_atoi_base[000/0]:%d\n", n);
	n = ft_atoi_base("000", "");
	printf("ft_atoi_base[000/]:%d\n", n);
	n = ft_atoi_base("", "0123456789");
	printf("ft_atoi_base[/0123456789]:%d\n", n);
	n = ft_atoi_base("100", "0\t123");
	printf("ft_atoi_base[100/0\\t123]:%d\n", n);
	n = ft_atoi_base("100", "01\n23");
	printf("ft_atoi_base[100/01\\n23]:%d\n", n);
	n = ft_atoi_base("100", "012\v3");
	printf("ft_atoi_base[100/012\\v3]:%d\n", n);
	n = ft_atoi_base("100", "0123\f");
	printf("ft_atoi_base[100/0123\\f]:%d\n", n);
	n = ft_atoi_base("100", "\r0123");
	printf("ft_atoi_base[100/\\r0123]:%d\n", n);
	n = ft_atoi_base("100", "0 123");
	printf("ft_atoi_base[100/0 123]:%d\n", n);
	n = ft_atoi_base("100", "01+23");
	printf("ft_atoi_base[100/01+23]:%d\n", n);
	n = ft_atoi_base("100", "012-3");
	printf("ft_atoi_base[100/012-3]:%d\n", n);
	n = ft_atoi_base("100", "01");
	printf("ft_atoi_base[100/01]:%d\n", n);
	n = ft_atoi_base("0", "0123");
	printf("ft_atoi_base[0/01]:%d\n", n);
	n = ft_atoi_base("123", "00123");
	printf("ft_atoi_base[123/00123]:%d\n", n);
	n = ft_atoi_base(" \t\n\v\f\r+-100", "0123456789");
	printf("ft_atoi_base[ \\t\\n\\v\\f\\r+-100/0123456789]:%d\n", n);
	n = ft_atoi_base(" \t\n\v\f\r+-100a100", "0123456789");
	printf("ft_atoi_base[ \\t\\n\\v\\f\\r+-100a100/0123456789]:%d\n", n);
	n = ft_atoi_base("baa", "abcdefghij");
	printf("ft_atoi_base[baa/abcdefghij]:%d\n", n);
	n = ft_atoi_base("aaaaabaa", "abcdefghij");
	printf("ft_atoi_base[aaaaabaa/abcdefghij]:%d\n\n", n);
}

void	test_ft_list_push_front()
{
	t_list	*list = NULL;

	printf("##############################################\n");
	printf("ft_list_push_front\n");
	ft_list_push_front(&list, strdup("1st_push"));
	ft_list_push_front(&list, strdup("2nd_push"));
	ft_list_push_front(&list, strdup("3rd_push"));
	print_list(list);

	printf("\nft_list_push_front [Error Check]\n");
	ft_list_push_front(NULL, strdup("1st_push"));
	printf("\n");
}

void	test_ft_list_size()
{
	int		n;
	t_list	*list = NULL;

	printf("##############################################\n");
	n = ft_list_size(list);
	printf("ft_list_size[0]:%d\n", n);
	ft_list_push_front(&list, strdup("1st_push"));
	n = ft_list_size(list);
	printf("ft_list_size[1push_front]:%d\n", n);
	ft_list_push_front(&list, strdup("2nd_push"));
	n = ft_list_size(list);
	printf("ft_list_size[2push_front]:%d\n", n);
	ft_list_push_front(&list, strdup("3rd_push"));
	n = ft_list_size(list);
	printf("ft_list_size[3push_front]:%d\n", n);
	ft_list_push_front(&list, strdup("2nd_push"));
	n = ft_list_size(list);
	printf("ft_list_size[2push_front]:%d\n\n", n);
}

void	test_ft_list_sort()
{
	t_list	*list = NULL;

	printf("##############################################\n");
	ft_list_push_front(&list, strdup("1st_push"));
	ft_list_push_front(&list, strdup("2nd_push"));
	ft_list_push_front(&list, strdup("3rd_push"));
	ft_list_push_front(&list, strdup("2nd_push"));
	printf("ft_list_sort[2nd,3rd,2nd,1st]\n");
	print_list(list);
	ft_list_sort(&list, strcmp);
	printf("After	\n");
	print_list(list);

	printf("\nft_list_sort [Error Check]\n");
	ft_list_sort(NULL, strcmp);
	ft_list_sort(&list, NULL);
	printf("\n");
}

void	test_ft_list_remove_if()
{
	t_list	*list = NULL;

	printf("##############################################\n");
	ft_list_push_front(&list, strdup("1st_push"));
	ft_list_push_front(&list, strdup("2nd_push"));
	ft_list_push_front(&list, strdup("3rd_push"));
	ft_list_push_front(&list, strdup("2nd_push"));
	printf("ft_list_remove_if [2nd_push]\n");
	print_list(list);
	ft_list_remove_if(&list, "2nd_push", strcmp, free);
	printf("After	\n");
	print_list(list);

	printf("\nft_list_remove_if [Error Check]\n");
	ft_list_remove_if(NULL, "3rd_push", strcmp, free);
	ft_list_remove_if(&list, NULL, strcmp, free);
	ft_list_remove_if(&list, "3rd_push", NULL, free);
	ft_list_remove_if(&list, "3rd_push", strcmp, NULL);
	printf("\n");
}

int		main(int argc, char **argv)
{
	int 	i;

	if (argc == 1)
	{
		test_ft_atoi_base();
		test_ft_list_push_front();
		test_ft_list_size();
		test_ft_list_sort();
		test_ft_list_remove_if();
		return (0);
	}
	i = 1;
	while (argc != i)
	{
		if (strcmp(argv[i], "ft_atoi_base") == 0)
			test_ft_atoi_base();
		else if (strcmp(argv[i], "ft_list_push_front") == 0)
			test_ft_list_push_front();
		else if (strcmp(argv[i], "ft_list_size") == 0)
			test_ft_list_size();
		else if (strcmp(argv[i], "ft_list_sort") == 0)
			test_ft_list_sort();
		else if (strcmp(argv[i], "ft_list_remove_if") == 0)
			test_ft_list_remove_if();
		else if (strcmp(argv[i], "all") == 0)
		{
			test_ft_atoi_base();
			test_ft_list_push_front();
			test_ft_list_size();
			test_ft_list_sort();
			test_ft_list_remove_if();
		}
		i++;
	}
	return (0);
}

