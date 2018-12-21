#include "project.h"
void delete(char * options, List * list)//delete함수
{
	if (!strcmp(options, ""))
	{
		printf("input options\n");
		return;
	}

	char * arg = (char *)malloc(sizeof(char) * 4);
	int num = -1;
	*arg = '\0';

	sscanf(options, "%[amd]%*[ ]%d", arg, &num);

	if (strcmp(arg, "m")) {
		list->movie = (movie *)malloc(sizeof(movie));
		FILE *mf = fopen("movie_log", "r");
		if (fscanf(mf, "%d", &list->movie->serial) == num) {

		}
		else
			printf("  No such record\n");
		fclose(mf);
	}
	else if (strcmp(arg, "d")) {
		list->director = (director *)malloc(sizeof(director));
		FILE *df = fopen("director_log", "r");
		if (fscanf(df, "%d", &list->director->serial) == num) {

		}
		else
			printf("  No such record\n");
		fclose(df);
	}
	else if (strcmp(arg, "a")) {
		list->actor = (actor *)malloc(sizeof(actor));
		FILE *af = fopen("actor_log", "r");
		if (fscanf(af, "%d", &list->actor->serial) == num) {

		}
		else
			printf("  No such record\n");
		fclose(af);
	}
	
	printf("arg : ==%s==\n", arg);
	for (int i = 0; i < strlen(arg); i++)
	{
		printf("*(arg + %d) : ==%c==\n", i, *(arg + i));
	}
	printf("num : %d\n", num);
	printf("strlen(arg)+1 : %d\n", strlen(arg) + 1);

	if (!strcmp(arg, ""))
	{
		printf("input arg\n");
		free(arg);
		return;
	}
	if (num < 0)
	{
		printf("input num\n");
		free(arg);
		return;
	}

	free(arg);
	printf("end delete\n");
}
