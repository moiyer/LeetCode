/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
两次动态规划，叹为观止
*/

class Solution {
 public:
     int maxProfit(vector<int> &prices) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         if (prices.size() == 0)
             return 0;
             
         vector<int> f1(prices.size());
         vector<int> f2(prices.size());
         
         //如果只进行一次交易，从左往右最大盈利
         int minV = prices[0];
         f1[0] = 0;
         for(int i = 1; i < prices.size(); i++)
         {
             minV = min(minV, prices[i]);
             f1[i] = max(f1[i-1], prices[i] - minV);
         }
         
         //如果只进行一次交易，从右往左最大盈利
         int maxV = prices[prices.size()-1];
         f2[f2.size()-1] = 0;
         for(int i = prices.size() - 2; i >= 0; i--)
         {
             maxV = max(prices[i], maxV);
             f2[i] = max(f2[i+1], maxV - prices[i]);
         }
         
         //两次动态规划结合
         int sum = 0;
         for(int i = 0; i < prices.size(); i++)
             sum = max(sum, f1[i] + f2[i]);
             
         return sum;
     }
 };
