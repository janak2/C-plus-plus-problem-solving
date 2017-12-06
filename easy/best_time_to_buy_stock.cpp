/**
  *Q. Say you have an array for which the ith element is the price of a given stock on day i.
      If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
      design an algorithm to find the maximum profit.
  */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        int min_seen = prices[0];
        int ans = 0;
        for(int i: prices)
        {
            ans = max(ans,i-min_seen);
            min_seen = min(i,min_seen);
        }
        return ans;
    }
};
