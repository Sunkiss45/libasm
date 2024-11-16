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

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, char const *src);
int			ft_strcmp(char const *s1, char const *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);

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

		printf(CYAN "Valeur de ft_dst avec ft_strcpy :		|%s|" PURPLE " %p\n" RESET, ft_dst, ft_dst);
		printf(CYAN "Return de ft_strcpy :				|%s|" PURPLE " %p\n" RESET, ft_dst_ret, ft_dst_ret);
		printf(CYAN "Valeur de std_dst avec std strcpy :		|%s|" PURPLE " %p\n" RESET, std_dst, std_dst);
		printf(CYAN "Return de std strcpy :				|%s|" PURPLE " %p\n" RESET, std_dst_ret, std_dst_ret);

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
		write(fd, " - ", 3);
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
		write(fd, " - ", 3);
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
		write(fd, " - ", 3);
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
		write(fd, " - ", 3);
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

int main()
{
	printf(GREEN "\nC'est l'heure du testage\n" RESET);
	getchar();

	// testage_strlen();
	// getchar();

	// testage_strcpy();
	// getchar();

	// testage_strcmp();
	// getchar();

	testage_write();
	getchar();

	printf(GREEN "c fini, c tout pété\n\n" RESET);

	return 0;
}