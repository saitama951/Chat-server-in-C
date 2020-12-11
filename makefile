target: server.c client.c
	gcc -lpthread server.c -o server.out
	gcc client.c -o client.out
