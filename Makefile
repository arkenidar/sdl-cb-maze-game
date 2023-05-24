all: produce_executable execute_executable

produce_executable:
ifeq (Linux,$(shell uname))
	gcc -o app -g -Wall *.c $(shell sdl2-config --cflags --libs)
else
	gcc -o app -g -Wall *.c $(shell sdl2-config --cflags --libs) -mwindows
endif	

execute_executable:
	./app
