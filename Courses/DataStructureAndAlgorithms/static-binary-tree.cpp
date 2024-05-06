// Program: static-binary-tree.cpp
// Date: 2024.04.15
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
                cout << tree.at(node.lchild - 1).alpha << endl;
            } else {
                cout << "no lchild" << endl;
            }
            if (node.rchild != 0) {
                cout << tree.at(node.rchild - 1).alpha << endl;
            } else {
                cout << "no rchild" << endl;
            }
            break;
        }
    }
}

bool deleteSubTree(vector<TreeNode> &tree, char key) {
    bool found = false;
    int index = 0;
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        if (it->alpha == key) {
            found = true;
            // Find the children
            if (it->lchild != 0) {
                deleteSubTree(tree, tree[it->lchild - 1].alpha);
            }
            if (it->rchild != 0) {
                deleteSubTree(tree, tree[it->rchild - 1].alpha);
            }

            for (TreeNode &parent : tree) {
                if (index_map[key] == parent.lchild) {
                    parent.lchild = 0;
                } else if (index_map[key] == parent.rchild) {
                    parent.rchild = 0;
                }
            }

            for (TreeNode &temp : tree) {
                if (temp.lchild > index) temp.lchild--;
                else if (temp.lchild == index + 1) temp.lchild = 0; // Update parent's lchild if it points to the deleted node
                if (temp.rchild > index) temp.rchild--;
                else if (temp.rchild == index + 1) temp.rchild = 0; // Update parent's rchild if it points to the deleted node
            }
            
            it = tree.erase(it); // Erase the node
            --it; // Move iterator back to point to the correct position
            break;
        }
        index++;
    }
    return found;
}



int main() {
    vector<TreeNode> tree = buildTree();

    char find_key, delete_key;
    cin >> find_key >> delete_key;
    findNodeInfo(tree, find_key);
    // Output the modified tree
    if (deleteSubTree(tree, delete_key)) {
        for (const auto &node : tree) {
            if (node.alpha != '0') {
                cout << node.alpha << " " << node.lchild << " " << node.rchild << endl;
            }
        }
    } else {
        cout << "ERROR" << endl;
    }

    return 0;
}