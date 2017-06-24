/* Algo used :
1. set iterator to index[0]. Here iterator
   will be pointing to index at which the 
   the array value is 0.
2. If at current position, array value is 0,
   do not increment the iterator. Continue
   the main loop.
3. If at current position, array value is non 0,
   and if the value at position, where currently
   iterator, is 0, swap the values. Here there 
   can be a case where value of array at position
   where iterator is currently may not be zero.
   For example array [1,2,3]. increment the itertor.

Note : Note that once we have found out 
       a 0 in the array, iterator will always 
       be at position where value of the array
       is 0.

       Example 1: 
       [1,2,3,0,6,7]

       Here 0 is adjacent to 6. So once
       we reach at 6, we will swap it with 0.
       So before swap value of i is 4 and 
       array[4] is 6, and value of j is 3
       and array[3] is 0. After swap arry[4] = 0
       and array[3] = 6.
 
       After swap
       [1,2,3,6,0,7]

       Now value of j is 4 and
       value of i is 5. Note that array[4] is 0. So
       iterator is at that position where array value is 0.

       Example 2:
       [1,2,0,0,6,7]
    
       Here 0 is adjacent to 6. So once
       we reach at 6, we will swap it with 0.
       So before swap value of i is 4 and 
       array[4] is 6, and value of j is 2
       and array[2] is 0. After swap arry[4] = 0
       and array[2] = 6.

       After swap
       [1,2,6,0,0,7]

       Now value of j is 3 and
       value of i is 5. Note that array[3] is 0. So
       iterator is at that position where array value is 0.

Complexity : O(n).
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int  j = 0;
        for (int i = 0;i<nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if (nums[j] == 0)
                    swap (nums[i], nums[j]);
                 j++;
            }
        }
    }
};