// C program that takes a random key, encrypts that password with the random key and sends it to the server
// Then the server cross checks the password and sends it back to the client and client has to decrypt it with the same key
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

	char d1[30], d2[30],d3[30];
	int i;
	int random=rand();
	sprintf(d3,"%d",random+5);
	send(client,d3,30,0);
	printf("Enter the Password");
	scanf("%s",d1);
	for (i=0; d1[i]!='\0'; i++){
		d1[i]=d1[i]+random;
	}
	send(client,d1,30,0);
		
	recv(client,d2,30,0);
	
	for(i=0; d2[i]!='\0'; i++){
		d2[i]=d2[i]-1;
	}
	
	printf("\nresult: %s ",d2);
}
