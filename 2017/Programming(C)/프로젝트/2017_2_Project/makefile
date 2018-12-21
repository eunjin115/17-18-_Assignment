project : main.o input_command.o search.o print.o add.o update.o delete.o sort.o save.o file_loading.o
	gcc -o project main.o input_command.o search.o print.o add.o update.o delete.o sort.o save.o file_loading.o
main : main.c project.h
	gcc -c -o main main.c project.h
input_command : input_command.c project.h
	gcc -c -o input_command input_command.c project.h
search : search.c project.h
	gcc -c -o search search.c project.h
print : print.c project.h
	gcc -c -o print print.c project.h
add : add.c project.h
	gcc -c -o add add.c project.h
update : update.c project.h
	gcc -c -o update update.c project.h
delete : delete.c project.h
	gcc -c -o delete delete.c project.h
sort : sort.c project.h
	gcc -c -o sort sort.c project.h
save : save.c project.h
	gcc -c -o save save.c project.h
file_loading : file_loading.c project.h
	gcc -c -o file_loading file-loading.c project.h
