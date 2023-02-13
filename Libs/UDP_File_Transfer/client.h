//
// Created by artsem on 13.2.23.
//

#ifndef SPEECHRECOGNITION_CLIENT_H
#define SPEECHRECOGNITION_CLIENT_H

#endif //SPEECHRECOGNITION_CLIENT_H

#include <stdio.h>
#include <arpa/inet.h>

#define DATA_SIZE 1024

void start_client(char* send_file_name);
void send_file_data(FILE *fp, int sockfd, struct sockaddr_in addr);
