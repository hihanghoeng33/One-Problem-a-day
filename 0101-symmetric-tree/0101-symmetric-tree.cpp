/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || checkboth(root->left, root->right);
    }
private:
    bool checkboth(TreeNode* left, TreeNode* right){
        if(left==nullptr && right==nullptr)
            return true;
        else if(left==nullptr || right==nullptr)
            return false;
        return (left->val==right->val) && checkboth(left->left, right->right) && checkboth(left->right, right->left);
    }
};