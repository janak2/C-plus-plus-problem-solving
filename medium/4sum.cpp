/**
Q.Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j!=i+1 && nums[j]==nums[j-1])continue;
                int k=j+1, l=nums.size()-1;
                while(k<l)
                {
                    if(k!=j+1 && nums[k]==nums[k-1])
                    {
                        k++;continue;
                    }
                    else if(l!=nums.size()-1 && nums[l]==nums[l+1])
                    {
                        l--;continue;
                    }
                    int temp = nums[i]+nums[j]+nums[k]+nums[l];
                    if(temp<target)k++;
                    else if(temp>target)l--;
                    else
                    {
                        ans.push_back(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                    }
                }
            }
        }
        return ans;
    }
};
