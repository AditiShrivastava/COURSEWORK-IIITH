/*URL:https://leetcode.com/playground/new/binary-tree


Question:
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


*/


/*Method 1 :Mine */
class Solution {
public:
    /*This is a utility function for recursion*/
    vector<int> twoSumUtil(vector<int>& nums, int target, vector<int>::iterator it1, vector<int>::iterator it2,vector<int>& result,vector<int>& original) 
    {
        //if the sum of the values of the two iterators equals the target.
        if(*it1+*it2==target)
        {
            //i stores the index of the element pointed by iterator it1.find(element)-original.begin() gives the index of the first occurence of the element to be found.
            int i=find(original.begin(),original.end(),*it1)-original.begin();
            //I've taken x to overcome situations when the elements are repeated,we have to consider them distinct(Fir ex in [3,3] answer should be [0,1] if target is 6 and not [0,0]
            int x=0;
             //j stores the index of the element pointed by iterator it2.
            int j=find(original.begin(),original.end(),*it2)-original.begin();
            //to handle identical elements,we have minimised range of numbers in vector,if matching.
            while(i==j)
            {
                j=find(original.begin()+x,original.end(),*it2)-original.begin();
                x++;
            }
            //Clear the result vector if it contains some garbage due to previous function call.
            result.clear();
            //Push i,j to the result
            result.push_back(i);
            result.push_back(j);
            return result;
        }
        else if(*it1+*it2 > target)
        {
            twoSumUtil(nums,target,it1,it2-1,result,original);
        }
        else
            twoSumUtil(nums,target,it1+1,it2,result,original);
        
        return result;
        
    }
    
    
    /*This is the main function*/
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //original vector is created that stores the original vector content as the nums vector will be modified because of sorting.
        vector<int> original(nums);
        //result vector stores two indices that need to be returned.
        vector<int> result; 
        //it1 points to the first element in the nums vector.
        vector<int>::iterator it1=nums.begin();
        //it2 points to the last element in the nums vector.
        vector<int>::iterator it2=nums.end()-1;
        //sorting the nums vector
        sort(nums.begin(),nums.end());
        //call the twoSumUtil() function.
        return twoSumUtil(nums,target,it1,it2,result,original);
        
        

    }
};


/*Method 2 :Bhavi-Using Maps 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        // map for {element, index} key-value pair
        unordered_map<int, int> num_map;

        for (int i = 0; i < nums.size(); ++i)
        {
            // let x + num[i] = target
            // => x = (target - nums[i])
            // check whether (target - nums[i]) i.e. x is already inserted into the map
            // if it is present, then, the indices of (target - nums[i]) and nums[i] are pushed in
            // the result vector, else, index of nums[i] is inserted in the map in line 21.
            if(num_map.find(target - nums[i]) != num_map.end())
            {
                result.push_back(num_map[target - nums[i]]);
                result.push_back(i);
                break;
            }
          /*line21:*//* num_map[nums[i]] = i;
        }
        return result;
    }
};

*/
