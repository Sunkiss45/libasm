# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define ORANGE "\033[38;2;255;165;0m"

# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, char const *src);
int			ft_strcmp(char const *s1, char const *s2);

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

int main()
{
	printf(GREEN "\nC'est l'heure du testage\n" RESET);
	getchar();

	// testage_strlen();
	// getchar();

	// testage_strcpy();
	// getchar();

	testage_strcmp();
	getchar();

	printf(GREEN "c fini, c tout pété\n" RESET);
	getchar();

	return 0;
}