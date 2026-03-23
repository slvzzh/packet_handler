#ifndef PACKET_H
#define PACKET_H
#include <cstdio>
#include <exception>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
struct Packet {
    Packet(size_t num, std::string data) : number(num), data_(data) {};



    size_t number;
    std::string data_;

};

struct PacketsNumberException : std::exception {
    private:
        std::string message;

    public:
    PacketsNumberException(std::string msg) : message(std::move(msg)) {}

         const char * what(){
             return message.c_str();
         }
};

struct EmptyFileException : std::exception {
    private:
        std::string message;

    public:

    EmptyFileException(std::string msg) : message(std::move(msg)) {}
         const char * what(){
             return message.c_str();
         }
};

#endif
