
#include <packet.h>

std::vector<Packet> make_vector_packet(std::string str, size_t num){
    if (str.size() == 0){
        throw EmptyFileException("Пустой файл");
    }

    if (str.size() < num || num <= 0){
        throw PacketsNumberException("Неверное число пакетов");
    }

    size_t size_of_packet = str.size() / num;
    std::vector<Packet> vec_of_packets;
    vec_of_packets.reserve(num);
    size_t pos = 0;
    std::string substring;
    for (size_t i = 0; i < num; ++i){
        if (i == num-1){
            substring = str.substr(pos);


        } else {
        substring = str.substr(pos, size_of_packet);
        }
        pos += size_of_packet;
        vec_of_packets.push_back(Packet(i, substring));
    }
    return vec_of_packets;
}

void print_packets(std::vector<Packet> vec){
    for(Packet packet : vec){
        std::cout << "[" << packet.number << "] " << packet.data_ << std::endl;

    }

}
void sort_packet_vect(std::vector<Packet> & vec){

    std::sort(vec.begin(), vec.end(), [](Packet a, Packet b){return a.number < b.number;});
}

std::string reassemble(std::vector<Packet> & vec){
    std::string result;
    for (Packet p : vec){
        result+=p.data_;
    }
    return result;
}
