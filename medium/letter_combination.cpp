/**
Q. Given a digit string, return all possible letter combinations that the number could represent.

You used a bottom up recursion but top down also possible.
combine(digits,0,m,string_to_be_added);

*/

class Solution {
public:
    
    vector<string> combine(string digits, int i, map<char,string> m)
    {
        vector<string> ans;
        if(i==digits.length()-1)
        {
            for(char c: m[digits[i]]) ans.push_back(string(1,c));
        }
        else
        {
        vector<string> s = combine(digits,i+1,m);
        for(char c: m[digits[i]])
        {
            for(string t: s)
            {
                ans.push_back(c+t);
            }
        }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        if(digits.length()==0)return vector<string>(0);
        return combine(digits,0,m);
    }
};
