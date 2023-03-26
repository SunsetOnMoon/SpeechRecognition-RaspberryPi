//
// Created by artsem on 13.2.23.
//
#include "server.h"
#include "get_ip.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void start_server()
{
    char* ip = get_ip("wlp4s0");
    int port = 8080;

    struct sockaddr_in server_addr, client_addr;
    int server_sockfd;
    char buffer[DATA_SIZE];
    int e;

    server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sockfd < 0)
    {
        perror("[ERROR] Socket error.");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    e = bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (e < 0)
    {
        perror("[ERROR] Bind error.");
        exit(1);
    }

    printf("[STARTING] UDP File Server started.");
    write_file(server_sockfd, client_addr);
    printf("[SUCCESS] Data transfer complete.\n");
    printf("[CLOSING] Closing the server.\n");

    close(server_sockfd);
}

void write_file(int sockfd, struct sockaddr_in addr)
{
    char *filename = "server_audio.wav";
    int n;
    char buffer[DATA_SIZE];
    socklen_t addr_size;

    FILE *fp = fopen(filename, "w");
    while (1)
    {
        addr_size = sizeof(addr);
        n = recvfrom(sockfd, buffer, DATA_SIZE, 0, (struct sockaddr*)&addr, &addr_size);

        if (strcmp(buffer, "END") == 0)
            break;

        fprintf(fp, "%s", buffer);
        bzero(buffer, DATA_SIZE);
    }
    fclose(fp);
}