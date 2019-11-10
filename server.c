#include "netinet/in.h"
#include "sys/socket.h"
#include "pthread.h"
struct sockaddr_in q;
int Concurrent_thread(int *p) 
{
	int id=*p;
	char x[100];
	while(1)
	{
		memset(x,0,sizeof(x)); //sets the array value 0
		read(id,x,100); //receives clients message
		printf("%s\n",x); //prints the clients message
		if(strcmp(x,"bye")==0) //disconnects client from the server
		{
			printf("connection lost from %s \n",inet_ntoa(q.sin_addr.s_addr));
			pthread_exit(NULL);
		}
	}
}
main()
{
	int sid,nid;  //socket id,network id
	pthread_t t1; //thread variables
	int len = sizeof(struct sockaddr_in); 
	char x[100];
	sid = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP); //creating a socket and returning the socket id
	q.sin_family=PF_INET; 
	q.sin_port = 2000;
	q.sin_addr.s_addr=INADDR_ANY;
	bind(sid,&q,len); //bind the a name to a socket
	listen(sid,30); //waits for client
	while(1)
	{
		nid=accept(sid,&q,&len); //accepts the network id of client
		printf("connection from %s \n",inet_ntoa(q.sin_addr.s_addr));
		pthread_create(&t1,0,Concurrent_thread,&nid);// create a thread 
	}
	pthread_join(t1,NULL); //waits until other threads don't complete their jobs.

	

}
