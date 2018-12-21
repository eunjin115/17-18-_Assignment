#include "project.h"
void sort(char * options)
{
	if (!strcmp(options, ""))
	{
		printf("input options\n");
		return;
	}

	char * arg = (char *)malloc(sizeof(char)*4);
	char * op = (char *)malloc(sizeof(char)*7);
	char * op_f = (char *)malloc(sizeof(char)*2);
	char * file_name = (char *)malloc(sizeof(char)*20);
	*arg = '\0';
	*op = '\0';
	*op_f = '\0';
	*file_name = '\0';

	sscanf(options, "%[amd]%*[ ]%[tgdyransbm]%*[ ]-%[f]%*[ ]%[^\0]", arg, op, op_f, file_name);

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
	printf("op_f : ==%s==\n", op_f);
	printf("file_name : ==%s==\n", file_name);
	printf("strlen(arg)+1 : %d\n", strlen(arg) + 1);
	printf("strlen(op)+1 : %d\n", strlen(op) + 1);
	printf("strlen(op_f)+1 : %d\n", strlen(op_f) + 1);
	printf("strlen(file_name)+1 : %d\n", strlen(file_name) + 1);

	if (!strcmp(arg, ""))
	{
		printf("input arg\n");
		free(arg);
		free(op);
		free(op_f);
		free(file_name);
		return;
	}
	if(!strcmp(op, ""))
	{
		printf("input op\n");
		free(arg);
		free(op);
		free(op_f);
		free(file_name);
		return;
	}
	if (!strcmp(op_f, ""))
	{
		// -f 옵션 사용하지 않음
		printf("no use op_f\n");
	}
	else
	{
		// -f 옵션 사용
		printf("use op_f\n");
		if(!strcmp(file_name, ""))
		{
			printf("input file_name\n");
			free(arg);
			free(op);
			free(op_f);
			free(file_name);
			return;
		}
	}

	free(arg);
	free(op);
	free(op_f);
	free(file_name);
	printf("end sort\n");
}
