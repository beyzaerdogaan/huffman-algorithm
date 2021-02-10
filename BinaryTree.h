//
// Created by Beyza on 23.12.2020.
//

#ifndef ASSIGNMENT_4_LAST_BINARYTREE_H
#define ASSIGNMENT_4_LAST_BINARYTREE_H

#include <string>
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <fstream>

class BinaryTree {
private:
    struct TreeNode {
        char item;
        TreeNode* left;
        TreeNode* right;
        int frequency;
    };
    TreeNode* root;

public:
    BinaryTree();
    BinaryTree(char value);
    ~BinaryTree();

    std::map<std::string, std::string> encodingMap; // mapten unordered mape cevrildi

    char getRootItem();
    TreeNode* getRoot();
    void setFrequency(int frequency);
    void insertLeftNode(BinaryTree* binaryTree);
    void insertRightNode(BinaryTree* binaryTree);
    void encodeChars(const std::string& code, TreeNode* treeNode);
};

#endif //ASSIGNMENT_4_LAST_BINARYTREE_H
