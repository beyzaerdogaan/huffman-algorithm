//
// Created by Beyza on 23.12.2020.
//

#ifndef ASSIGNMENT_4_LAST_ENCODE_H
#define ASSIGNMENT_4_LAST_ENCODE_H

#include "BinaryTree.h"
#include "Decode.h"
#include <algorithm>
#include <utility>
#include <cctype>

class Encode {
public:
    Encode();
    Encode(std::string inputFile);
    ~Encode();

    std::fstream input; // fstream object for input file
    std::fstream treeFile; // fstream object for saving tree
    std::string message; // store the original message

    // frequency vector for initial states of binary trees and frequencies
    std::vector<std::pair<BinaryTree*, int>> frequencyVector;

    void createFinalTree();
    void encodeTree();
    void printEncodedMessage();
};

#endif //ASSIGNMENT_4_LAST_ENCODE_H
