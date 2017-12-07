/**
  *Q. The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
   *
   */
 class Solution {
public:
    string convert(string s, int numRows) {
        int i =0;
        if(numRows==1)return s;
        vector<string> v(numRows,"");
        while(i<s.length())
        {
            int t = i%(2*numRows-2);
            if(t<numRows) v[t] += s[i];
            else v[2*numRows-2-t] += s[i];
            i++;
        }
        string ans = "";
        for(string i: v) ans += i;
        return ans;
    }
};
