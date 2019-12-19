// C program that stores a password in a variable. The client password is sent to the server after encrypting it.
// Server decrypts it with the key and authenticates the password. And sends a response to the user

#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
int main(){
	int client,server;
	//2 structures of socket that is defined in socket.h
	struct sockaddr_in saddr,caddr;

	char pass[] = "1234"; //password to crosscheck
	
	//ip-address
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	saddr.sin_family=AF_INET;
	//port number
	saddr.sin_port=3012;
	
	//socket connection for tcp
	server=socket(PF_INET,SOCK_STREAM,0);
	bind(server,(struct sockaddr *)&saddr,sizeof(saddr));

	listen(server,5);
	char d1[30], d2[30],d3[30];
	int i,random;
	int len=sizeof(caddr);
	while(1){
		client=accept(server,(struct sockaddr*)&caddr,&len);
		recv(client,d3,30,0);
		random=(atoi(d3)-5);
		recv(client,d1,30,0);
		for (i=0; d1[i]!='\0'; i++){
			d1[i]=d1[i]-random;
		}
		if(strcmp(pass,d1) == 0){
			for(i=0; d1[i]!='\0'; i++){
				d1[i]=d1[i]+1;
			}
			send(client,d1,30,0);
		}
		else{
			sprintf(d1,"Wrong password");
			send(client,d1,30,0);
		}
	}	
}
