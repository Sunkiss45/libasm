# include <string.h>
# include <stdio.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define ORANGE "\033[38;2;255;165;0m"
# define RESET "\033[0m"

size_t		ft_strlen(char *str);

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
	};

	for (int i = 0; str[i] != NULL; i++)
	{
		printf(YELLOW "Chaine utilisé : |%s|\n\n" RESET, str[i]);
		printf(BLUE "return ft_strlen :			%zu\n" RESET, ft_strlen(str[i]));
		printf(BLUE "return std strlen :		%zu\n" RESET, strlen(str[i]));

		if (strlen(str[i]) == ft_strlen(str[i]))
			printf(GREEN "- Validé -\n\n" RESET);
		else
			printf(RED "- C'est raté là.. -\n\n" RESET);
	}

	return;
}

int main()
{
	printf(GREEN "\nC'est l'heure du testage\n" RESET);
	getchar();

	testage_strlen(); // Tester ft_strlen
	getchar();

	printf(GREEN "c fini, c tout pété\n\n" RESET);
	getchar();

	return 0;
}