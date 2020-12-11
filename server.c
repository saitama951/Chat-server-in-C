#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "netinet/in.h"
#include "sys/socket.h"
#include "pthread.h"
#include "arpa/inet.h"

struct sockaddr_in q;
void Concurrent_thread(int *p)
{
	int id = *p;
	char x[100];
	while(1)
	{
		//sets the array value 0
		memset(x, 0, sizeof(x));

		//receives clients message
		recv(id, x, 100, 0);

		//prints the clients message
		printf("%s", x);

		//disconnects client from the server
		if(strcmp(x, "bye\n") == 0)
		{
			printf("%s disconnected!\n", inet_ntoa(q.sin_addr));
			pthread_exit(NULL);
		}
	}
}
int main()
{
	int sockID, netID;
	pthread_t t1;
	unsigned int len = sizeof(struct sockaddr_in);
	char x[100];

	//creating a socket and returning the socket id
	sockID = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	q.sin_family = PF_INET;
	q.sin_port = 8080;
	q.sin_addr.s_addr = INADDR_ANY;

	//bind the a name to a socket
	bind(sockID, (struct sockaddr *)&q, len);

	//waits for client
	listen(sockID, 5);

	while(1)
	{
		//accepts the network id of client
		netID = accept(sockID, (struct sockaddr *)&q, &len);
		printf("%s connected!\n",inet_ntoa(q.sin_addr));
		pthread_create(&t1, 0, (void *)Concurrent_thread,
		               (void *)&netID);
	}

	//waits until other threads don't complete their jobs.
	pthread_join(t1,NULL);
}
