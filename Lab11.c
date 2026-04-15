#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode* create(int data) {
    struct TreeNode* n = malloc(sizeof(struct TreeNode));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

struct TreeNode* find(struct TreeNode* root, int val) {
    if (root == NULL || root->data == val) return root;
    if (val < root->data)
        return find(root->left, val);
    return find(root->right, val);
}

void grandchildren(struct TreeNode* node) {
    if (node == NULL) return;
    if (node->left) {
        if (node->left->left) printf("%d ", node->left->left->data);
        if (node->left->right) printf("%d ", node->left->right->data);
    }
    if (node->right) {
        if (node->right->left) printf("%d ", node->right->left->data);
        if (node->right->right) printf("%d ", node->right->right->data);
    }
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);

    struct TreeNode* n = find(root, 20);
    grandchildren(n);
}