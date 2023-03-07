#include "libasm.h"

int		main(int argc, char **argv)
{
	// strlen
	printf("##############################################\n");
	size_t len = ft_strlen("abc");
	printf("ft_strlen[abc]:%d\n", len);

	// strcpy
	printf("\n##############################################\n");
	char s1[10] = "abc";
	char *s2 = ft_strcpy(s1, "efg");
	printf("ft_strcpy[abc/efg]:%s\n", s2);

	// strcmp
	printf("\n##############################################\n");
	int n = ft_strcmp("abc", "abc");
	printf("ft_strcmp[abc/abc]:%d\n", n);

	// write
	printf("\n##############################################\n");
	int count = ft_write(1, "hello_world\n", 13);
	printf("ft_write[hello_world\\n]:%d\n", count);

	// read
	printf("\n##############################################\n");
	char	buf[1024];
	int		fd = open("main/sample.txt", O_RDONLY);
	int		readsize = ft_read(fd, buf, 1024);
	buf[readsize] = '\0';
	printf("ft_read(sample.txt, buf, 1024):%s\n", buf);
	close(fd);

	// strdup
	printf("\n##############################################\n");
	char *s = ft_strdup("abc");
	printf("ft_strdup(\"abc\"):%s\n", s);
	free(s);

	return (0);
}
