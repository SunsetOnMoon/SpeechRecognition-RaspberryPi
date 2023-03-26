//
// Created by artsem on 20.2.23.
//

#ifndef SPEECHRECOGNITION_SERVER_H
#define SPEECHRECOGNITION_SERVER_H
#include <sys/socket.h>

void sigchld_handler(int s);
void *get_in_addr(struct sockaddr *sa);
int start_server(int argc, char** argv);

#endif //SPEECHRECOGNITION_SERVER_H
