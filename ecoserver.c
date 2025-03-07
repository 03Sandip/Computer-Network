#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define SERVER_ADDR "0.0.0.0"
#define SERVER_PORT 15678
#define MAX_MSG 100

int main() {
    int sd, newsd, cli_len, n;
    char line[MAX_MSG];
    struct sockaddr_in cli_addr, serv_addr;

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    serv_addr.sin_port = htons(SERVER_PORT);

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("Error opening socket");
        return 1;
    }
    printf("Successfully created stream socket\n");

    if (bind(sd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Binding failed");
        return 1;
    }
    printf("Local Port Bound Successfully!!\n");

    listen(sd, 1);
    printf("Waiting for any Client to connect at server port %u\n", SERVER_PORT);

    while (1) {
        cli_len = sizeof(cli_addr);
        newsd = accept(sd, (struct sockaddr*)&cli_addr, &cli_len);
        if (newsd < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Connection established with client\n");

        do {
            memset(line, 0x0, MAX_MSG);
            n = recv(newsd, line, sizeof(line), 0);
            if (n < 0) {
                perror("Error in receiving data");
                break;
            }
            printf("Received from HOST: %s\n", line);
            send(newsd, line, n, 0);
        } while (strcmp(line, "quit") != 0);

        printf("Closing connection with host...\n");
        close(newsd);
        printf("\n\n");
    }

    close(sd);
    return 0;
}



