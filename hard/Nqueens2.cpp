/**
 *Q.Now, instead outputting board configurations, return the total number of distinct solutions.
 *
 */

class Solution {
public:
    
    bool check(vector<int> x, int i)
    {
        for(int j=0;j<i;j++)
        {
            if(x[j]==x[i])return false;
            if(abs(x[j]-x[i])==abs(j-i))return false;
        }
        return true;
    }
    
    void solve(vector<int>& x, int i, int n, int& count)
    {
        if(i==n)
        {
            count++;
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                x[i]=j;
                if(check(x,i))
                {
                    solve(x,i+1,n,count);
                }
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<int> x(n,-1);
        int count = 0;
        solve(x,0,n,count);
        return count;
    }
};
