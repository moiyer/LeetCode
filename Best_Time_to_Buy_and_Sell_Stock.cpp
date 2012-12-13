/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

用类似动态规划的思想，到第i天买入，那么我能赚到的最大利润是多少呢？就是i + 1 ~ n天中最大的股价减去第i天的。找最大股价的问题可以在找第i+1~n天的最大利润时顺便记录，

这样就得出了一个线性方法。
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
            
        int maxPrice = prices[prices.size()-1];
        int ans = 0;
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            maxPrice = max(maxPrice, prices[i]);
            ans = max(ans, maxPrice - prices[i]);
        }
        
        return ans;
    }
};
