/**
 *Q.Find the largest palindrome made from the product of two n-digit numbers. Since the result could be very large, you should return the largest palindrome mod 1337.
 * 
 * Faster to check if the palindromes have suitable factors, then to multiply 2 numbers and checking if it is a palindrome.
 */
 
class Solution {
public:
    
    long create(long n)
    {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        return stol(to_string(n) + s);
    }
    
    int largestPalindrome(int n) {
        if(n==1)return 9;
        long long t = pow(10,n)-1;
        long long  l = pow(10,n-1);
        for(long i=t;i>=l;i--)
        {
            long temp = create(i);
            for(long j=t;j*j>temp;j--)
            {
                if(temp%j==0 && temp/j<=t)return temp%1337;
            }
        }        
    }
};
