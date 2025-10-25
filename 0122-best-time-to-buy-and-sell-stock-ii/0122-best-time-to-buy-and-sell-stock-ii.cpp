// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int cost = INT_MAX;
//         int profit = 0;
//         int maxprofit = 0;
//         for(int i = 0; i<n; i++) {
//             if(prices[i]<cost) cost = prices[i];
//             else {
//                 profit = prices[i] - cost;
//                 maxprofit+=profit;
//                 cost = prices[i];
//             }
//         }
//         return maxprofit;

//     }
// };
class Solution {
public:
    int maxProfit(vector<int> & prices) {
        int n = prices.size();
        int maxprofit = 0;
        for(int i = 1 ;i<n ; i++) {
            if(prices[i]>prices[i-1]) {
                maxprofit+=(prices[i]-prices[i-1]);
            }
        }
        return maxprofit;
    }
};