#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <fstream>
#include <packet_functions_head.h>
#include <packet.h>

int main()
{


        size_t num;
        std::fstream src("src.txt");
        std::fstream dst("dst.txt");

        std::string str{std::istreambuf_iterator<char>{src}, std::istreambuf_iterator<char>{}};

        if (!src.is_open()){

        std::cout << "not open";
        return 1;
        }

        std::cout << "_____________________________" << std::endl;
        std::cout << "____TEXT PACKET HANDLER______" << std::endl;
        std::cout << "_____________________________" << std::endl;

        std::cout << "Enter number of packets: " << std::endl;
        std::cin >> num;
        std::cout << "1. ORIGINAL TEXT: " << std::endl;

        std::cout << "\n" << std::endl;

        std::cout << str << std::endl;
        std::vector<Packet> vec_of_packets = make_vector_packet(str, num);
        std::cout << "2. Created " << num << "packets: " << std::endl;
        std::cout << "\n" << std::endl;

        print_packets(vec_of_packets);

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(vec_of_packets.begin(), vec_of_packets.end(), g);
        std::cout << "3. Packets after shuffling: " << std::endl;
        std::cout << "\n" << std::endl;

        print_packets(vec_of_packets);

        sort_packet_vect(vec_of_packets);

        std::string reass_str = reassemble(vec_of_packets);
        std::cout << "\n" << std::endl;
        std::cout << "4. Reassembled string (" << reass_str.size() << " chars): " << reass_str << std::endl;

        std::cout << "\n" << std::endl;

        dst << reass_str;

        return 0;


}
