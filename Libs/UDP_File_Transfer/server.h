//
// Created by artsem on 13.2.23.
//

#ifndef SPEECHRECOGNITION_SERVER_H
#define SPEECHRECOGNITION_SERVER_H

#endif //SPEECHRECOGNITION_SERVER_H

#include <arpa/inet.h>

#define DATA_SIZE 1024

void start_server();
void write_file(int sockfd, struct sockaddr_in addr);