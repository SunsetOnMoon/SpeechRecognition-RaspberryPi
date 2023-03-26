//
// Created by artsem on 16.2.23.
//

#include "header.h"
#include <assert.h>
#include <string.h>

int fill_header(u_short seq, u_short ack, u_short offset, u_short flag, packet_t* packet)
{
    assert(offset <= 1024);
    assert(flag == ACK || flag == FIN || flag == (ACK|FIN));
    assert(packet!=0);
    packet->header.seq = seq;
    packet->header.ack = ack;
    packet->header.checksum = 0;
    packet->header.offset = offset;
    packet->header.flag = flag;
    return  0;
}

int fill_packet(u_char* src, packet_t* packet, u_short size)
{
    assert(size <= PAYLOAD_SIZE);
    memcpy(packet->payload, src, size);
    return 0;
}

int read_header(header_t* header, packet_t* packet)
{
    header_t* tmp = (header_t*)packet;
    header->seq = tmp->seq;
    header->ack = tmp->ack;
    header->offset = tmp->offset;
    header->flag = tmp->flag;
    return 0;
}

int read_packet(u_char* dest, packet_t* packet, u_short size)
{
    assert(size <= PAYLOAD_SIZE);
    memcpy(dest, packet->payload, size);
    return 0;
}
