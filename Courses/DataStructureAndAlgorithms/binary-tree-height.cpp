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

int GetHieght(TreeNode* root, char key) {

}

int main() {
    
}