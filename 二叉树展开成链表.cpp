#include <iostream>
using namespace std;

struct NodeInfo {
    int val, left, right;
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(NodeInfo nodes[], int idx) {
    if (idx == 0) return nullptr;
    TreeNode* node = new TreeNode(nodes[idx].val);
    node->left = buildTree(nodes, nodes[idx].left);
    node->right = buildTree(nodes, nodes[idx].right);
    return node;
}

TreeNode* prevNode = nullptr;

void flatten(TreeNode* root) {
    if (!root) return;
    if (prevNode) {
        prevNode->right = root;
        prevNode->left = nullptr;
    }
    prevNode = root;
    TreeNode* left = root->left, *right = root->right;
    flatten(left);
    flatten(right);
}

int main() {
    int n;
    cin >> n;
    NodeInfo nodes[105];
    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].val >> nodes[i].left >> nodes[i].right;
    }
    TreeNode* root = buildTree(nodes, 1);
    flatten(root);
    TreeNode* p = root;
    while (p) {
        cout << p->val;
        if (p->right) cout << " ";
        p = p->right;
    }
    cout << endl;
    return 0;
}