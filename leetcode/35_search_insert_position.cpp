/*Question 35 :
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2

Example 2:

Input: [1,3,5,6], 2
Output: 1

Example 3:

Input: [1,3,5,6], 7
Output: 4

Example 4:

Input: [1,3,5,6], 0
Output: 0

*/


/* My method*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        //creating dummy vector to not manipulate the original vector
        vector<int> dummy(nums);
        //find the index of target if found
        vector<int>::iterator it= find(dummy.begin(),dummy.end(),target);
        //if found ,return the index
        if(it!=dummy.end())
        return it-dummy.begin();
        //if not found,add the target in dummy array and return the index
        else
        {
            dummy.push_back(target);
            //sort the dummy array
            sort(dummy.begin(),dummy.end());
            return find(dummy.begin(),dummy.end(),target)-dummy.begin();
        }

    }
};
