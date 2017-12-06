/**
  *Q. Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
  *
  */

class Solution {
public:
    
    bool is(string s,int i,int j,vector<vector<int>>& v){
        if(v[i][j]!=-1)return v[i][j];
        else if(j-i==0)return true;
        else if(j-i==1)return s[i]==s[j];
        v[i][j] = s[i]==s[j] && is(s,i+1,j-1,v);
        return v[i][j];
    }
    
    string longestPalindrome(string s) {
        vector<vector<int>> v(s.length(),vector<int>(s.length(),-1));
        int start =0,size=0;
        for(int i=0;i<s.length();i++)
        {
            int j=i,k=i;
            while(k<s.length()-1 && j>0 && s[j-1]==s[k+1]){k++;j--;}
            if(k-j>size)
            {
                start = j;
                size = k-j;
            }
            j=i,k=i+1;
            if(s[j]!=s[k])continue;
            while(k<s.length()-1 && j>0 && s[j-1]==s[k+1]){k++;j--;}
            if(k-j>size)
            {
                start = j;
                size = k-j;
            }
        }
        return s.substr(start,size+1);
    }
};
