/*
 * File: binary-tree-width.cpp
 * Date: 2024.04.27
 * User: Nulla
 * Description: Print the binary tree by level order
 *              Get the width of a binary tree
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    char value;
    TreeNode *left, *right;
    TreeNode(char x) : value(x), left(nullptr), right(nullptr) {}
};

TreeNode* CreateTree(const string& tree, int& index) {
    if (index > tree.length() || tree[index] == '#') {
        ++index;
        return nullptr;
    }
    TreeNode* node = new TreeNode(tree[index++]);
    node->left = CreateTree(tree, index);
    node->right = CreateTree(tree, index);
    return node;
}

void PrintByLevel(TreeNode* root) {
    if (root == nullptr) 
        return;
    int level = 1;
    queue<TreeNode*> current_level;
    current_level.push(root);
    queue<TreeNode*> next_level;
    while (!next_level.empty() || (level == 1)) {
        if(level > 1) 
            swap(current_level, next_level);
        while (!current_level.empty()) {
            TreeNode* current_node = current_level.front();
            cout << current_node->value << ' ' << level << '\n';
            if (current_node->left != nullptr)
                next_level.push(current_node->left);
            if (current_node->right != nullptr)
                next_level.push(current_node->right);
            current_level.pop();
        }
        
        level++;
    }
}

int GetWidth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int level = 1;
    int max_width = 0;
    queue<TreeNode*> current_level;
    current_level.push(root);
    queue<TreeNode*> next_level;
    while (!next_level.empty() || (level == 1)) {
        if(level > 1) 
            swap(current_level, next_level);
        int current_width = 0;
        while (!current_level.empty()) {
            TreeNode* current_node = current_level.front();
            current_width++;
            if (current_node->left != nullptr)
                next_level.push(current_node->left);
            if (current_node->right != nullptr)
                next_level.push(current_node->right);
            current_level.pop();
        }
        max_width = max_width > current_width ? max_width : current_width;
        level++;
    }
    return max_width;
}

int main() {
    //string test_sample[3] = {"ABF###CD#G##E##", "AB#D##CE###", "ABC##D#E###"};
    int i = 0;
    string tree;
    cin >> tree;
    TreeNode* root = CreateTree(tree, i);
    PrintByLevel(root);
    cout << GetWidth(root);
    return 0;
}