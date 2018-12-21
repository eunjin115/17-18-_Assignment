#include "project.h"
void input_command(char * input, char * command, char * options)
{
	scanf("%[^\n]", input);
	getchar();
	sscanf(input, "%[^ ]%*[ ]%[^\0]", command, options);
}
