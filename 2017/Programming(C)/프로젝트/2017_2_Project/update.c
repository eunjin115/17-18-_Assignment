#include "project.h"
void update(char * options)
{
	if (!strcmp(options, ""))
	{
		printf("input options\n");
		return;
	}

	char * arg = (char *)malloc(sizeof(char)*4);
	char * op = (char *)malloc(sizeof(char)*7);
	int num = 0;
	*arg = '\0';
	*op = '\0';

	sscanf(options, "%[amd]%*[ ]%[tgdyransbm]%*[ ]%d", arg, op, &num);

	printf("arg : ==%s==\n", arg);
	for (int i = 0; i < strlen(arg); i++)
	{
		printf("*(arg + %d) : ==%c==\n", i, *(arg + i));
	}
	printf("op : ==%s==\n", op);
	for (int i = 0; i < strlen(op); i++)
	{
		printf("*(op + %d) : ==%c==\n", i, *(op + i));
	}
	printf("num : %d\n", num);
	printf("strlen(arg)+1 : %d\n", strlen(arg) + 1);
	printf("strlen(op)+1 : %d\n", strlen(op) + 1);

	if (!strcmp(arg, ""))
	{
		printf("input arg\n");
		free(arg);
		free(op);
		return;
	}
	if (!strcmp(op, ""))
	{
		printf("input op\n");
		free(arg);
		free(op);
		return;
	}
	free(arg);
	free(op);
	printf("end update\n");
}
