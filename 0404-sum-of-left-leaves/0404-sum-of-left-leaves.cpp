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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int total = 0;

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            total += root->left->val;
        }

        total += sumOfLeftLeaves(root->left);
        total += sumOfLeftLeaves(root->right);

        return total;
    }
};
