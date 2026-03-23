#pragma once
#include <random>
#include <algorithm>
#include <packet.h>
std::vector<Packet> make_vector_packet(std::string str, size_t num);
void print_packets(std::vector<Packet> vec);
void sort_packet_vect(std::vector<Packet> & vec);
std::string reassemble(std::vector<Packet> & vec);
