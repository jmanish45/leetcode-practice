class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mincost = INT_MAX;
        int maxprofit = INT_MIN;
        int profit = 0;
        for(int i = 0; i<n; i++) {
            if(prices[i]<mincost) {
                mincost = prices[i];
            }
            profit = prices[i] - mincost;
            if(profit>maxprofit) maxprofit = profit;

        }
        return maxprofit;
    }
};