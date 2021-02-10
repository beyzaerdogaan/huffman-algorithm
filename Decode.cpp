//
// Created by Beyza on 23.12.2020.
//

#include "Decode.h"

Decode::Decode() {}

Decode::~Decode() {}

void Decode::decodeFromMap(const std::string& decode_input) {
    std::fstream treeInput;
    treeInput.open("saveTree.txt", std::ios::in); // open the file that we saved in encoding part to get encoding values
    std::string line;
    while(getline(treeInput, line))
    {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> vector;
        if (line.front() == ' ') // FOR SPACE CHARACTER
        {
            std::string string = line;
            vector.emplace_back(" ");
            string.erase(0,2);
            vector.push_back(string);
        }
        else
        {
            while(getline(ss, item, ' ')) {
                vector.push_back(item); // get chars and values and push them into a vector
            }
        }
        encodingVector.push_back(vector); // push the char-value vector into encodingVector
        vector.clear();
    }
    // fill the encodingMap with the chars and values we get from encodingVector
    // since encoding values are unique for each character, we can use them as keys and characters as values
    for (std::vector<std::string> a : encodingVector)
    {
        encodingMap[a[1]] = a[0];
    }
    treeInput.close();

    decodeInput.open(decode_input, std::ios::in);
    std::string line1;
    std::map<std::string,std::string>::iterator it;
    while(getline(decodeInput, line1))
    {
        int substrIndex = 1;
        while (!line1.empty())
        {
            std::string substr = line1.substr(0, substrIndex);
            it = encodingMap.find(substr); // search for matching key in encoding map to decode
            if (it != encodingMap.end()) // if key is found then print the char value of it
            {
                std::cout << encodingMap[substr];
                line1.erase(0, substrIndex); // erase the bits that belongs to the printed character from encoded message
                substrIndex = 1; // reinitialize the number of bits to be erased
            }
            else
            {
                substrIndex += 1; // if key is not found add one more bit from encoded message and search again
            }
        }
        std::cout << "\n";
    }
    decodeInput.close();
}
