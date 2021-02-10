//
// Created by Beyza on 23.12.2020.
//

#include "Encode.h"

Encode::Encode() {}

Encode::Encode(std::string inputFile)
{
    input.open(inputFile, std::ios::in);
    std::string line;
    while (getline(input, line))
    {
        std::transform(line.begin(), line.end(), line.begin(),
                       [](unsigned char c){ return std::tolower(c); }); // convert characters to lowercase
        message = line;
        // get frequency of every char and map
        std::unordered_map<char, int> frequency;
        for (const char &c: line) {
            frequency[c]++;
        }
        std::vector<std::pair<char, int>> v;
        std::copy(frequency.begin(), frequency.end(), std::back_inserter<std::vector<std::pair<char, int>>>(v));
        std::sort(v.begin(), v.end(), [](const std::pair<char, int>& left, const std::pair<char, int>& right) {
            if (left.second != right.second) { return left.second < right.second; }
            return left.first < right.first;
        });

        // turn the char values to binary trees and fill the frequencyVector with binary tree and frequency pairs
        for (auto const &pair: v) {
            BinaryTree* binaryTree = new BinaryTree(pair.first);
            binaryTree->setFrequency(pair.second);
            std::pair <BinaryTree*, int> newPair;
            newPair.first = binaryTree;
            newPair.second = pair.second;
            frequencyVector.push_back(newPair);
        }

    }
    input.close();
}

Encode::~Encode() {}

void Encode::createFinalTree()
{
    int size = frequencyVector.size()-1;
    for (int i = 0; i < size; i++)
    {
        // calculate new frequency
        int newFrequency = frequencyVector[0].second + frequencyVector[1].second;

        // create new binary tree
        BinaryTree* newBinaryTree = new BinaryTree;
        newBinaryTree->setFrequency(newFrequency); // NEW
        newBinaryTree->insertLeftNode(frequencyVector[0].first);
        newBinaryTree->insertRightNode(frequencyVector[1].first);

        // make the pair of merged trees and total frequency
        std::pair <BinaryTree*, int> newPair;
        newPair.first = newBinaryTree;
        newPair.second = newFrequency;
        frequencyVector.push_back(newPair); // push the new pair
        frequencyVector.erase(frequencyVector.begin()); // delete first pair
        frequencyVector.erase(frequencyVector.begin()); // delete second pair

        // sort the vector again
        std::sort(frequencyVector.begin(), frequencyVector.end(),
                  [](const std::pair<BinaryTree*, int>& left, const std::pair<BinaryTree*, int>& right) {
                      if (left.second != right.second) { return left.second < right.second; }
                      else if (left.first->getRootItem() == '\0' && right.first->getRootItem() != '\0') { return true; }
                      else if (left.first->getRootItem() != '\0' && right.first->getRootItem() == '\0') { return false; }
                      else if (left.first->getRootItem() == '\0' && right.first->getRootItem() == '\0') { return true; }
                      return left.first < right.first;
                  });
    }
}

void Encode::encodeTree() {
    frequencyVector.begin()->first->encodeChars("", frequencyVector.begin()->first->getRoot());
    treeFile.open("saveTree.txt" , std::ios::out);
    BinaryTree* b = frequencyVector.begin()->first;
    for (auto a : b->encodingMap)
    {
        treeFile << a.first << " " << a.second << std::endl; // write chars and encoding values to a file to store
    }
    treeFile.close();
}

void Encode::printEncodedMessage() {
    BinaryTree* b = frequencyVector.begin()->first;
    std::string coding;
    while (!message.empty())
    {
        coding += b->encodingMap[message.substr(0,1)];
        message.erase(message.begin());
    }
    std::cout << coding << std::endl;
}
