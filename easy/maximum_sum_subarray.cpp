/**
  *Q. Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
  *
  */
  
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], ans = nums[0];
        int i=0,j=1;
        while(j<nums.size())
        {
            cout<<i<<j<<endl;
            cout<<sum<<endl;
            if(sum<0)
            {
                    i=j;
                    sum = nums[i];
            }
            else sum+= nums[j];
            if(sum>ans)
            {
                ans = sum;
            }
            j++;
        }
        return ans;
    }
};
  
