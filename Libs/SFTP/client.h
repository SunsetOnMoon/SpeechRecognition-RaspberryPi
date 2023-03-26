//
// Created by artsem on 20.2.23.
//

#ifndef SPEECHRECOGNITION_CLIENT_H
#define SPEECHRECOGNITION_CLIENT_H
#include <sys/socket.h>

int recvFromTimeOut(int socket, long sec, long usec);
int tftp(int sockfd, const void* packet, int expected_seqnum, int timeout, int flag);
void *get_in_addr(struct sockaddr *sa);
int start_client(int argc, char* argv[]);
#endif //SPEECHRECOGNITION_CLIENT_H
