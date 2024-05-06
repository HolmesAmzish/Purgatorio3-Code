/*
 * Program: binary-tree-height.cpp
 * Date: 2024.05.06
 * Description: get the height of specific node
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

int GetHeight(TreeNode* root, char key) {
    if (root == nullptr) {
        return 0;
    }
    int level = 1;
    queue<TreeNode*> current_level;
    current_level.push(root);
    queue<TreeNode*> next_level;
    while (!next_level.empty() || (level == 1)) {
        if(level > 1)
            swap(current_level, next_level);
        while (!current_level.empty()) {
            TreeNode* current_node = current_level.front();

            if (current_node->value == key) {
                return level;
                break;
            }

            if (current_node->left != nullptr)
                next_level.push(current_node->left);
            if (current_node->right != nullptr)
                next_level.push(current_node->right);
            current_level.pop();
        }
        level++;
    }
    return -1;
}

int main() {
    string tree = "AB##CD#F##E##";
    int i = 0;
    char key = 'B';
    //cin >> tree >> key;
    cout << tree << endl;
    TreeNode* root = CreateTree(tree, i);
    cout << key << endl << GetHeight(root, key) << endl;
}