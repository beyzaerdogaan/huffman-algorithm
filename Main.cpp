#include <iostream>
#include "Encode.h"
#include <cstring>
#include <algorithm>

int main(int argc, char **argv) {
    if (strcmp(argv[1], "-i") == 0)
    {
        if (strcmp(argv[3], "-encode") == 0)
        {
            Encode* anEncode = new Encode(argv[2]);
            anEncode->createFinalTree();
            anEncode->encodeTree();
            anEncode->printEncodedMessage();
        }
        else if (strcmp(argv[3], "-decode") == 0)
        {
            Decode* decode = new Decode;
            decode->decodeFromMap(argv[2]);
        }
    }
    else if (strcmp(argv[1], "-s") == 0)
    {
        std::fstream file;
        file.open("saveTree.txt", std::ios::in);
        std::string line;
        while (getline(file, line))
        {
            std::stringstream ss(line);
            std::string item;
            std::vector<std::string> vector;
            while(getline(ss, item, ' ')) {
                vector.push_back(item);
            }
            if (vector[0] == argv[2])
            {
                std::cout << vector[1] << std::endl;
            }
            vector.clear();
        }
        file.close();
    }
    else if (strcmp(argv[1], "-l") == 0)
    {
        std::fstream file;
        file.open("saveTree.txt", std::ios::in);
        std::string line;
        std::map<std::string, std::string> map;
        while (getline(file, line)) {
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
                while (getline(ss, item, ' ')) {
                    vector.push_back(item);
                }
            }
            map[vector[1]] = vector[0];
            vector.clear();
        }
        file.close();
        std::vector<std::string> branches;
        std::cout << "+-root" << std::endl;
        for (const auto& i : map)
        {
            std::string branch;
            for (char c : i.first)
            {
                std::string s(1,c);
                branch.append(s);
                if (!(std::find(branches.begin(), branches.end(), branch) != branches.end()))
                {
                    for (int k = 1; k < branch.length(); k++)
                    {
                        std::cout << "|  ";
                    }
                    branches.push_back(branch);
                    std::cout << "|  +- branch_" << branch << std::endl;
                }
            }
            for (int j = 0; j < i.first.length(); j++)
            {
                std::cout << "|  ";
            }
            std::cout << "|- child_'" << i.second << "'" << std::endl;
        }
    }
    return 0;
}
