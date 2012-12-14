/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

这道题就是找到最多的递增子序列个数，然后把利润加总。有点贪心算法的味道
*/

class Solution {
 public:
     int maxProfit(vector<int> &prices) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         if (prices.size() == 0)
             return 0;
             
         int start = prices[0];
         int profit = 0;
         for(int i = 1; i < prices.size(); i++)
         {
             if (prices[i] >= prices[i-1])
                 continue;
                 
             profit += prices[i-1] - start;
             
             start = prices[i];
         }
         
         profit += prices[prices.size()-1] - start;
         
         return profit;
     }
 };
