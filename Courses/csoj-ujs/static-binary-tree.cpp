// Program: static-binary-tree.cpp
// Date: 2024.04.14
// Author: Nulla

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    char alpha;
    int lchild;
    int rchild;
    TreeNode(char a, int l, int r) : alpha(a), lchild(l), rchild(r) {}
};

unordered_map<char, int> index_map;

vector<TreeNode> buildTree() {
    vector<TreeNode> tree;
    char alpha;
    int lchild, rchild;
    while (true) {
        cin >> alpha;
        if (alpha == '#') break;
        cin >> lchild >> rchild;
        tree.emplace_back(alpha, lchild, rchild);
        index_map[alpha] = tree.size();
    }
    return tree;
}

void findNodeInfo(const vector<TreeNode> &tree, char key) {
    for (const TreeNode &node : tree) {
        if (node.alpha == key) {
            // Find parent node
            if (node.alpha != tree[0].alpha) {
                for (const TreeNode &temp : tree) {
                    if (temp.lchild == index_map[key] || temp.rchild == index_map[key]) {
                        cout << temp.alpha << endl;
                        break;
                    }
                }
            } else {
                cout << "NO PARENT" << endl;
            }

            // Find children node
            if (node.lchild != 0) {
                cout << index_map[node.lchild] << endl;
            } else {
                cout << "no lchild" << endl;
            }
            if (node.rchild != 0) {
                cout << index_map[node.rchild] << endl;
            } else {
                cout << "no rchild" << endl;
            }
            break; // No need to continue searching once found
        }
    }
}

void deleteSubTree(vector<TreeNode> &tree, char key) {
    for (TreeNode &node : tree) {

        if (node.alpha == key) {
            // Find the children
            if (node.lchild != 0) {
                deleteSubTree(tree, tree[node.lchild - 1].alpha);
            }
            if (node.rchild != 0) {
                deleteSubTree(tree, tree[node.rchild - 1].alpha);
            }

            node.alpha = '0';
            node.lchild = 0;
            node.rchild = 0;

            for (TreeNode &parent : tree) {
                if (parent.lchild == index_map[key]) {
                    parent.lchild = 0;
                } else if (parent.rchild == index_map[key]) {
                    parent.rchild = 0;
                }
            }

            break; // No need to continue searching once found
        }
    }
}

int main() {
    vector<TreeNode> tree = buildTree();

    char find_key, delete_key;
    cin >> find_key >> delete_key;
    findNodeInfo(tree, find_key);
    deleteSubTree(tree, delete_key);

    // Output the modified tree
    for (const auto &node : tree) {
        if (node.alpha != '0') {
            cout << node.alpha << " " << node.lchild << " " << node.rchild << endl;
        }
    }

    return 0;
}