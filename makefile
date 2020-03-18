target: server.c client.c
	gcc -lpthread server.c -o server
	gcc client.c -o client
