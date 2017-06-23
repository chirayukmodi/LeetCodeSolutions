/* Problem Statement : 
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.

Algo Used : 

1. Multiply the given sum value with 10. Add node value in to sum. 
2. Recurse for left and right child with passing the sum value.
3. If we reach to leaf, return the sum.
4. If we reach to NULL node, return 0.
*/

class Solution {
public:
    
    bool isLeaf(TreeNode * r)
    {
        return (!(r->left || r->right));
    }
    int sumNumbersUtil(TreeNode * r, int sum = 0)
    {
        if (!r)
            return 0;
        sum = (sum * 10) + (r->val);
        return ((isLeaf(r)) ? sum
                            : ((sumNumbersUtil(r->left,sum)) + (sumNumbersUtil(r->right,sum))));
    }
    int sumNumbers(TreeNode* root)
    {
        return sumNumbersUtil(root);   
    }
};