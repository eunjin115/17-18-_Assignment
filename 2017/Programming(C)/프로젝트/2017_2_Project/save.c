#include "project.h"
void save(char * options, List * list)//save함수
{
	if (!strcmp(options, ""))
	{
		printf("input options\n");
		return;
	}
	
	FILE *mp, *dp, *ap;
	mp = fopen("movie_list", "w");
	dp = fopen("director_list", "w");
	ap = fopen("actor_list", "w");
	
	char * arg = (char *)malloc(sizeof(char) * 4);
	char * op = (char *)malloc(sizeof(char) * 7);
	char * op_f = (char *)malloc(sizeof(char) * 2);
	char * file_name = (char *)malloc(sizeof(char) * 20);
	*arg = '\0';
	*op = '\0';
	*op_f = '\0';
	*file_name = '\0';

	sscanf(options, "%[amd]%*[ ]%[tgdyransbm]%*[ ]-%[f]%*[ ]%[^\0]", arg, op, op_f, file_name);

	if (strcmp(arg, "m")){
		if (strcmp(op, "t")) 
			fprintf(mp, "%s", list->movie->title);
		else if (strcmp(op, "g")) 
			fprintf(mp, "%s", list->movie->genre);
		else if (strcmp(op, "d")) 
			fprintf(mp, "%s", list->movie->director);
		else if (strcmp(op, "y")) 
			fprintf(mp, "%d", list->movie->year);
		else if (strcmp(op, "r")) 
			fprintf(mp, "%d", list->movie->runtime);
		else if (strcmp(op, "a")) 
			fprintf(mp, "%s", list->movie->actor);
		fclose(mp);
	}
	else if (strcmp(arg, "d")) {
		if (strcmp(op, "n")) 
			fprintf(dp, "%s", list->director->director);
		else if (strcmp(op, "s")) 
			fprintf(dp, "%s", list->director->sex);
		else if (strcmp(op, "b")) 
			fprintf(dp, "%d", list->director->birth);
		else if (strcmp(op, "m")) 
			fprintf(dp, "%s", list->director->title);
		fclose(dp);
	}
	else if (strcmp(arg, "a")) {
		if (strcmp(op, "n")) 
			fprintf(ap, "%s", list->actor->actor);
		else if (strcmp(op, "s"))
			fprintf(ap, "%s", list->actor->sex);
		else if (strcmp(op, "b"))
			fprintf(ap, "%d", list->actor->birth);
		else if (strcmp(op, "m"))
			fprintf(ap, "%s", list->actor->title);
		fclose(ap);
	}

	free(arg);
	free(op);
	free(op_f);
	free(file_name);
}
