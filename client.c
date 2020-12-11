#include "netinet/in.h"
#include "sys/socket.h"
#include "string.h"
#include "stdio.h"
#include "arpa/inet.h"
#include "stdlib.h"

int main()
{

	int sid, status, n = 1;
	struct sockaddr_in q;
	int len = sizeof(q);
	char x[100];

	//socket creation
	sid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	// setting up the socket
	q.sin_family = PF_INET;
	q.sin_port = 8080;

	//IP of the server
	q.sin_addr.s_addr = inet_addr("192.168.29.6");
	status = connect(sid, (struct sockaddr *)&q, len);

	//if fails to connect to the server
	if(status == -1)
	{
		printf("connection failed");
		exit(0);
	}

	// communication
	while(1)
	{
		printf("> ");
		fgets(x, 99, stdin);

		//send data to the server
		send(sid, x, strlen(x), 0);

		//disconnect from the server
		if(strcmp(x, "bye\n") == 0)
			break;
	}


}
