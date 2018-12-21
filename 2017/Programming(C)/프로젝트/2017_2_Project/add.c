#include "project.h"
void add(char * options, List* list)//add함수
{
	if (!strcmp(options, ""))
	{
		printf("input options\n");
		return;
	}

	char * arg = (char *)malloc(sizeof(char) * 4);
	*arg = '\0';

	sscanf(options, "%[amd]", arg); //옵션으로 amd중 하나를읽어들임

	movie * p = (movie *)malloc(sizeof(movie));
	director * q = (director *)malloc(sizeof(director));
	actor * r = (actor *)malloc(sizeof(actor));
	if (!strcmp(options,"m")) {
		FILE *fp;
		//int i = 1;
		fp = fopen("movie_list", "a+w");//movie_list파일을 열어 정보들을 저장함
		if (list->movie == NULL) { //NULL을포인트하는 처음의 영화구조체를 if문에서 영화에 관한 정보를받고 이후 영화구조체에 저장할정보들을else문에서입력받음
			list->movie = (movie*)malloc(sizeof(movie));
			list->movie->title = (char*)malloc(sizeof(char) * 40);
			printf("title > ");
			gets(list->movie->title);
			fprintf(fp, "%s:", list->movie->title);
			list->movie->genre = (char*)malloc(sizeof(char) * 15);
			printf("genre > ");
			gets(list->movie->genre);
			fprintf(fp, "%s:", list->movie->genre);
			list->movie->director = (char*)malloc(sizeof(char) * 40);
			printf("director > ");
			gets(list->movie->director);
			fprintf(fp, "%s:", list->movie->director);
			printf("year > ");
			scanf("%d", &list->movie->year);
			fprintf(fp, "%d:", list->movie->year);
			printf("runtime > ");
			scanf("%d", &list->movie->runtime);
			fprintf(fp, "%d \n", list->movie->runtime);
			list->movie->next = NULL;
			p = list->movie;
			fclose(fp);
			return;
		}
		else {
			list->movie->next = (movie*)malloc(sizeof(movie));
			list->movie->next->title = (char*)malloc(sizeof(char) * 40);
			printf("title > ");
			gets(list->movie->next->title);
			fprintf(fp, "%s:", list->movie->next->title);
			list->movie->next->genre = (char*)malloc(sizeof(char) * 15);
			printf("genre > ");
			gets(list->movie->next->genre);
			printf("%s \n", list->movie->next->genre);
			fprintf(fp, "%s:", list->movie->next->genre);
			list->movie->next->director = (char*)malloc(sizeof(char) * 40);
			printf("director > ");
			gets(list->movie->next->director);
			fprintf(fp, "%s:", list->movie->next->director);
			printf("year > ");
			scanf("%d", &list->movie->next->year);
			fprintf(fp, "%d:", list->movie->next->year);
			printf("runtime > ");
			scanf("%d", &list->movie->next->runtime);
			fprintf(fp, "%d \n", list->movie->next->runtime);
			list->movie->next->next = NULL;
			list->movie = list->movie->next;// 현재 영화구조체가 다음 영화구조체를 참조할 수 있게함
			fclose(fp);
			return;
		}
	}
	else if (!strcmp(options, "d")) //add d
	{
		 FILE* dp;
   		 dp =fopen("direcor_list","a+w");//director_list파일을 열어 감독에 관한 정보들을 입력받는다
         if(list->director == NULL)
		 {
	         list->director = (director*)malloc(sizeof(director));
	         list->director->director = (char*)malloc(sizeof(char) * 40);
	         printf("director > ");
	         gets(list->director->director);
 			 fprintf(dp,"%s:",list->director->director);
 	         list->director->sex = (char*)malloc(sizeof(char) * 3);
	         printf("sex > ");
	         scanf("%c",list->director->sex);
	         fprintf(dp,"%c:",list->director->sex);
	         printf("birth > ");
	         scanf("%d", &list->director->birth);
	         getchar();	
	         fprintf(dp,"%d:",list->director->birth);
	         printf("title > ");
 	         scanf("%[^\n]",list->director->title);
        	 getchar();
 	         fprintf(dp,"%s:",list->director->title);
	         list->director->next = NULL;
	         q = list->director;
        	 fclose(dp);
		 }
	     else{
       	 	list->director->next=(director*)malloc(sizeof(director));//현재 감독구조체가 다음 감독구조체를 참조하기 위한 동적할당
       	 	list->director->next->director = (char*)malloc(sizeof(char)*20);
    	 	printf("director > ");
  	     	gets(list->director->next->director);
 	     	fprintf(dp,"%s:",list->director->next->director);
	     	list->director->next->sex = (char*)malloc(sizeof(char)*5);
	     	printf("sex > ");
    	 	scanf("%c",list->director->next->sex);
       	 	getchar();
    	 	printf("%s",list->director->next->sex);
     	 	fprintf(dp,"%c:",list->director->next->sex);
       	 	printf("birth > ");
      	 	scanf("%d",&list->director->next->birth);
      	 	fprintf(dp,"%d:",list->director->next->birth);
  	     	printf("title > ");
	     	scanf("%[^\n]",list->director->next->title);
     	 	getchar();
	     	fprintf(dp,"%s:",list->director->next->title);
    	 	list->director->next->next = NULL;
         	list->director = list->director->next;//현재 감독구조체가 다음 감독구조체를 참조할 수 있게함
         	fclose(dp);
         	return;
         }
    }

    else if (!strcmp(options,"a")) //add a
    {
        FILE *ap;
        ap=fopen("actor_list","a+w");//actor_list파일을 열어 actor에 관한 정보를 입력받는다
    	if(list->actor == NULL)
        {
        	list->actor=(actor*)malloc(sizeof(actor));
        	list->actor->actor=(char*)malloc(sizeof(char)*20);
        	list->actor->next=(actor*)malloc(sizeof(actor));
        	printf("actor > ");
        	scanf("%[^\n]",list->actor->actor);
        	getchar();
        	fprintf(ap,"%s:",list->actor->actor);
        	printf("sex > ");
        	scanf("%c", list->actor->sex);
        	getchar();
        	fprintf(ap,"%c:",list->actor->sex);
        	printf("birth > ");
        	scanf("%d", &list->actor->birth);
        	getchar();
        	fprintf(ap,"%d:",list->actor->birth);
        	printf("title > ");
        	scanf("%[^\n]", list->actor->title);
        	getchar();
        	fprintf(ap,"%s:",list->actor->title);
        	list->actor->next = NULL;
        	r = list->actor;
        }
        else
        {
            list->actor->next=(actor*)malloc(sizeof(actor));
            list->actor->next->actor=(char*)malloc(sizeof(char)*20);
            printf("actor > ");
            scanf("%[^\n]",list->actor->next->actor);
            getchar();
            fprintf(ap,"%s:",list->actor->next->actor);
            printf("sex > ");
            scanf("%[^\n]",list->actor->next->sex);
            getchar();
            fprintf(ap,"%c:",list->actor->next->sex);
            printf("birth > ");
        	scanf("%d",&list->actor->next->birth);
            fprintf(ap,"%d:",list->actor->next->birth);
            printf("title > ");
            scanf("%[^\n]", list->actor->next->title);
            getchar();
            fprintf(ap,"%s:",list->actor->next->title);
            list->actor->next->next = NULL;
            list->actor = list->actor->next;//배우구조체가 다음의 배우구조체를 참조하게함
            fclose(ap);
            return;
        }

    }
    free(p);
    free(q);
    free(r);
    free(list);
    free(arg);
}
