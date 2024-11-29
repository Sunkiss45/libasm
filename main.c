# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>  

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define ORANGE "\033[38;2;255;165;0m"

# define UNDERLINE "\033[4m"
# define ITALIC "\033[3m"
# define RESET "\033[0m"

# define BUFFER 8192

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, char const *src);
int			ft_strcmp(char const *s1, char const *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);

void	lprintf(const char *msg, size_t limit) {
    if (strlen(msg) > limit) {
        for (size_t i = 0; i < limit; i++) {
            putchar(msg[i]);
        }
        printf("[...]");
    } else {
        printf("%s", msg);
    }
	return;
}

void testage_strlen(void)
{
	printf(ORANGE "");
	printf("=========================\n");
	printf("|  Testage de strlen :  |\n");
	printf("=========================\n\n" RESET);

	char *str[] = {
		"",
		"Hallo",
		"TeStAgE iMpRoMpTuE",
		"1-5+4/1*8",
		NULL
	};

	for (int i = 0; str[i] != NULL; i++)
	{
		printf(YELLOW UNDERLINE "Chaine utilisée :" RESET YELLOW " |%s|\n" RESET, str[i]);
		printf(CYAN "Return ft_strlen :		%zu\n" RESET, ft_strlen(str[i]));
		printf(CYAN "Return std strlen :		%zu\n" RESET, strlen(str[i]));

		if (strlen(str[i]) == ft_strlen(str[i]))
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);
	}

	return;
}

void testage_strcpy(void)
{
	printf(ORANGE "");
	printf("=========================\n");
	printf("|  Testage de strcpy :  |\n");
	printf("=========================\n\n" RESET);

	char *ft_dst = NULL;
	char *std_dst = NULL;

	char *str[] = {
		"",
		"Hallo",
		"TeStAgE iMpRoMpTuE",
		"1-5+4/1*8",
		NULL
	};

	for (int i = 0; str[i] != NULL; i++)
	{
		printf(YELLOW UNDERLINE "Chaine utilisée :" RESET YELLOW " |%s|" PURPLE " %p\n" RESET, str[i], str[i]);

		char *ft_dst_ret;
		char *std_dst_ret;

		if (!(ft_dst = malloc(strlen(str[i]) + 1))) {
			perror("malloc");
			return;}
		if (!(std_dst = malloc(strlen(str[i]) + 1))) {
			free(ft_dst);
			perror("malloc");
			return;}

		printf(PURPLE "Address ft_dst malloced : %p\n" RESET, ft_dst);
		printf(PURPLE "Address std_dst malloced : %p\n" RESET, std_dst);

		ft_dst_ret = ft_strcpy(ft_dst, str[i]);
		std_dst_ret = strcpy(std_dst, str[i]);

		printf(CYAN "Value ft_dst :			|%s|" PURPLE " %p\n" RESET, ft_dst, ft_dst);
		printf(CYAN "Return ft_strcpy :		|%s|" PURPLE " %p\n" RESET, ft_dst_ret, ft_dst_ret);
		printf(CYAN "Value std_dst :			|%s|" PURPLE " %p\n" RESET, std_dst, std_dst);
		printf(CYAN "Return std strcpy :		|%s|" PURPLE " %p\n" RESET, std_dst_ret, std_dst_ret);

		if (!strcmp(ft_dst, str[i]))
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);

		free(ft_dst);
		free(std_dst);

	}
}

void testage_strcmp(void)
{
	printf(ORANGE "");
	printf("=========================\n");
	printf("|  Testage de strcmp :  |\n");
	printf("=========================\n\n" RESET);

	char *str[] = {
		"",
		"Hallo",
		"TeStAgE iMpRoMpTuE",
		"1-5+4/1*8",
		"",
		"Hallo",
		"TeStAgE iMpRoMpTuE",
		"1-5+4/1*8",
		NULL
	};
	
	char *strr[] = {
		"",
		"Hallo",
		"TeStAgE iMpRoMpTuE",
		"1-5+4/1*8",
		";",
		"Hal lo",
		"TeStAqqgE iMpRoMpTuE",
		"1--8+5+4/1*8",
		NULL
	};
	
	for (int i = 0; str[i] != NULL; i++)
	{
		printf(YELLOW UNDERLINE "Chaines utilisées :" RESET YELLOW " |%s| |%s|\n" RESET, str[i], strr[i]);
		
		int ft = ft_strcmp(str[i], strr[i]);
		int std = strcmp(str[i], strr[i]);
		
		printf(CYAN "Return ft_strcmp :		%d\n" RESET, ft);
		printf(CYAN "Return std strcmp :		%d\n" RESET, std);
	
		if (ft == std)
			printf(GREEN "- Validé -\n\n" RESET);
		else if (ft > 0 && std > 0)
			printf(GREEN "- Validé (mais avec fsan) -\n\n" RESET);
		else if (ft < 0 && std < 0)
			printf(GREEN "- Validé (mais avec fsan) -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);
	}
}

void testage_write(void)
{
	printf(ORANGE "");
	printf("========================\n");
	printf("|  Testage de write :  |\n");
	printf("========================\n\n" RESET);

	char *str[] = {
		"",
		"Hallo",
		"TeStAgE iMpRoMpTuE",
		"1-5+4/1*8",
		"UNE CHAINE GENRE TRES TREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEES LONGUE",
		NULL
	};

	int cus_fd = open("testage_file.txt", O_WRONLY);
	int ft_errno = 0;
	int std_errno = 0;

	for (int i = 0; i != 6; i++)
	{
		printf(YELLOW UNDERLINE "Chaine utilisée :" RESET YELLOW " |%s|\n\n" RESET, str[i]);
		int len;
		if (str[i])
			len = strlen(str[i]);
		else
			len = 42;
		errno = 0;

		printf(PURPLE "Sortie Standard :\n" RESET);
		int fd = 1;
		int ft = ft_write(fd, str[i], len);
		ft_errno = errno;
		errno = 0;
		write(fd, " | ", 3);
		int std = write(fd, str[i], len);
		std_errno = errno;
		errno = 0;
		write(fd, "\n", 1);
		printf(CYAN "Return ft_write :		%zd (%d)" RED " Errno = %d\n" RESET, ft, (int)ft, ft_errno);
		printf(CYAN "Return std write :		%zd (%d)" RED " Errno = %d\n" RESET, std, (int)std, std_errno);

		if (ft == std && ft_errno == std_errno)
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);

		printf(PURPLE "Sortie FD :\n" RESET);
		fd = cus_fd;
		ft = ft_write(fd, str[i], len);
		ft_errno = errno;
		errno = 0;
		write(fd, " | ", 3);
		std = write(fd, str[i], len);
		std_errno = errno;
		errno = 0;
		write(fd, "\n", 1);
		printf(CYAN "Return ft_write :		%zd (%d)" RED " Errno = %d\n" RESET, ft, (int)ft, ft_errno);
		printf(CYAN "Return std write :		%zd (%d)" RED " Errno = %d\n" RESET, std, (int)std, std_errno);

		if (ft == std && ft_errno == std_errno)
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);

		printf(PURPLE " - FD invalide :\n" RESET);
		fd = -1;
		write(fd, "FD invalide - ", 14);
		ft = ft_write(fd, str[i], len);
		ft_errno = errno;
		errno = 0;
		write(fd, " | ", 3);
		std = write(fd, str[i], len);
		std_errno = errno;
		errno = 0;
		write(fd, "\n", 1);
		printf(RESET);
		printf(CYAN " - Return ft_write :		%zd (%d)" RED " Errno = %d\n" RESET, ft, (int)ft, ft_errno);
		printf(CYAN " - Return std write :		%zd (%d)" RED " Errno = %d\n" RESET, std, (int)std, std_errno);

		if (ft == std && ft_errno == std_errno)
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);

		printf(PURPLE " - Count négatif :\n" RESET);
		fd = cus_fd;
		write(fd, "Count négatif - ", 16);
		ft = ft_write(fd, str[i], -42);
		ft_errno = errno;
		errno = 0;
		write(fd, " | ", 3);
		std = write(fd, str[i], -42);
		std_errno = errno;
		errno = 0;
		write(fd, "\n", 1);
		printf(RESET);
		printf(CYAN " - Return ft_write :		%zd (%d)" RED " Errno = %d\n" RESET, ft, (int)ft, ft_errno);
		printf(CYAN " - Return std write :		%zd (%d)" RED " Errno = %d\n" RESET, std, (int)std, std_errno);

		if (ft == std && ft_errno == std_errno)
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);

		printf(PURPLE " - Count / 2 :\n" RESET);
		fd = cus_fd;
		write(fd, "Count / 2 - ", 12);
		ft = ft_write(fd, str[i], len/2);
		ft_errno = errno;
		errno = 0;
		write(fd, " | ", 3);
		std = write(fd, str[i], len/2);
		std_errno = errno;
		errno = 0;
		write(fd, "\n", 1);
		printf(RESET);
		printf(CYAN " - Return ft_write :		%zd (%d)" RED " Errno = %d\n" RESET, ft, (int)ft, ft_errno);
		printf(CYAN " - Return std write :		%zd (%d)" RED " Errno = %d\n" RESET, std, (int)std, std_errno);

		if (ft == std && ft_errno == std_errno)
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);

		printf(PURPLE " - Count = 0 :\n" RESET);
		fd = cus_fd;
		write(fd, "Count = 0 - ", 12);
		ft = ft_write(fd, str[i], len*0);
		ft_errno = errno;
		errno = 0;
		write(fd, " | ", 3);
		std = write(fd, str[i], len*0);
		std_errno = errno;
		errno = 0;
		write(fd, "\n", 1);
		printf(RESET);
		printf(CYAN " - Return ft_write :		%zd (%d)" RED " Errno = %d\n" RESET, ft, (int)ft, ft_errno);
		printf(CYAN " - Return std write :		%zd (%d)" RED " Errno = %d\n" RESET, std, (int)std, std_errno);

		if (ft == std && ft_errno == std_errno)
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);

	}

	close(cus_fd);

	return;
}

void testage_read(void)
{
	printf(ORANGE "");
	printf("=======================\n");
	printf("|  Testage de read :  |\n");
	printf("=======================\n\n" RESET);

	char	buf[BUFFER];
	int		fd;
	int		ft;
	int		std;
	char	ft_buf[BUFFER];
	char	std_buf[BUFFER];
	int		cus_fd = open("testage_file.txt", O_RDONLY);
	int		ft_errno = 0;
	int		std_errno = 0;
	errno = 0;
	bzero(buf, BUFFER);
	bzero(ft_buf, BUFFER);
	bzero(std_buf, BUFFER);

	printf(PURPLE "Entrée Standard :\n" RESET);
	fd = 0;
	ft = ft_read(fd, buf, BUFFER);
	strcpy(ft_buf, buf);
	ft_errno = errno;
	bzero(buf, BUFFER);
	errno = 0;
	write(fd, " | ", 3);
	std = read(fd, buf, BUFFER);
	strcpy(std_buf, buf);
	std_errno = errno;
	bzero(buf, BUFFER);
	errno = 0;
	write(fd, "\n", 1);
	printf(CYAN "Value ft_buf :		|" GREY "%s" CYAN "|\n" RESET, ft_buf);
	printf(CYAN "Value std_buf :		|" GREY "%s" CYAN "|\n" RESET, std_buf);
	printf(CYAN "Return ft_read :		%zd (%d)" RED " Errno = %d\n" RESET, ft, (int)ft, ft_errno);
	printf(CYAN "Return std read :		%zd (%d)" RED " Errno = %d\n" RESET, std, (int)std, std_errno);

	if (ft == std && !strcmp(ft_buf, std_buf) && ft_errno == std_errno)
		printf(GREEN "- Validé -\n\n" RESET);
	else
		printf(RED "- C'est raté là.. -\n\n" RESET);

	printf(PURPLE "Entrée FD :\n" RESET);
	fd = cus_fd;
	ft = ft_read(fd, buf, BUFFER);
	ft_errno = errno;
	strcpy(ft_buf, buf);
	bzero(buf, BUFFER);
	errno = 0;
	close(cus_fd);
	cus_fd = open("testage_file.txt", O_RDONLY);
	fd = cus_fd;
	std = read(fd, buf, BUFFER);
	std_errno = errno;
	strcpy(std_buf, buf);
	bzero(buf, BUFFER);
	errno = 0;
	printf(CYAN "Value ft_buf :		|" GREY "%s" CYAN "|\n" RESET, ft_buf);
	printf(CYAN "Value std_buf :		|" GREY "%s" CYAN "|\n" RESET, std_buf);
	printf(CYAN "Return ft_read :		%zd (%d)" RED " Errno = %d\n" RESET, ft, (int)ft, ft_errno);
	printf(CYAN "Return std read :		%zd (%d)" RED " Errno = %d\n" RESET, std, (int)std, std_errno);

	if (ft == std && !strcmp(ft_buf, std_buf) && ft_errno == std_errno)
		printf(GREEN "- Validé -\n\n" RESET);
	else
		printf(RED "- C'est raté là.. -\n\n" RESET);

	close(cus_fd);
	cus_fd = open("testage_file.txt", O_RDONLY);
	fd = cus_fd;

	printf(PURPLE " - Count = 42 :\n" RESET);
	fd = cus_fd;
	ft = ft_read(fd, buf, 42);
	ft_errno = errno;
	strcpy(ft_buf, buf);
	bzero(buf, BUFFER);
	errno = 0;
	close(cus_fd);
	cus_fd = open("testage_file.txt", O_RDONLY);
	fd = cus_fd;
	std = read(fd, buf, 42);
	std_errno = errno;
	strcpy(std_buf, buf);
	bzero(buf, BUFFER);
	errno = 0;
	printf(CYAN " - Value ft_buf :		|" GREY "%s" CYAN "|\n" RESET, ft_buf);
	printf(CYAN " - Value std_buf :		|" GREY "%s" CYAN "|\n" RESET, std_buf);
	printf(CYAN " - Return ft_read :		%zd (%d)" RED " Errno = %d\n" RESET, ft, (int)ft, ft_errno);
	printf(CYAN " - Return std read :		%zd (%d)" RED " Errno = %d\n" RESET, std, (int)std, std_errno);

	if (ft == std && !strcmp(ft_buf, std_buf) && ft_errno == std_errno)
		printf(GREEN "- Validé -\n\n" RESET);
	else
		printf(RED "- C'est raté là.. -\n\n" RESET);

	close(cus_fd);

	return;
}

void testage_strdup(void)
{
	printf(ORANGE "");
	printf("=========================\n");
	printf("|  Testage de strdup :  |\n");
	printf("=========================\n\n" RESET);

	char *str[] = {
		"",
		"Hallo",
		"TeStAgE iMpRoMpTuE",
		"1-5+4/1*8",
		NULL
	};

	for (int i = 0; str[i] != NULL; i++)
	{
		printf(YELLOW UNDERLINE "Chaine utilisée :" RESET YELLOW " |%s|" PURPLE " %p\n" RESET, str[i], str[i]);

		char *ft_dst = NULL;
		char *std_dst = NULL;

		ft_dst = ft_strdup(str[i]);
		std_dst = strdup(str[i]);

		printf(CYAN "Value ft_dst :		|%s|" PURPLE " %p\n" RESET, ft_dst, ft_dst);
		printf(CYAN "Value std_dst:		|%s|" PURPLE " %p\n" RESET, std_dst, std_dst);

		if (!strcmp(ft_dst, std_dst))
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);

		free(ft_dst);
		free(std_dst);
	}

	return;
}

int main()
{
	printf(GREEN "\nC'est l'heure du testage\n" RESET);
	getchar();

	testage_strlen();
	getchar();

	testage_strcpy();
	getchar();

	testage_strcmp();
	getchar();

	testage_write();
	getchar();

	testage_read();
	getchar();

	testage_strdup();
	getchar();

	printf(GREEN "c fini, c tout pété\n\n" RESET);

	return 0;
}