//
// Created by Beyza on 23.12.2020.
//

#ifndef ASSIGNMENT_4_LAST_DECODE_H
#define ASSIGNMENT_4_LAST_DECODE_H

#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>

class Decode {
public:
    Decode();
    ~Decode();

    std::fstream decodeInput;
    std::vector<std::vector<std::string>> encodingVector;
    std::map<std::string, std::string> encodingMap;

    void decodeFromMap(const std::string& decode_input);

};

#endif //ASSIGNMENT_4_LAST_DECODE_H
