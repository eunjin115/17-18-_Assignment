#include "project.h"
void print(char * options, List* list) //print함수
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
	
	if (!strcmp(arg, ""))
	{
		printf("input arg\n");
		free(arg);
		return;
	}
	else if (!strcmp(arg, "m")) {
		printf("%s, ", list->movie->title);
		printf("%s \n", list->movie->genre);
		printf("D : %s \n", list->movie->director);
		while (list->movie->next != NULL) {
			printf("%s, ", list->movie->next->title);
			printf("%s \n", list->movie->next->genre);
			printf("D : %s \n", list->movie->next->director);
			list->movie = list->movie->next;
		}
		printf("%s, ", list->movie->title);
		printf("%s \n", list->movie->genre);
		printf("D : %s \n", list->movie->director);
		return;
	}

	free(arg);
	printf("end print\n");
}
