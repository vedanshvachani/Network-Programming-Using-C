#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
int main(){
	int client;
	struct sockaddr_in saddr;

	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	saddr.sin_family=AF_INET;
	saddr.sin_port=3012;
	
	client=socket(PF_INET,SOCK_STREAM,0);
	connect(client,(struct sockaddr *)&saddr,sizeof(saddr));

	char d1[30], d2[30];
	
	printf("Enter the string");
	scanf("%s",d1);
	
	send(client,d1,30,0);
	
	recv(client,d2,30,0);
	printf("result: %s ",d2);
}
