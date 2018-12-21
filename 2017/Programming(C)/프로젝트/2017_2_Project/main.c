#include "project.h"
void func(int);
int main(void)
{
	List* list = (List *)malloc(sizeof(List));
	list->movie = NULL;
	char * input = (char *)malloc(sizeof(char)*30);
	char * command = (char *)malloc(sizeof(char)*7);
	char * options = (char *)malloc(sizeof(char)*20);
	*input = '\0';
	*command = '\0';
	*options = '\0';
	printf("Welcome to My Movie<< \n");
	file_loading(list);
	printf("You can use add, update, search, sort, save, end, commands. \n");
	signal(2, func);
	while(1)
	{
		printf("\n(movie) ");
		input_command(input, command, options);
		if (!strcmp(command, "search"))
		{
			search(options, list);
		}
		else if (!strcmp(command, "print"))
		{
			print(options, list);
		}
		else if (!strcmp(command, "add"))
		{
			add(options, list);
			/*int a;
			a = get_length(list);*/
		}
		else if (!strcmp(command, "update"))
		{
			update(options);
		}
		else if (!strcmp(command, "delete"))
		{
			delete(options, list);
		}
		else if (!strcmp(command, "sort"))
		{
			sort(options);
		}
		else if (!strcmp(command, "save"))
		{
			save(options, list);
		}
		else if (!strcmp(command, "end"))
		{
			break;
		}
		*input = '\0';
		*command = '\0';
		*options = '\0';
	}

	free(input);
	free(command);
	free(options);
	return 0;
}	
void func(int c) {
	char a;
	printf("Get Interrupt Signal.\n");
	printf("Do you want to exit myMOVIE program? (Y/N)");
	scanf("%c", &a);
	if (a == 'Y') {
		exit(1);
	}
	return;
}
