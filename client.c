#include "netinet/in.h"
#include "sys/socket.h"
#include "string.h"

main()
{
	
	int sid,status,n=1;
	struct sockaddr_in q;
	int len = sizeof(struct sockaddr_in);
	char x[100];
	sid = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP); //socket creation
	q.sin_family=PF_INET;
	q.sin_port = 2000;
	q.sin_addr.s_addr=inet_addr("192.168.1.1");//IP of the server
	status = connect(sid,&q,len); //connects to the server
	if(status==-1) //if fails to connect to the server
	{
		printf("connection failed");
		exit(0);
	}
	while(1) 
	{
		printf("enter data to send----->");
		gets(x);
		write(sid,x,strlen(x)); //send data to the server
		
		if(strcmp(x,"bye")==0) //disconnect from the server
			break;
	}
		
	
}
