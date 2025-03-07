#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<arpa/inet.h>

#include<netdb.h>

#include<unistd.h>

#include<string.h>

#include<stdio.h>

#include<math.h>

#define SERVER ADDR "192.168.117.128"

#define SERVER_PORT 15678

#define MAX_MSG 100

int main()

{ int sd, newsd, cli_len,n; char line [MAX_MSG]; struct sockaddr_in cli_addr,serv_addr; bzero((char*) &serv_addr, sizeof(serv_addr)); serv_addr.sin_family = AF_INET; serv_addr.sin_addr.s_addr=inet_addr(SERVER_ADDR); serv_addr.sin port = htons(SERVER_PORT); sd=socket(AF_INET,SOCK_STREAM, 0);

printf("Successfully created stream socket\n"); bind(sd, (struct sockaddr*)&serv_addr, sizeof (serv_addr)); printf("Local Port Bound Successfully!!\n"); listen (sd,1);

while(1)

{ fflush(stdin); printf("Waiting for any Client to connect at server port...%u \n", SERVER_PORT); newsd = accept (sd, (struct sockaddr*)&cli_addr,&cli_len); fflush(stdin);

do

{ fflush(stdin); memset(line, 0x0, MAX_MSG); n=recv(newsd, line, (strlen(line)+1),0);

line[n]='\n';

printf("Recieved from HOST: %s\n", line); send(newsd, line, strlen(line)+1,0); fflush(stdin); }while(strcmp(line,"quit"));

printf("CLOSING connection with host....\n");

close(newsd); printf("\n\n"); }

return 0;

}
