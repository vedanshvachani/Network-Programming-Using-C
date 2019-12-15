#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
int main(){
	int client,server;
	struct sockaddr_in saddr,caddr;

	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	saddr.sin_family=AF_INET;
	saddr.sin_port=3012;
	
	server=socket(PF_INET,SOCK_STREAM,0);
	bind(server,(struct sockaddr *)&saddr,sizeof(saddr));

	listen(server,5);
	char d1[30], d2[30];
	int len=sizeof(caddr);
	while(1)
		client=accept(server,(struct sockaddr*)&caddr,&len);
		recv(client,d1,30,0);
		send(client,d1,30,0);
	}	
}
