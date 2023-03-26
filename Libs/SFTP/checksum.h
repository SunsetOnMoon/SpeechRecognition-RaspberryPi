//
// Created by artsem on 16.2.23.
//

#ifndef SPEECHRECOGNITION_CHECKSUM_H
#define SPEECHRECOGNITION_CHECKSUM_H
#include "header.h"

u_short add_checksum(u_short len_udp, int padding, const u_short *temp);
#endif //SPEECHRECOGNITION_CHECKSUM_H
