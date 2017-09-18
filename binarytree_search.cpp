#include <iostream>

bool find_node(TreeNode* root, int val) {
    if(root == nullptr) return false;
    if(root->value == val) {
        return true;
    }
    if(val < root->value) {
        return find_node(root->left, val);
    }
    else if (root->value < val) {
        return find_node(root->right, val);
    } 
    return false;
}
