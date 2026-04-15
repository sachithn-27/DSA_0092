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

struct TreeNode* lca(struct TreeNode* root, int a, int b) {
    if (root == NULL) return NULL;
    if (root->data > a && root->data > b)
        return lca(root->left, a, b);
    if (root->data < a && root->data < b)
        return lca(root->right, a, b);
    return root;
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);

    struct TreeNode* ans = lca(root, 5, 15);
    printf("%d", ans->data);
}