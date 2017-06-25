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
Level Order Traversal using queue.
Datastructure used are : Queue, Pair.
First push root in the queue.
Till Queue is not empty
1. Pop the node from the queue.
2. If (this is the first node which we are visiting of this level)
       Push the vector which has the values of the nodes, we encountered
       in previous level in the result set And clear this vector so that
       we can add values of the nodes available at this level.
3. Push the value in the vector.
4. Push the Right child of the popped node in to the queue if it exists.
5. Push the left child of the popped node in the queue if it exists.
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <pair<TreeNode*,int>> q;
        vector<int>v;
        vector<vector<int>>V;
        
        if (!root)
            return V;
        q.push(make_pair(root, 0));
        int current = 0;
        
        while(!q.empty())
        {
            TreeNode * t = get<0>(q.front());
            int c = get<1>(q.front());
            q.pop();
            
            if (c != current)
            {
                V.push_back(v);
                v.resize(0);
                current = c;
            }
            
            v.push_back(t->val);
            if (t->left)
                q.push(make_pair(t->left,c+1));
            if (t->right)
                q.push(make_pair(t->right,c+1));
        }
        
        V.push_back(v);
        return V;
        
    }
};

/* Better Solution */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode *> q;
        int size;
        
        vector<vector<int>>V;
        
        if (!root)
            return V;
        q.push(root);
        size = 1;
        
        while(!q.empty())
        {
            vector<int>v;
            size  = q.size();
            
            for (int i=0;i<size;i++)
            {
                TreeNode * t = q.front();
                q.pop();
                v.push_back(t->val);
            
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            V.push_back(v);
        }
        return V;
        
    }
};