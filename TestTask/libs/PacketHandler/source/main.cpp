#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <fstream>
#include <packet.h>
#include <packet_functions_head.h>





int main(){
    size_t num;
    std::ifstream src("src.txt");
    std::string str{std::istreambuf_iterator<char>{src}, std::istreambuf_iterator<char>{}};

    if (!src.is_open()){

    std::cout << "not open";
    return 1;
    }

    std::cout << "_____________________________" << std::endl;
    std::cout << "____TEXT PACKET HANDLER______" << std::endl;

    std::cout << "Enter number of packets: " << std::endl;
    std::cin >> num;

    std::vector<Packet> vec_of_packets = make_vector_packet(str, num);
    std::cout << "Created " << num << "packets: " << std::endl;
    print_packets(vec_of_packets);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec_of_packets.begin(), vec_of_packets.end(), g);
    std::cout << "Packets after shuffling: " << std::endl;

    print_packets(vec_of_packets);

    sort_packet_vect(vec_of_packets);

    std::string reass_str = reassemble(vec_of_packets);
    std::cout << "Reassembled string (" << reass_str.size() << " chars): " << reass_str << std::endl;


    return 0;
}
