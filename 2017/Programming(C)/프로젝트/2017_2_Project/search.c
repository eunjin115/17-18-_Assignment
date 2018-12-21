#include "project.h"
#define EMPTY -1
#define MAX_LEN 30
#define FULL (MAX_LEN-1)
typedef struct stack
{
	char * s;
	int top;
} stack;
static stack s;
void reset() {
	s.top = EMPTY;
}
void push(char c) {
	s.top++;
	*(s.s + s.top) = c;
}
char pop(void) {
	return *(s.s +s.top--);
}
bool empty(void) {
	return (s.top == EMPTY);
}
bool full(void) {
	return (s.top == FULL);
}
void search(char * options, List * list)
{
	if (!strcmp(options, ""))
	{
		printf("input options\n");
		return;
	}
	
	char * op = (char *)malloc(sizeof(char)*4);
	char * string = (char *)malloc(sizeof(char)*MAX_LEN);
	*op = '\0';
	*string = '\0';

	sscanf(options, "-%[amd]%*[ ]%[^\0]", op, string);

	if (!strcmp(op, ""))
	{
		printf("input op\n");
		free(op);
		free(string);
		return;
	}
	if (!strcmp(string, ""))
	{
		printf("input string\n");
		free(op);
		free(string);
		return;
	}
	char * comp_str = (char *)malloc(sizeof(char)*MAX_LEN);

	for (int l = 0; l < strlen(op); l++)
	{
		if (*(op+l) == 'a')
		{
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i) == '?')
				{
					for (int j = 32; j < 127; j++)
					{
						while (list -> actor -> next != NULL)
						{
							*(string + i) = j;
							if (!strcmp(string, list->actor->actor))
								printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
							if (!strcmp(string, list->actor->sex))
								printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
							if (!strcmp(string, list->actor->birth))
								printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
							if (!strcmp(string, list->actor->title))
								printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
						}
					}
				}
			}
			if (*(string + strlen(string)-1) == '*')
			{
				sscanf(string, "%[^*]", comp_str);
				// strncmp 이용 리스트 전체의 내용과 comp_str 비교
				while (list->actor->next != NULL)
				{
					if (!strncmp(comp_str, list->actor->actor, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					if (!strncmp(comp_str, list->actor->birth, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					if (!strncmp(comp_str, list->actor->sex, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					if (!strncmp(comp_str, list->actor->title, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					list -> actor = list->actor ->next;
				}
			}
			else if (*string == '*')
			{
				char * r_comp_str = (char *)malloc(sizeof(char)*MAX_LEN);
				char * r_list = (char *)malloc(sizeof(char)*MAX_LEN);
				s.s = (char *)malloc(sizeof(char)*MAX_LEN);
				reset();
				sscanf(string, "*%[^\0]", comp_str);
				reset();
				for (int i = 0; i < strlen(comp_str); i++)
				{
					if (!full())
						push(*(comp_str + i));
				}
				for (int j = 0; !empty(); j++)
				{
					*(r_comp_str + j) = pop();
				}
				// 리스트 내용 역전해 r_list 만든 후 strncmp 이용 r_list 내용과 r_comp_str 비교
				while (list->actor->next != NULL)
				{
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->actor->actor + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->actor->birth + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->actor->sex + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->actor->title + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					list -> actor = list->actor ->next;
				}
				free(r_comp_str);
				free(r_list);
			}
			else
			{
				while (list->actor->next != NULL)
				{
					if (!strcmp(string, list->actor->actor))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					if (!strcmp(string, list->actor->birth))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					if (!strcmp(string, list->actor->sex))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					if (!strcmp(string, list->actor->title))
						printf("%d:%s:%s:%s:%s\n", list->actor->serial, list->actor->actor, list->actor->sex, list->actor->birth, list->actor->title);
					list -> actor = list->actor ->next;
				}
			}
		}
		if (*(op+l) == 'd')
		{
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i) == '?')
				{
					for (int j = 32; j < 127; j++)
					{
						while (list -> director -> next != NULL)
						{
							*(string + i) = j;
							if (!strcmp(string, list->director->director))
								printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
							if (!strcmp(string, list->director->sex))
								printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
							if (!strcmp(string, list->director->birth))
								printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
							if (!strcmp(string, list->director->title))
								printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
						}
					}
				}
			}
			if (*(string + strlen(string)-1) == '*')
			{
				sscanf(string, "%[^*]", comp_str);
				// strncmp 이용 리스트 전체의 내용과 comp_str 비교
				while (list->director->next != NULL)
				{
					if (!strncmp(comp_str, list->director->director, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					if (!strncmp(comp_str, list->director->birth, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					if (!strncmp(comp_str, list->director->sex, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					if (!strncmp(comp_str, list->director->title, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					list -> director = list->director ->next;
				}
			}
			else if (*string == '*')
			{
				char * r_comp_str = (char *)malloc(sizeof(char)*MAX_LEN);
				char * r_list = (char *)malloc(sizeof(char)*MAX_LEN);
				s.s = (char *)malloc(sizeof(char)*MAX_LEN);
				reset();
				sscanf(string, "*%[^\0]", comp_str);
				reset();
				for (int i = 0; i < strlen(comp_str); i++)
				{
					if (!full())
						push(*(comp_str + i));
				}
				for (int j = 0; !empty(); j++)
				{
					*(r_comp_str + j) = pop();
				}
				// 리스트 내용 역전해 r_list 만든 후 strncmp 이용 r_list 내용과 r_comp_str 비교
				while (list->actor->next != NULL)
				{
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->director->director + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->director->birth + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->actor->sex + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->director->title + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					list -> director = list->director ->next;
				}
				free(r_comp_str);
				free(r_list);
			}
			else
			{
				while (list->director->next != NULL)
				{
					if (!strcmp(string, list->director->director))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					if (!strcmp(string, list->director->birth))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					if (!strcmp(string, list->director->sex))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					if (!strcmp(string, list->director->title))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					list -> director = list->director ->next;
				}
			}
		}
		if (*(op+l) == 'm')
		{
			for (int i = 0; i < strlen(string); i++)
			{
				if (*(string + i) == '?')
				{
					for (int j = 32; j < 127; j++)
					{
						while (list -> movie -> next != NULL)
						{
							*(string + i) = j;
							if (!strcmp(string, list->movie->title))
								printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
							if (!strcmp(string, list->movie->genre))
								printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
							if (!strcmp(string, list->movie->director))
								printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
							if (!strcmp(string, list->movie->actor))
								printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
						}
					}
				}
			}
			if (*(string + strlen(string)-1) == '*')
			{
				sscanf(string, "%[^*]", comp_str);
				// strncmp 이용 리스트 전체의 내용과 comp_str 비교
				while (list->movie->next != NULL)
				{
					if (!strncmp(comp_str, list->movie->title, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
					if (!strncmp(comp_str, list->movie->genre, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
					if (!strncmp(comp_str, list->movie->director, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
					if (!strncmp(comp_str, list->movie->actor, sizeof(comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
					list -> movie = list->movie ->next;
				}
			}
			else if (*string == '*')
			{
				char * r_comp_str = (char *)malloc(sizeof(char)*MAX_LEN);
				char * r_list = (char *)malloc(sizeof(char)*MAX_LEN);
				s.s = (char *)malloc(sizeof(char)*MAX_LEN);
				reset();
				sscanf(string, "*%[^\0]", comp_str);
				reset();
				for (int i = 0; i < strlen(comp_str); i++)
				{
					if (!full())
						push(*(comp_str + i));
				}
				for (int j = 0; !empty(); j++)
				{
					*(r_comp_str + j) = pop();
				}
				// 리스트 내용 역전해 r_list 만든 후 strncmp 이용 r_list 내용과 r_comp_str 비교
				while (list->movie->next != NULL)
				{
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->movie->title + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->movie->genre + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->movie->director + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
					reset();
					for (int i = 0; i < strlen(comp_str); i++)
					{
						if (!full())
							push(*(list->movie->director + i));
					}
					for (int j = 0; !empty(); j++)
					{
						*(r_list + j) = pop();
					}
					if (!strncmp(r_comp_str, r_list, sizeof(r_comp_str)))
						printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
					list -> movie = list->movie ->next;
				}
				free(r_comp_str);
				free(r_list);
			}
			else
			{
				while (list->director->next != NULL)
				{
					if (!strcmp(string, list->movie->title))
						printf("%d:%s:%s:%s:%s\n", list->movie->serial, list->movie->title, list->movie->genre, list->movie->director, list->movie->actor);
					if (!strcmp(string, list->movie->genre))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					if (!strcmp(string, list->movie->director))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					if (!strcmp(string, list->movie->actor))
						printf("%d:%s:%s:%s:%s\n", list->director->serial, list->director->director, list->director->sex, list->director->birth, list->director->title);
					list -> director = list->director ->next;
				}
			}
		}
	}
	free(comp_str);
	free(op);
	free(string);
}
