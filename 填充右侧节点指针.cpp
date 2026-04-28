//
// Created by icyw on 2026/4/24.
//

#include <iostream>
using namespace std;

const int MAXN = 105;

struct Node {
    int val;
    Node *left, *right, *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
} nodePool[MAXN];

int leftIdx[MAXN], rightIdx[MAXN];

void connect(Node* root) {
    if (!root || !root->left || !root->right) return;
    root->left->next = root->right;
    if (root->next)
        root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int val, l, r;
        cin >> val >> l >> r;
        nodePool[i].val = val;
        leftIdx[i] = l;
        rightIdx[i] = r;
    }
    for (int i = 1; i <= n; ++i) {
        nodePool[i].left = (leftIdx[i] ? &nodePool[leftIdx[i]] : nullptr);
        nodePool[i].right = (rightIdx[i] ? &nodePool[rightIdx[i]] : nullptr);
        nodePool[i].next = nullptr;
    }
    Node* root = &nodePool[1];

    connect(root);

    for (int i = 1; i <= n; ++i) {
        int nextId = 0;
        if (nodePool[i].next) {
            for (int j = 1; j <= n; ++j) {
                if (&nodePool[j] == nodePool[i].next) {
                    nextId = j;
                    break;
                }
            }
        }
        cout << nextId << endl;
    }
    return 0;
}