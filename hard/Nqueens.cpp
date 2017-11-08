/**
 *Q. Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Could have passed the vector<vector<string>> as argument and pushed the solutions on it.
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
    
    vector<vector<int>> solve(vector<int>& x, int i, int n)
    {
        vector<vector<int>> ans;
        if(i==n)
        {
            ans.push_back(x);
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                x[i]=j;
                if(check(x,i))
                {
                    vector<vector<int>> temp = solve(x,i+1,n);
                    for(vector<int> t:temp) ans.push_back(t);
                }
            }
        }
        return ans;
    }
    
    vector<string> board(vector<int> x,int n)
    {
        vector<string> ans;
        for(int i: x)
        {
            string s="";
            for(int j=0;j<i;j++)s+='.';
            s+='Q';
            for(int j=i+1;j<n;j++)s+='.';
            ans.push_back(s);
        }
        return ans;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int> x(n,-1);
        vector<vector<int>> t= solve(x,0,n);
        vector<vector<string>> ans;
        for(vector<int> v: t)
        {
            ans.push_back(board(v,n));
        }
        return ans;
    }
};
