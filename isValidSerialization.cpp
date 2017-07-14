/* Algo 
This problem is to tell whether given preorder representation of 
a binary tree is valid representation or not. Tree will be give like,

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #


Basic rule is, number of #s in the representation will be +1 then
the given values. 

no of #s = no of values + 1

But this should hold true only when we reach at the end of the string.
If 

no of #s = no of values + 1 and we have not reached till the end of the string,
this is not the correct preorder representation of the tree.

Here we start searching delimeter. Once we reach to a delimeter, we check the value
just before it. If it is '#', we decrement the count or else, we increment the count.
If count < 0 that means we have reach our 

no of #s = no of values + 1 condition.

If at this time we are not at the end of the string, return false.

Note that as we do not have delimeter after last value, we explicitly append ','
at the end so that we can also consider the last value.

*/


class Solution {
public:
    bool isValidSerialization(string preorder) 
    {
        if (!preorder.size())
            return false;
        
        preorder+=',';
        
        int cnt = 0,i;
        for (i = 0;i <preorder.size();i++)
        {
            if (preorder[i]!=',')
                continue;

            cnt = (  (preorder[i-1] == '#') 
                   ? cnt - 1
                   : cnt + 1);
            
            if (cnt<0)
                break;
        }
        
        return (cnt<0 && (i == preorder.size()-1));
    }
};