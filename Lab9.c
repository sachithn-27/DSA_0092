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

void preorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    preorder(root);
}