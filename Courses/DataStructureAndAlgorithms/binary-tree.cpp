#include <iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};


// 递归生成树
TreeNode* createTree(int value) {
    if (value == 0)
        return nullptr;

    TreeNode* root = new TreeNode(value);
    root->left = createTree(value - 1);
    root->right = createTree(value - 1);

    return root;
}

void printTree(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->value << ' ';
    printTree(root->left);
    printTree(root->right);
}

// 递归释放整棵树
void destoryTree(TreeNode* root) {
    if (root != NULL) {
        destoryTree(root->left);
        destoryTree(root->right);
        free(root);
    }
}

int main() {
    TreeNode* root = createTree(4);
    cout << "Tree values (preorder traversal): ";
    printTree(root);
    cout << endl;

    destoryTree(root);
    return 0;
}