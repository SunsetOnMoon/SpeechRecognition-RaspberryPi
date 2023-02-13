//
// Created by artsem on 13.2.23.
//
#include "client.h"
#include "get_ip.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void start_client(char* send_file_name)
{
    char* ip = get_ip("wlp4s0");
    int port = 8080;

    int server_sockfd;
    struct sockaddr_in server_addr;

    FILE *fp = fopen(send_file_name, "r");

    server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sockfd < 0)
    {
        perror("[ERROR] Socket error.");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip); //this is ip for client. Learn, how to know address of a server

    if (fp == NULL)
    {
        perror("[ERROR] Reading the file.");
        exit(1);
    }

    send_file_data(fp, server_sockfd, server_addr);

    printf("[SUCCESS] Data transfer complete.\n");
    printf("[CLOSING] Disconnecting from the server.\n");

    close(server_sockfd);
}

void send_file_data(FILE *fp, int sockfd, struct sockaddr_in addr)
{
    int n;
    char buffer[DATA_SIZE];

    while(fgets(buffer, DATA_SIZE, fp) != NULL)
    {
        n = sendto(sockfd, buffer, DATA_SIZE, 0, (struct sockaddr*)&addr, sizeof(addr));

        if (n == -1)
        {
            perror("[ERROR] Sending data to a server.");
            exit(1);
        }
        bzero(buffer, DATA_SIZE);
    }

    strcpy(buffer, "END");
    sendto(sockfd, buffer, DATA_SIZE, 0, (struct sockaddr*)&addr, sizeof(addr));

    fclose(fp);
}