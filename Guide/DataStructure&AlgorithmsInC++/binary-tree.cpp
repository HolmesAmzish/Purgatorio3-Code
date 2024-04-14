// file: binary-tree.cpp
// page: 278
// date: 2024.04.10
// description: the structure and  basic algorithms of a linked binary tree

#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode {
    int element;
    BinaryTreeNode* left_child;
    BinaryTreeNode* right_child;

    BinaryTreeNode() {left_child = right_child = NULL;}
    BinaryTreeNode(const int& value) {
        element = value;
        left_child = right_child = NULL;
    }
    BinaryTreeNode(const int& value, BinaryTreeNode* left, BinaryTreeNode* right) {
        element = value;
        left_child = left;
        right_child = right;
    }
};

BinaryTreeNode* createTree(int root_num);
void visit(BinaryTreeNode* x);
void printByPreOrder(BinaryTreeNode* root);
void printByLevelOrder(BinaryTreeNode* root);
int countTreeNodes(BinaryTreeNode* root);
int getTreeHeight(BinaryTreeNode* root);

int main() {
    cout << "Please input the number of root: ";
    int n; cin >> n;
    BinaryTreeNode* root = createTree(n);

    cout << "The nodes print by pre order:\n";
    printByPreOrder(root); cout << endl;
    cout << "The nodes print by level order:\n";
    printByLevelOrder(root); cout << endl;

    cout << "The number of nodes is: " << countTreeNodes(root) << endl;
    cout << "The height of tree is: " << getTreeHeight(root) << endl;

    return 0;
}

BinaryTreeNode* createTree(int root_num) {
    BinaryTreeNode* root;
    if (root_num == 0) {
        return NULL;
    } else {
        root = new BinaryTreeNode(root_num);
        root->left_child = createTree(root_num - 1);
        root->right_child = createTree(root_num - 1);
    }
    return root;
}

void visit(BinaryTreeNode* x) {
    cout << x->element << ' ';
}

void printByPreOrder(BinaryTreeNode* root) {
    if (root != NULL) {
        visit(root);
        printByPreOrder(root->left_child);
        printByPreOrder(root->right_child);
    }
}

void printByLevelOrder(BinaryTreeNode* root) {
    if (root == NULL)
        return;
    queue<BinaryTreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        BinaryTreeNode* current = queue.front();
        visit(current);
        queue.pop();
        if (current->left_child != NULL)
            queue.push(current->left_child);
        if (current->right_child != NULL)
            queue.push(current->right_child);
    }
}

// Count the number of nodes in the tree, similar to size()
int countTreeNodes(BinaryTreeNode* root) {
    if (root == 0) {
        return 0;
    } else {
        return 1 + countTreeNodes(root->left_child) + countTreeNodes(root->right_child);
    }
}

int getTreeHeight(BinaryTreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = getTreeHeight(root->left_child);
        int right_height = getTreeHeight(root->right_child);
        return 1 + max(left_height, right_height);
    }
}
