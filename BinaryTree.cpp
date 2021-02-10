//
// Created by Beyza on 23.12.2020.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root = new TreeNode;
    root->item = '\0'; // item is null char for null nodes
    root->right = nullptr;
    root->left = nullptr;
}

BinaryTree::BinaryTree(char value) {
    root = new TreeNode;
    root->item = value;
    root->left = nullptr;
    root->right = nullptr;
}

BinaryTree::~BinaryTree() {}


void BinaryTree::insertLeftNode(BinaryTree* binaryTree) {
    if (root->left == nullptr)
    {
        root->left = binaryTree->root;
    }
    else
    {
        std::cout << "Invalid" << std::endl;
    }
}

void BinaryTree::insertRightNode(BinaryTree* binaryTree) {
    if (root->right == nullptr)
    {
        root->right = binaryTree->root;
    }
    else
    {
        std::cout << "Invalid" << std::endl;
    }
}

char BinaryTree::getRootItem() { // get the char in the root
    return root->item;
}

BinaryTree::TreeNode *BinaryTree::getRoot() { // get root of the binary tree
    return root;
}

void BinaryTree::setFrequency(int frequency) { // set the root of the binary tree as the frequency of tree
    root->frequency = frequency;
}

void BinaryTree::encodeChars(const std::string& code, TreeNode* treeNode) {
    // we are performing inorder traversal through the tree

    if (treeNode == nullptr) // if treeNode is empty, stop
    {
        return;
    }

    // if treeNode's right node and left node are nullptr, then it means that we reached a character
    else if (treeNode->left == nullptr && treeNode->right == nullptr)
    {
        std::string s(1, treeNode->item);
        encodingMap[s] = code; // map the character to it's new encoding value
        s.clear();
    }

    encodeChars(code + "0", treeNode->left);
    encodeChars(code + "1", treeNode->right);
}
