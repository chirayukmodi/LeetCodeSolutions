/* Algo Used

1. if root == NULL
    return true.
2. If left_child == NULL and right_child == NULL
    return true.
3.    If one of the child is NULL and other is not
   OR If left_child->val != right_child->val
      return false;
4. Recurse for (root->left->left, root->right->right)
           and (root->left->right, root->right->left)
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool isSymmetricUtil(TreeNode *r1, TreeNode *r2)
    {
        return (  (!r1 && !r2)
                ? true
                : (  (!r1 || !r2 || (r1->val != r2->val))
                   ? false 
                   : (   isSymmetricUtil(r1->left, r2->right) 
                      && isSymmetricUtil(r1->right, r2->left))));
    }
    bool isSymmetric(TreeNode* root) 
    {
        return (!root ? true
                      : isSymmetricUtil(root->left, root->right));
    }
};