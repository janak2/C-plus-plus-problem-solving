/**
 *Q. Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
 *
 */

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool found = false;
        int a=0,b=0,c=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                if(found)return false;
                else
                {
                    found = true;
                    if(i==0 || nums[i-1]<=nums[i+1]);
                    else if(i==nums.size()-2 || nums[i]<=nums[i+2]);
                    else return false;
                }
            }
        }
        return true;
    }
};
