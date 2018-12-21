#include "project.h"
void file_loading(List * list)
{
	movie * l_movie = (movie *)malloc(sizeof(movie));
	movie * head_m = (movie *)malloc(sizeof(movie));
	
	director * l_director = (director *)malloc(sizeof(director));
	director * head_d = l_director;
	
	actor * l_actor = (actor *)malloc(sizeof(actor));
	actor * head_a = l_actor;
	
	list -> movie = (movie *)malloc(sizeof(movie));
	list -> movie = l_movie;
	list -> director = (director *)malloc(sizeof(director));
   	list -> director = l_director;
	list -> actor = (actor *)malloc(sizeof(actor));;
	list -> actor = l_actor;
	
	FILE * mlog_file, * alog_file, * dlog_file;

	printf("File loading......\n");
	mlog_file = fopen("movie_log", "r+w");
	if (mlog_file == NULL)
	{
		printf("no movie_log file\n");
		return;
	}
	rewind(mlog_file);
	char * m_command = (char *)malloc(sizeof(char)*10);
	char * m_options = (char *)malloc(sizeof(char)*90);
	int m_serial_number = 0;
	char * m_title = (char *)malloc(sizeof(char)*10);
	char * m_genre = (char *)malloc(sizeof(char)*10);
	char * m_director = (char *)malloc(sizeof(char)*10);
	char * m_year = (char *)malloc(sizeof(char)*10);
	char * m_time = (char *)malloc(sizeof(char)*10);
	char * m_actors = (char *)malloc(sizeof(char)*50);
	do
	{
		*m_command = '\0';
		m_serial_number = 0;
		*m_title = '\0';
		*m_genre = '\0';
		*m_director = '\0';
		*m_year = '\0';
		*m_time = '\0';
		*m_actors = '\0';
		fscanf(mlog_file, "%[^:]:%d:%[^\n\0]", m_command, &m_serial_number, m_options);

		if (!strcmp(m_command, "add"))
		{
			sscanf(m_options, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n\0]", m_title, m_genre, m_director, m_year, m_time, m_actors);
			if (list->movie == NULL)
			{
				list->movie -> serial = m_serial_number;
				list->movie -> title = (char *)malloc(sizeof(char)*10);
				list->movie -> title = m_title;
				list->movie -> genre = (char *)malloc(sizeof(char)*10);
				list->movie -> genre = m_genre;
				list->movie -> director = (char *)malloc(sizeof(char)*10);
				list->movie -> director = m_director;
				list->movie -> actor = (char *)malloc(sizeof(char)*50);
				list->movie -> actor = m_actors;
				list->movie -> next = NULL;
				head_m = list->movie;
			}
			else
			{
				list->movie -> next = (movie *)malloc(sizeof(movie));
				list->movie -> serial = m_serial_number;
				list->movie -> title = (char *)malloc(sizeof(char)*10);
				list->movie -> title = m_title;
				list->movie -> genre = (char *)malloc(sizeof(char)*10);
				list->movie -> genre = m_genre;
				list->movie -> director = (char *)malloc(sizeof(char)*10);
				list->movie -> director = m_director;
				list->movie -> actor = (char *)malloc(sizeof(char)*50);
				list->movie -> actor = m_actors;
				list->movie -> next -> next = NULL;
				list->movie = list->movie -> next;
			}
		}
		else if (!strcmp(m_command, "update"))
		{
			sscanf(m_options, "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n\0]", m_title, m_genre, m_director, m_year, m_time, m_actors);
			while (list->movie->serial == m_serial_number)
				list->movie = list->movie -> next;
			if (m_title != "=") 
				list->movie -> title = m_title;
			if (m_genre != "=")
				list->movie -> genre = m_genre;
			if (m_director != "=")
				list->movie -> director = m_director;
			if (m_actors != "=")
				list->movie -> actor = m_actors;
		}
		else if (!strcmp(m_command, "delete"))
		{
			l_movie = l_movie -> next -> next;
		}
		else break;
	}while (getc(mlog_file) == '\n');
	fclose(mlog_file);
	free(m_command);
	free(m_options);
	free(m_title);
	free(m_genre);
	free(m_director);
	free(m_year);
	free(m_time);
	free(m_actors);

	dlog_file = fopen("director_log", "r+w");
	if (dlog_file == NULL)
	{
		printf("no director_log file\n");
		return;
	}
	rewind(dlog_file);
	char * d_command = (char *)malloc(sizeof(char)*10);
	char * d_options = (char *)malloc(sizeof(char)*90);
	int d_serial_number = 0;
	char * d_name = (char *)malloc(sizeof(char)*10);
	char * d_sex = (char *)malloc(sizeof(char)*10);
	char * d_birth = (char *)malloc(sizeof(char)*10);
	char * d_best_movie = (char *)malloc(sizeof(char)*50);
	do
	{
		*d_command = '\0';
		d_serial_number = 0;
		*d_name = '\0';
		*d_sex = '\0';
		*d_birth = '\0';
		*d_best_movie = '\0';
		fscanf(dlog_file, "%[^:]:%d:%[^\n\0]", d_command, &d_serial_number, d_options);

		if (!strcmp(d_command, "add"))
		{
			sscanf(d_options, "%[^:]:%[^:]:%[^:]:%[^\n\0]", d_name, d_sex, d_birth, d_best_movie);
			if (list->director == NULL)
			{
				list->director -> serial = d_serial_number;
				list->director -> director = (char *)malloc(sizeof(char)*10);
				list->director -> director = d_name;
				list->director -> sex = (char *)malloc(sizeof(char)*10);
				list->director -> sex = d_sex;
				list->director -> birth = (char *)malloc(sizeof(char)*10);
				list->director -> birth = d_birth;
				list->director -> title = (char *)malloc(sizeof(char)*50);
				list->director -> title = d_best_movie;
				list->director -> next = NULL;
				head_d = list->director;
			}
			else
			{
				list->director -> next = (director *)malloc(sizeof(director));
				list->director -> serial = d_serial_number;
				list->director -> director = (char *)malloc(sizeof(char)*10);
				list->director -> director = d_name;
				list->director -> sex = (char *)malloc(sizeof(char)*10);
				list->director -> sex = d_sex;
				list->director -> birth = (char *)malloc(sizeof(char)*10);
				list->director -> birth = d_birth;
				list->director -> title = (char *)malloc(sizeof(char)*50);
				list->director -> title = d_best_movie;
				list->director -> next -> next = NULL;
				list->director = list->director -> next;
			}
		}
		else if (!strcmp(m_command, "update"))
		{
			sscanf(d_options, "%[^:]:%[^:]:%[^:]:%[^\n\0]", d_name, d_sex, d_birth, d_best_movie);
			
			while (list->director->serial == d_serial_number)
				list->director = list->director -> next;
			if (d_name != "=") 
				list->director -> director = d_name;
			if (d_sex != "=")
				list->director -> sex = d_sex;
			if (d_birth != "=")
				list->director -> birth = d_birth;
			if (d_best_movie != "=")
				list->director -> title = d_best_movie;
		}
		else if (!strcmp(m_command, "delete"))
		{
			list->director = list->director -> next -> next;
		}
		else break;
	}while (getc(dlog_file) == '\n');
	fclose(dlog_file);
	free(d_command);
	free(d_options);
	free(d_name);
	free(d_sex);
	free(d_birth);
	free(d_best_movie);

	alog_file = fopen("actor_log", "r+w");
	if (alog_file == NULL)
	{
		printf("no actor_log file\n");
		return;
	}
	rewind(alog_file);
	char * a_command = (char *)malloc(sizeof(char)*10);
	char * a_options = (char *)malloc(sizeof(char)*90);
	int a_serial_number = 0;
	char * a_name = (char *)malloc(sizeof(char)*10);
	char * a_sex = (char *)malloc(sizeof(char)*10);
	char * a_birth = (char *)malloc(sizeof(char)*10);
	char * a_best_movie = (char *)malloc(sizeof(char)*50);
	do
	{
		*a_command = '\0';
		a_serial_number = 0;
		*a_name = '\0';
		*a_sex = '\0';
		*a_birth = '\0';
		*a_best_movie = '\0';
		fscanf(alog_file, "%[^:]:%d:%[^\n\0]", a_command, &a_serial_number, a_options);

		if (!strcmp(a_command, "add"))
		{
			sscanf(a_options, "%[^:]:%[^:]:%[^:]:%[^\n\0]", a_name, a_sex, a_birth, a_best_movie);
			if (list->actor == NULL)
			{
				list->actor -> serial = a_serial_number;
				list->actor -> actor = (char *)malloc(sizeof(char)*10);
				list->actor -> actor = a_name;
				list->actor -> sex = (char *)malloc(sizeof(char)*10);
				list->actor -> sex = a_sex;
				list->actor -> birth = (char *)malloc(sizeof(char)*10);
				list->actor -> birth = a_birth;
				list->actor -> title = (char *)malloc(sizeof(char)*50);
				list->actor -> title = a_best_movie;
				list->actor -> next = NULL;
				head_a = list -> actor;
			}
			else
			{
				list->actor -> next = (actor *)malloc(sizeof(actor));
				list->actor -> serial = a_serial_number;
				list->actor -> actor = (char *)malloc(sizeof(char)*10);
				list->actor -> actor = a_name;
				list->actor -> sex = (char *)malloc(sizeof(char)*10);
				list->actor -> sex = a_sex;
				list->actor -> birth = (char *)malloc(sizeof(char)*10);
				list->actor -> birth = a_birth;
				list->actor -> title = (char *)malloc(sizeof(char)*50);
				list->actor -> title = a_best_movie;
				list->actor -> next -> next = NULL;
				list->actor = list->actor -> next;
			}
		}
		else if (!strcmp(a_command, "update"))
		{
			sscanf(a_options, "%[^:]:%[^:]:%[^:]:%[^\n\0]", a_name, a_sex, a_birth, a_best_movie);
			
			while (list->actor->serial == a_serial_number)
				list->actor = list->actor -> next;
			if (a_name != "=") 
				list->actor -> actor = a_name;
			if (a_sex != "=")
				list->actor -> sex = a_sex;
			if (a_name != "=")
				list->actor -> birth = a_birth;
			if (m_actors != "=")
				list->actor -> title = a_best_movie;
		}
		else if (!strcmp(a_command, "delete"))
		{
			list->actor = list->actor -> next -> next;
		}
		else break;
	}while (getc(alog_file) == '\n');
	fclose(alog_file);
	free(a_command);
	free(a_options);
	free(a_name);
	free(a_sex);
	free(a_birth);
	free(a_best_movie);

	free(list->actor);
	free(list->director);
	free(list->movie);
	free(l_actor);
	free(l_director);
	free(l_movie);
	free(list);
}
