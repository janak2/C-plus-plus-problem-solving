/**
  *Q.You are climbing a stair case. It takes n steps to reach to the top. Each time you can either climb 1 or 2 steps. 
  *   In how many distinct ways can you climb to the top?
  * 
  * Iterative solution also possible like Fibonnaci numbers.
  */

class Solution {
public:
    
    int recurse(int n, vector<int>& v)
    {
        if(n==1) return 1;
        else if(n==2) return 2;
        else if(v[n-1]!=0)return v[n-1];
        else
        {
            v[n-1] = recurse(n-1,v)+recurse(n-2,v);
            return v[n-1];
        }
    }
    
    int climbStairs(int n) {
        vector<int> v(n,0);
        return recurse(n,v);
    }
};
