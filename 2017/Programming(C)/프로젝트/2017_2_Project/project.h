#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#pragma warning(disable:4996)
typedef struct movie {
	int serial;
	int year;
	int runtime;
	char* title;
	char* genre;
	char* director;
	char* actor;
	struct movie* next;
}movie;
typedef struct director {
	int serial;
	char* director;
	char* sex;
	char* birth;
	char* title;
	struct director* next;
}director;
typedef struct actor {
	int serial;
	char* actor;
	char* sex;
	char* birth;
	char* title;
	struct actor* next;
}actor;
typedef struct list {
	movie * movie;
	director * director;
	actor * actor;
}List;
void file_loading(List *);
void input_command(char *, char *, char *);
void search(char *, List *);
void print(char *, List *);
void add(char *, List *);
void update(char *);
void delete(char *, List *);
void sort(char *);
void save(char *, List *);
void func(int);
