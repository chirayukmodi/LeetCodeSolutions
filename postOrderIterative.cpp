/* Algo Used:

1. Create a stack of type pair<TreeNode *, bool>.
2. while stack is not empty, pop the element from the stack.
3. If    it is a Leaf Element 
      OR if the boolean value associated with this
         element is true, 

         add this element to result. 
         Here bool value associated with the node will be
         true if it's left and right child are already processed.
         Other wise it will be false.
    Else
        set bool value to true and push again this element to stack.
        push it's left and/or right child to the stack with bool value
        as false.
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
    bool isLeaf(TreeNode *r)
    {
        return (!r->left && !r->right);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        stack< pair<TreeNode *,bool> > s;
        pair <TreeNode *,bool>p;
        TreeNode *t;
        vector <int>v;
        
        if (!root)
            return v;
            
        s.push(make_pair(root,false));
        while(!s.empty())
        {
            p = s.top();
            s.pop();
            t = get<0>(p);
            if (   get<1>(p)
                || (isLeaf(t)))
            {
                v.push_back(t->val);
                continue;
            }
            
            s.push(make_pair(t, true));
            
            if (t->right)
            {
                (  isLeaf(t->right)
                 ? s.push(make_pair(t->right, true))
                 : s.push(make_pair(t->right, false)));
            }
            if (t->left)
            {
                (  isLeaf(t->left)
                 ? s.push(make_pair(t->left, true))
                 : s.push(make_pair(t->left, false)));
            }
        }
        
        return v;
        
    }
};