#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


struct TreeNode {
    char alpha;
    int lchild;
    int rchild;
    TreeNode(char a, int l, int r) {
        alpha = a;
        lchild = l;
        rchild = r;
    }
};

unordered_map<char, int> index_map;

vector<TreeNode> CreateTree() {
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
            break;
        }
    }
}

void deleteSubtree(vector<TreeNode> &tree, char key) {
    vector<TreeNode>::iterator it = tree.begin();
    while (it != tree.end()) {
        if (it->alpha == key) {
            if (it->lchild != 0) {
                deleteSubtree(tree, tree[it->lchild - 1].alpha);
            } else if (it->rchild != 0) {
                deleteSubtree(tree, tree[it->rchild - 1].alpha);
            }
            it = tree.erase(it);
            break;
        }
        it++;
    }

}

int main() {
    vector<TreeNode> tree = CreateTree();
    int find_key, delete_key;
    cin >> find_key >> delete_key;
    findNodeInfo(tree, find_key);
    deleteSubtree(tree, delete_key);

    return 0;
}