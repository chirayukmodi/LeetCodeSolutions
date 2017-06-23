/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* Algo Used : 

Here i have used Reverse Level Order Traversal.
Datastructure used are : Queue, Pair.

First push root in the queue.

Till Queue is not empty
1. Pop the node from the queue.
2. If (this is the first node which we are visiting of this level)
       push it into result set and update
       the current level visited. By maintaining, current level, 
       which we are visiting we can know that have we visited any node
       from level or not? If this is the first node then it will be part 
       of your result set (Here note that we are using reverse level order traversal).
3. Push the Right child of the popped node in to the queue if it exists.
4. Push the left child of the popped node in the queue if it exists.
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        queue <pair<TreeNode*,int>> q;
        vector<int>v;
        if (!root)
            return v;
        q.push(make_pair(root, 0));
        v.push_back(root->val);
        int current = 0;
        
        while(!q.empty())
        {
            TreeNode * t = get<0>(q.front());
            int c = get<1>(q.front());
            q.pop();
            
            if (c != current)
            {
                v.push_back(t->val);
                current = c;
            }
            
            if (t->right)
                q.push(make_pair(t->right,c+1));
            if (t->left)
                q.push(make_pair(t->left,c+1));
        }
        
        return v;
    }
};

/* Recursive Solution */

class Solution {
public:
    void rightSideViewUtil(TreeNode *root, vector<int>&v, int node_level)
    {
        if (!root)
            return;
        if (v.size() == node_level)
            v.push_back(root->val);
        
        rightSideViewUtil(root->right, v, node_level+1);
        rightSideViewUtil(root->left, v, node_level+1);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector <int>v;
        rightSideViewUtil(root,v,0);
        return v;
    }
};