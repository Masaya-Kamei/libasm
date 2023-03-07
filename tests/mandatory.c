#include "../includes/libasm.h"

void	print_error(int count)
{
	printf("	count		: %d\n", count);
    perror("	perror		");
    printf("	strerror	: %s\n", strerror(errno));
    printf("	errno		: %d\n", errno);
	errno = 0;
}

void	test_ft_strlen()
{
	int	len;

	printf("##############################################\n");
	len = ft_strlen("abc");
	printf("ft_strlen[abc]:%d\n", len);
	len = strlen("abc");
	printf("   strlen[abc]:%d\n", len);
	len = ft_strlen("");
	printf("ft_strlen[]:%d\n", len);
	len = strlen("");
	printf("   strlen[]:%d\n\n", len);
	// len = ft_strlen(NULL);
	// len = strlen(NULL);
}

void	test_ft_strcpy()
{
	char s1[10] = "abc";
	char s2[10] = "abcdefg";
	char *s3;

	printf("##############################################\n");
	s3 = ft_strcpy(s1, "efg");
	printf("ft_strcpy[abc/efg]:%s\n", s3);
	s3 = strcpy(s1, "efg");
	printf("   strcpy[abc/efg]:%s\n", s3);
	s3 = ft_strcpy(s2, "efg");
	printf("ft_strcpy[abcdefg/efg]:%s\n", s3);
	s3 = strcpy(s2, "efg");
	printf("   strcpy[abcdefg/efg]:%s\n", s3);
	s3 = ft_strcpy(s1, "stuvwxyz");
	printf("ft_strcpy[abc/stuvwxyz]:%s\n", s3);
	s3 = strcpy(s1, "stuvwxyz");
	printf("   strcpy[abc/stuvwxyz]:%s\n\n", s3);
	// s3 = ft_strcpy(s1, NULL);
	// s3 = strcpy(s1, NULL);
	// s3 = ft_strcpy(NULL, "efg");
	// s3 = strcpy(NULL, "efg");
	// s3 = ft_strcpy(NULL, NULL);
	// s3 = strcpy(NULL, NULL);
}

void	test_ft_strcmp()
{
	int		n;

	printf("##############################################\n");
	n = ft_strcmp("abc", "abc");
	printf("ft_strcmp[abc/abc]:%d\n", n);
	n = strcmp("abc", "abc");
	printf("   strcmp[abc/abc]:%d\n", n);
	n = ft_strcmp("abc", "acd");
	printf("ft_strcmp[abc/acd]:%d\n", n);
	n = strcmp("abc", "acd");
	printf("   strcmp[abc/acd]:%d\n", n);
	n = ft_strcmp("", "");
	printf("ft_strcmp[/]:%d\n", n);
	n = strcmp("", "");
	printf("   strcmp[/]:%d\n", n);
	n = ft_strcmp("abc", "defg");
	printf("ft_strcmp[abc/defg]:%d\n", n);
	n = strcmp("abc", "defg");
	printf("   strcmp[abc/defg]:%d\n", n);
	n = ft_strcmp("zyxwv", "abc");
	printf("ft_strcmp[zyxwy/abc]:%d\n", n);
	n = strcmp("zyxwv", "abc");
	printf("   strcmp[zyxwy/abc]:%d\n", n);
	n = ft_strcmp("\xff\xff", "\xff");
	printf("ft_strcmp[\xff\xff/\xff]:%d\n", n);
	n = strcmp("\xff\xff", "\xff");
	printf("   strcmp[\xff\xff/\xff]:%d\n", n);
	n = ft_strcmp("\xff", "");
	printf("ft_strcmp[\xff/]:%d\n", n);
	n = strcmp("\xff", "");
	printf("   strcmp[\xff/]:%d\n\n", n);
	// n = ft_strcmp(NULL, "abc");
	// n = strcmp(NULL, "abc");
	// n = ft_strcmp("abc", NULL);
	// n = strcmp("abc", NULL);
	// n = ft_strcmp(NULL, NULL);
	// n = strcmp(NULL, NULL);
}

void	test_ft_write()
{
	int		count;

	printf("##############################################\n");
	printf("ft_write(1, \"hello_world\\n\", 13)\n");
	count = ft_write(1, "hello_world\n", 13);
	print_error(count);
	count = write(1, "hello_world\n", 13);
	print_error(count);

	printf("\nft_write(1, \"over_words_set\\n\", 5)\n");
	count = ft_write(1, "over_words_set\n", 5);
	print_error(count);
	count = write(1, "over_words_set\n", 5);
	print_error(count);

	printf("\nft_write(1, NULL, 10)\n");
	count = ft_write(1, NULL, 10);
	print_error(count);
	count = write(1, NULL, 10);
	print_error(count);

	printf("\nft_write(1, \"hello_world\\n\", 0)\n");
	count = ft_write(1, "hello_world\n", 0);
	print_error(count);
	count = write(1, "hello_world\n", 0);
	print_error(count);

	printf("\nft_write(1, \"hello_world\\n\", -1)\n");
	count = ft_write(1, "hello_world\n", -1);
	print_error(count);
	count = write(1, "hello_world\n", -1);
	print_error(count);

	printf("\nft_write(0, \"hello_world\\n\", 13)\n");
	count = ft_write(0, "hello_world\n", 13);
	print_error(count);
	count = write(0, "hello_world\n", 13);
	print_error(count);

	printf("\nft_write(-1, \"hello_world\\n\", 13)\n");
	count = ft_write(-1, "hello_world\n", 13);
	print_error(count);
	count = write(-1, "hello_world\n", 13);
	print_error(count);

	printf("\nft_write(1, \"\", 1)\n");
	count = ft_write(1, "", 1);
	print_error(count);
	count = write(1, "", 1);
	print_error(count);

	printf("\nft_write(-1, \"tt\", 2)\n");
	count = ft_write(-1, "tt", 2);
	print_error(count);
	count = write(-1, "tt", 2);
	print_error(count);

	printf("\nft_write(OPEN_MAX + 1, \"tt\", 2)\n");
	count = ft_write(OPEN_MAX + 1, "tt", 2);
	print_error(count);
	count = write(OPEN_MAX + 1, "tt", 2);
	print_error(count);

	printf("\nft_write(98123, \"\", 1)\n");
	count = ft_write(98123, "", 1);
	print_error(count);
	count = write(98123, "", 1);
	print_error(count);
	printf("\n");
}

void	test_ft_read()
{
	char	buf[1024];
	int		count;
	int		fd;
	int		i;

	printf("##############################################\n");
	printf("ft_read(fd, buf, 1024)\n");
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = ft_read(fd, buf, 1024);
	write(1, buf, strlen(buf));
	print_error(count);
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = read(fd, buf, 1024);
	write(1, buf, strlen(buf));
	print_error(count);

	printf("\nft_read(-1, buf, 1024)\n");
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = ft_read(-1, buf, 1024);
	write(1, buf, strlen(buf));
	print_error(count);
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = read(-1, buf, 1024);
	write(1, buf, strlen(buf));
	print_error(count);

	printf("\nft_read(fd, NULL, 1024)\n");
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = ft_read(fd, NULL, 1024);
	write(1, buf, strlen(buf));
	print_error(count);
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = read(fd, NULL, 1024);
	write(1, buf, strlen(buf));
	print_error(count);

	printf("\nft_read(fd, buf, -1)\n");
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = ft_read(fd, buf, -1);
	write(1, buf, strlen(buf));
	print_error(count);
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = read(fd, buf, -1);
	write(1, buf, strlen(buf));
	print_error(count);

	printf("\nft_read(fd, buf, 0)\n");
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = ft_read(fd, buf, 0);
	write(1, buf, strlen(buf));
	print_error(count);
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = read(fd, buf, 0);
	write(1, buf, strlen(buf));
	print_error(count);

	printf("\nft_read(fd, buf, 2)\n");
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = ft_read(fd, buf, 2);
	write(1, buf, strlen(buf));
	print_error(count);
	i = 0;
	while (i < 1024)
		buf[i++] = '\0';
	fd = open("sample.txt", O_RDONLY);
	count = read(fd, buf, 2);
	write(1, buf, strlen(buf));
	print_error(count);
	printf("\n");
}

void	test_ft_strdup()
{
	char *s;

	printf("##############################################\n");
	s = ft_strdup("abc");
	printf("ft_strdup(\"abc\"):%s\n", s);
	free(s);
	s = strdup("abc");
	printf("   strdup(\"abc\"):%s\n", s);
	free(s);

	s = ft_strdup("");
	printf("ft_strdup(\"\"):%s\n", s);
	free(s);
	s = strdup("");
	printf("   strdup(\"\"):%s\n\n", s);
	free(s);

	// s = ft_strdup(NULL);
	// printf("ft_strdup(NULL):%s\n", s);
	// free(s);
	// s = strdup(NULL);
	// printf("   strdup(NULL):%s\n\n", s);
	// free(s);
}

int		main(int argc, char **argv)
{
	int 	i;

	if (argc == 1)
	{
		test_ft_strlen();
		test_ft_strcpy();
		test_ft_strcmp();
		test_ft_write();
		test_ft_read();
		test_ft_strdup();
		return (0);
	}
	i = 1;
	while (argc != i)
	{
		if (strcmp(argv[i], "ft_strlen") == 0)
			test_ft_strlen();
		else if (strcmp(argv[i], "ft_strcpy") == 0)
			test_ft_strcpy();
		else if (strcmp(argv[i], "ft_strcmp") == 0)
			test_ft_strcmp();
		else if (strcmp(argv[i], "ft_write") == 0)
			test_ft_write();
		else if (strcmp(argv[i], "ft_read") == 0)
			test_ft_read();
		else if (strcmp(argv[i], "ft_strdup") == 0)
			test_ft_strdup();
		else if (strcmp(argv[i], "all") == 0)
		{
			test_ft_strlen();
			test_ft_strcpy();
			test_ft_strcmp();
			test_ft_write();
			test_ft_read();
			test_ft_strdup();
		}
		i++;
	}
	return (0);
}
