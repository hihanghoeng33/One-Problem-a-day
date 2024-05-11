#include <stddef.h>
struct node
{
  int value;
  struct node* left;
  struct node* right;
};


int sumTheTreeValues(struct node* root) {
    if (root == NULL) {
        return 0; 
    } else {
        int leftSum = sumTheTreeValues(root->left);
        int rightSum = sumTheTreeValues(root->right);
        
        return root->value + leftSum + rightSum;
    }
}
